//
// PlayerModel.cpp
//

#include "PlayerModel.h"

using namespace HE;

void PlayerModel::Load()
{
	draftSprite_ = HE::Sprite("");
	draftSprite_.params.siz = Math::Vector2(50, 50);
	RenderingPath->AddSprite(&draftSprite_,0);
	collision_sprite_ = HE::Sprite("");
	collision_sprite_.params.color =  HE::Color(255, 0, 0, 100); // 衝突範囲表示用のスプライト
	RenderingPath->AddSprite(&collision_sprite_, 10);
}

void PlayerModel::Initialize(Math::Vector2 InitialPos, float leftedge, float rightedge)
{
	playerPosition_ = InitialPos;
	gameWindowLeftEdge_ = leftedge; // ゲームウィンドウの左端の位置
	gameWindowRightEdge_ = rightedge; // ゲームウィンドウの右端の位置

}


void PlayerModel::Update()
{
	OnGroundCheck();
	PlayerMoveX();
	PlayerMoveY(); 
	GravityChange();
	UpdatePlayerSprite();
}

Math::Rectangle PlayerModel::GetCollision()
{
	Math::Rectangle collision;
	collision.x = (long)playerPosition_.x - collisionSizeCorrection_x_ / 2 + collisionPositionCorrection_x_;
	collision.y = (long)playerPosition_.y - collisionSizeCorrection_y_ / 2 + collisionPositionCorrection_y_;
	collision.width = (long)playerWidth_ + collisionSizeCorrection_x_;
	collision.height = (long)playerHeight_ + collisionSizeCorrection_y_;


	// 衝突範囲表示設定
	collision_sprite_.params.pos.x = (float)collision.x;
	collision_sprite_.params.pos.y = (float)collision.y;
	collision_sprite_.params.siz.x = (float)collision.width;
	collision_sprite_.params.siz.y = (float)collision.height;
	return collision;
}

void PlayerModel::OnCollisionGround(Math::Vector2 floorPos, float floorHeight,float floorWidth)
{
	if (isOnGround_) return; // すでに床に乗っている場合は何もしない
	isOnGround_ = true; // 床に乗っている状態にする
	if(isGravityUpward_) {
		playerPosition_.y = floorPos.y + floorHeight;	
	}
	else {
		playerPosition_.y = floorPos.y - playerHeight_;
	}
	floorRange_x_min_ = floorPos.x; // 床の範囲の最小値を設定
	floorRange_x_max_ = floorPos.x + floorWidth; // 床の範囲の最大値を設定
}

void PlayerModel::OnGroundCheck()
{
	if (!isOnGround_) return;
	if (playerPosition_.x+playerWidth_ < floorRange_x_min_ || floorRange_x_max_ < playerPosition_.x)
	{
		isOnGround_ = false; // 床から離れた場合は床に乗っていない状態にする
		return;
	}

}
void PlayerModel::UpdatePlayerSprite()
{
	draftSprite_.params.pos = playerPosition_;
}

void PlayerModel::PlayerMoveX()
{
	if(!isOnGround_)
		return; // 床に乗っていない場合は移動しない
	float direction;
	if (isMovingToRight_) {
		direction = 1.0f; // 右に移動
		if (playerPosition_.x >= gameWindowRightEdge_-playerWidth_) {
			isMovingToRight_ = false; // 画面の右端に到達したら左に移動
		}
	}
	else {
		direction = -1.0f; // 左に移動
		if (playerPosition_.x <= gameWindowLeftEdge_) {
			isMovingToRight_ = true; // 画面の左端に到達したら右に移動
		}
	}

	playerPosition_.x += direction * playerSpeed_ * Time.deltaTime;
}


void PlayerModel::PlayerMoveY()
{   
	int playerHeight = draftSprite_.params.siz.y; // プレイヤーの身長を取得
	if (isOnGround_) {
		fallingSpeed_ = 0.0f; // 床にいる場合は落下速度をリセット
	}
	else {
		if (isGravityUpward_)
		{
			playerPosition_.y -= fallingSpeed_ * Time.deltaTime; // 上に重力を受けている場合は上に移動
			fallingSpeed_ += gravity_ * Time.deltaTime; // 重力の影響を受けて落下速度を増加
			if (playerPosition_.y <= -playerHeight) {
				playerPosition_.y = RenderingPath->GetLogicalHeight()+roopInterval_; //床の上下はループ 
			}
		}
		else
		{
			playerPosition_.y += fallingSpeed_ * Time.deltaTime; // 下に重力を受けている場合は下に移動
			fallingSpeed_ += gravity_ * Time.deltaTime; // 重力の影響を受けて落下速度を増加

			if (playerPosition_.y >= RenderingPath->GetLogicalHeight()) {
				playerPosition_.y = 0-roopInterval_; //床の上下はループ 
			}
		}
	}
	
}

void PlayerModel::GravityChange()
{
	if(!isOnGround_)
		return; // 床に乗っていない場合は方向転換しない
	if (InputSystem.Keyboard.wasPressedThisFrame.Space)
	{
		isGravityUpward_ = !isGravityUpward_; // 方向を反転
		isOnGround_ = false; // 床から離れる
	}
}

