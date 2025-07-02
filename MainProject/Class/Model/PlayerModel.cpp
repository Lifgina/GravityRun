//
// PlayerModel.cpp
//

#include "PlayerModel.h"

using namespace HE;

void PlayerModel::Load()
{
	collision_sprite_ = HE::Sprite("");
	collision_sprite_.params.color =  HE::Color(255, 0, 0, 100); // 衝突範囲表示用のスプライト
	RenderingPath->AddSprite(&collision_sprite_, 10);
}

void PlayerModel::Initialize(Math::Vector2 InitialPos, float leftedge, float rightedge, bool isMovingToRightFirst, bool isGravityUpwardFirst,float playerWidth,float playerHeight)
{
	playerPosition_ = InitialPos;
	gameWindowLeftEdge_ = leftedge; // ゲームウィンドウの左端の位置
	gameWindowRightEdge_ = rightedge; // ゲームウィンドウの右端の位置
	isMovingToRight_ = isMovingToRightFirst; // プレイヤーの初期移動方向
	isGravityUpward_ = isGravityUpwardFirst; // プレイヤーの初期重力方向

	playerWidth_ = playerWidth; // プレイヤーの幅
	playerHeight_ = playerHeight; // プレイヤーの高さ

	loopedVelocityY_ = 0.0f; // ループ待機時の落下速度
	loopWaitStartTime_ = 0.0f; // ループ待機開始時のタイマー
	isOnGround_ = true; // 初期状態では床に乗っている
	isLoopWaiting_ = false; // 初期状態ではループ待機していない
	fallingSpeed_ = 0.0f; // 初期状態では落下速度は0

}


void PlayerModel::Update(float timer)
{
	OnGroundCheck();
	PlayerMoveX(timer);
	PlayerMoveY(timer); 
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
	fallingSpeed_ = 0.0f; // 落下速度をリセット
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


void PlayerModel::PlayerMoveX(float timer)
{
	if(!isOnGround_)
		return; // 床に乗っていない場合は移動しない
	float direction;
	float playerSpeed;

	if (timer < speedChangeTime_) {
		playerSpeed = initialPlayerSpeed_; // 初期速度
	}
	else {
		playerSpeed = afterPlayerSpeed_; // 速度変化後の速度
	}
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

	playerPosition_.x += direction * playerSpeed* Time.deltaTime;
}


void PlayerModel::PlayerMoveY(float timer)
{

	// ループ待機中
	if (isLoopWaiting_) {
		if ((timer - loopWaitStartTime_) >= loopInterval_) {
			// 逆側にワープ
			if (isGravityUpward_) {
				playerPosition_.y = RenderingPath->GetLogicalHeight();
				fallingSpeed_ = loopedVelocityY_;
			}
			else {
				playerPosition_.y = -playerHeight_;
				fallingSpeed_ = loopedVelocityY_;
			}
			isLoopWaiting_ = false;
		}
		return; // 待機中は移動しない
	}

	if (isOnGround_) return;

	if (isGravityUpward_) {
		playerPosition_.y -= fallingSpeed_ * Time.deltaTime;
		fallingSpeed_ += gravity_ * Time.deltaTime;
		if (playerPosition_.y <= -playerHeight_) {
			// ループ待機開始
			isLoopWaiting_ = true;
			loopWaitStartTime_ = timer;
			loopedVelocityY_ = fallingSpeed_;
		}
	}
	else {
		playerPosition_.y += fallingSpeed_ * Time.deltaTime;
		fallingSpeed_ += gravity_ * Time.deltaTime;
		if (playerPosition_.y >= RenderingPath->GetLogicalHeight()) {
			// ループ待機開始
			isLoopWaiting_ = true;
			loopWaitStartTime_ = timer;
			loopedVelocityY_ = fallingSpeed_;
		}
	}
}


void PlayerModel::GravityChange()
{
	if(!isOnGround_)
		return; // 床に乗っていない場合は方向転換しない
     isGravityUpward_ = !isGravityUpward_; // 方向を反転
	 isOnGround_ = false; // 床から離れる
	
}

