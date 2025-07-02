//
// PlayerModel.cpp
//

#include "PlayerModel.h"

using namespace HE;

void PlayerModel::Load()
{
	collision_sprite_ = HE::Sprite("");
	collision_sprite_.params.color =  HE::Color(255, 0, 0, 100); // �Փ˔͈͕\���p�̃X�v���C�g
	RenderingPath->AddSprite(&collision_sprite_, 10);
}

void PlayerModel::Initialize(Math::Vector2 InitialPos, float leftedge, float rightedge, bool isMovingToRightFirst, bool isGravityUpwardFirst,float playerWidth,float playerHeight)
{
	playerPosition_ = InitialPos;
	gameWindowLeftEdge_ = leftedge; // �Q�[���E�B���h�E�̍��[�̈ʒu
	gameWindowRightEdge_ = rightedge; // �Q�[���E�B���h�E�̉E�[�̈ʒu
	isMovingToRight_ = isMovingToRightFirst; // �v���C���[�̏����ړ�����
	isGravityUpward_ = isGravityUpwardFirst; // �v���C���[�̏����d�͕���

	playerWidth_ = playerWidth; // �v���C���[�̕�
	playerHeight_ = playerHeight; // �v���C���[�̍���

	loopedVelocityY_ = 0.0f; // ���[�v�ҋ@���̗������x
	loopWaitStartTime_ = 0.0f; // ���[�v�ҋ@�J�n���̃^�C�}�[
	isOnGround_ = true; // ������Ԃł͏��ɏ���Ă���
	isLoopWaiting_ = false; // ������Ԃł̓��[�v�ҋ@���Ă��Ȃ�
	fallingSpeed_ = 0.0f; // ������Ԃł͗������x��0

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


	// �Փ˔͈͕\���ݒ�
	collision_sprite_.params.pos.x = (float)collision.x;
	collision_sprite_.params.pos.y = (float)collision.y;
	collision_sprite_.params.siz.x = (float)collision.width;
	collision_sprite_.params.siz.y = (float)collision.height;
	return collision;
}

void PlayerModel::OnCollisionGround(Math::Vector2 floorPos, float floorHeight,float floorWidth)
{
	if (isOnGround_) return; // ���łɏ��ɏ���Ă���ꍇ�͉������Ȃ�
	isOnGround_ = true; // ���ɏ���Ă����Ԃɂ���
	fallingSpeed_ = 0.0f; // �������x�����Z�b�g
	if(isGravityUpward_) {
		playerPosition_.y = floorPos.y + floorHeight;	
	}
	else {
		playerPosition_.y = floorPos.y - playerHeight_;
	}
	floorRange_x_min_ = floorPos.x; // ���͈̔͂̍ŏ��l��ݒ�
	floorRange_x_max_ = floorPos.x + floorWidth; // ���͈̔͂̍ő�l��ݒ�
}

void PlayerModel::OnGroundCheck()
{
	if (!isOnGround_) return;
	if (playerPosition_.x+playerWidth_ < floorRange_x_min_ || floorRange_x_max_ < playerPosition_.x)
	{
		isOnGround_ = false; // �����痣�ꂽ�ꍇ�͏��ɏ���Ă��Ȃ���Ԃɂ���
		return;
	}

}


void PlayerModel::PlayerMoveX(float timer)
{
	if(!isOnGround_)
		return; // ���ɏ���Ă��Ȃ��ꍇ�͈ړ����Ȃ�
	float direction;
	float playerSpeed;

	if (timer < speedChangeTime_) {
		playerSpeed = initialPlayerSpeed_; // �������x
	}
	else {
		playerSpeed = afterPlayerSpeed_; // ���x�ω���̑��x
	}
	if (isMovingToRight_) {
		direction = 1.0f; // �E�Ɉړ�
		if (playerPosition_.x >= gameWindowRightEdge_-playerWidth_) {
			isMovingToRight_ = false; // ��ʂ̉E�[�ɓ��B�����獶�Ɉړ�
		}
	}
	else {
		direction = -1.0f; // ���Ɉړ�
		if (playerPosition_.x <= gameWindowLeftEdge_) {
			isMovingToRight_ = true; // ��ʂ̍��[�ɓ��B������E�Ɉړ�
		}
	}

	playerPosition_.x += direction * playerSpeed* Time.deltaTime;
}


void PlayerModel::PlayerMoveY(float timer)
{

	// ���[�v�ҋ@��
	if (isLoopWaiting_) {
		if ((timer - loopWaitStartTime_) >= loopInterval_) {
			// �t���Ƀ��[�v
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
		return; // �ҋ@���͈ړ����Ȃ�
	}

	if (isOnGround_) return;

	if (isGravityUpward_) {
		playerPosition_.y -= fallingSpeed_ * Time.deltaTime;
		fallingSpeed_ += gravity_ * Time.deltaTime;
		if (playerPosition_.y <= -playerHeight_) {
			// ���[�v�ҋ@�J�n
			isLoopWaiting_ = true;
			loopWaitStartTime_ = timer;
			loopedVelocityY_ = fallingSpeed_;
		}
	}
	else {
		playerPosition_.y += fallingSpeed_ * Time.deltaTime;
		fallingSpeed_ += gravity_ * Time.deltaTime;
		if (playerPosition_.y >= RenderingPath->GetLogicalHeight()) {
			// ���[�v�ҋ@�J�n
			isLoopWaiting_ = true;
			loopWaitStartTime_ = timer;
			loopedVelocityY_ = fallingSpeed_;
		}
	}
}


void PlayerModel::GravityChange()
{
	if(!isOnGround_)
		return; // ���ɏ���Ă��Ȃ��ꍇ�͕����]�����Ȃ�
     isGravityUpward_ = !isGravityUpward_; // �����𔽓]
	 isOnGround_ = false; // �����痣���
	
}

