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
}

void PlayerModel::Initialize(Math::Vector2 InitialPos)
{
	playerPosition_ = InitialPos;
	SetStageData();

}

void PlayerModel::SetStageData()
{
	floorHeight_ = floorData_.GetFloorHeight();
	for (int i = 0; i < floorLines_; ++i) {
		floorPosition_Y_[i]=floorData_.GetFloorPosition_Y(i);
		for (int j = 0; j < floorEdgeNum_; ++j) {
			floorEdgePosition_X_[i][j]= floorData_.GetFloorEdgePosition_X(i, j);
		}
	}
}

void PlayerModel::Update()
{
	UpdatePlayerSprite();
	GroundCheck();
	PlayerMoveX();
	PlayerMoveY();
	DirectionChange();
}

void PlayerModel::UpdatePlayerSprite()
{
	draftSprite_.params.pos = playerPosition_;
}

void PlayerModel::PlayerMoveX()
{
	float direction;
	if (isMovingToRight_) {
		direction = 1.0f; // 右に移動
		if (playerPosition_.x >= RenderingPath->GetLogicalWidth()) {
			isMovingToRight_ = false; // 画面の右端に到達したら左に移動
		}
	}
	else {
		direction = -1.0f; // 左に移動
		if (playerPosition_.x <= 0) {
			isMovingToRight_ = true; // 画面の左端に到達したら右に移動
		}
	}

	playerPosition_.x += direction * playerSpeed_ * Time.deltaTime;
}

void PlayerModel::GroundCheck()
{
	float playerHeight = draftSprite_.params.siz.y;
	float playerWidth = draftSprite_.params.siz.x;
	isOnGround_X_ = false;
	isOnGround_Y_ = false;

	for (int i = 0; i < floorLines_; i++) {
		for (int j = 0; j < floorEdgeNum_; j += 2) {
			// X方向の床区間内か？
			if (floorEdgePosition_X_[i][j] - playerWidth <= playerPosition_.x &&
				playerPosition_.x <= floorEdgePosition_X_[i][j + 1]) {

				// Y方向の床高さ内か？
				if (isGravityUpward_) {
					if (playerPosition_.y > floorPosition_Y_[i] &&
						playerPosition_.y <= floorPosition_Y_[i] + floorHeight_) {
						// 床の上端に位置を合わせる
						playerPosition_.y = floorPosition_Y_[i] + floorHeight_;
						isOnGround_X_ = true;
						isOnGround_Y_ = true;
						return; // どこかで床に乗っていれば即終了
					}
				}
				else {
					if (playerPosition_.y >= floorPosition_Y_[i] - playerHeight &&
						playerPosition_.y <= floorPosition_Y_[i]) {
						playerPosition_.y = floorPosition_Y_[i] - playerHeight;
						isOnGround_X_ = true;
						isOnGround_Y_ = true;
						return;
					}
				}
			}
		}
	}
	// どの床にも乗っていなければ両方false
	isOnGround_X_ = false;
	isOnGround_Y_ = false;
}

void PlayerModel::PlayerMoveY()
{   
	int playerHeight = draftSprite_.params.siz.y; // プレイヤーの高さを取得
	if (isOnGround_X_&&isOnGround_Y_) {
		fallingSpeed_ = 0.0f; // 床にいる場合は落下速度をリセット
	}
	else {
		if (isGravityUpward_)
		{
			playerPosition_.y -= fallingSpeed_ * Time.deltaTime; // 上に重力を受けている場合は上に移動
			fallingSpeed_ += gravity_ * Time.deltaTime; // 重力の影響を受けて落下速度を増加
			if (playerPosition_.y <= -playerHeight) {
				playerPosition_.y = RenderingPath->GetLogicalHeight(); //床の上下はループ 
			}
		}
		else
		{
			playerPosition_.y += fallingSpeed_ * Time.deltaTime; // 下に重力を受けている場合は下に移動
			fallingSpeed_ += gravity_ * Time.deltaTime; // 重力の影響を受けて落下速度を増加

			if (playerPosition_.y >= RenderingPath->GetLogicalHeight()) {
				playerPosition_.y = 0; //床の上下はループ 
			}
		}
	}
	
}

void PlayerModel::DirectionChange()
{
	if (InputSystem.Keyboard.wasPressedThisFrame.Space)
	{
		isGravityUpward_ = !isGravityUpward_; // 方向を反転
	}
}