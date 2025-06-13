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
		direction = 1.0f; // �E�Ɉړ�
		if (playerPosition_.x >= RenderingPath->GetLogicalWidth()) {
			isMovingToRight_ = false; // ��ʂ̉E�[�ɓ��B�����獶�Ɉړ�
		}
	}
	else {
		direction = -1.0f; // ���Ɉړ�
		if (playerPosition_.x <= 0) {
			isMovingToRight_ = true; // ��ʂ̍��[�ɓ��B������E�Ɉړ�
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
			// X�����̏���ԓ����H
			if (floorEdgePosition_X_[i][j] - playerWidth <= playerPosition_.x &&
				playerPosition_.x <= floorEdgePosition_X_[i][j + 1]) {

				// Y�����̏����������H
				if (isGravityUpward_) {
					if (playerPosition_.y > floorPosition_Y_[i] &&
						playerPosition_.y <= floorPosition_Y_[i] + floorHeight_) {
						// ���̏�[�Ɉʒu�����킹��
						playerPosition_.y = floorPosition_Y_[i] + floorHeight_;
						isOnGround_X_ = true;
						isOnGround_Y_ = true;
						return; // �ǂ����ŏ��ɏ���Ă���Α��I��
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
	// �ǂ̏��ɂ�����Ă��Ȃ���Η���false
	isOnGround_X_ = false;
	isOnGround_Y_ = false;
}

void PlayerModel::PlayerMoveY()
{   
	int playerHeight = draftSprite_.params.siz.y; // �v���C���[�̍������擾
	if (isOnGround_X_&&isOnGround_Y_) {
		fallingSpeed_ = 0.0f; // ���ɂ���ꍇ�͗������x�����Z�b�g
	}
	else {
		if (isGravityUpward_)
		{
			playerPosition_.y -= fallingSpeed_ * Time.deltaTime; // ��ɏd�͂��󂯂Ă���ꍇ�͏�Ɉړ�
			fallingSpeed_ += gravity_ * Time.deltaTime; // �d�͂̉e�����󂯂ė������x�𑝉�
			if (playerPosition_.y <= -playerHeight) {
				playerPosition_.y = RenderingPath->GetLogicalHeight(); //���̏㉺�̓��[�v 
			}
		}
		else
		{
			playerPosition_.y += fallingSpeed_ * Time.deltaTime; // ���ɏd�͂��󂯂Ă���ꍇ�͉��Ɉړ�
			fallingSpeed_ += gravity_ * Time.deltaTime; // �d�͂̉e�����󂯂ė������x�𑝉�

			if (playerPosition_.y >= RenderingPath->GetLogicalHeight()) {
				playerPosition_.y = 0; //���̏㉺�̓��[�v 
			}
		}
	}
	
}

void PlayerModel::DirectionChange()
{
	if (InputSystem.Keyboard.wasPressedThisFrame.Space)
	{
		isGravityUpward_ = !isGravityUpward_; // �����𔽓]
	}
}