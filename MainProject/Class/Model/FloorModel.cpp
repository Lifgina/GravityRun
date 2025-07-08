//
// FloorModel.cpp
//

#include "FloorModel.h"

using namespace HE;

void FloorModel::Initialize(Math::Vector2 floorPosition, float floorWidth, float floorHeight,bool isBreakable,float breakTime)
{
	floorPosition_ = floorPosition;
	floorWidth_ = floorWidth;
	floorHeight_ = floorHeight;
	isBreakable_ = isBreakable; 
	breakTime_ = breakTime; // ��������܂ł̎��Ԃ�ݒ�

	isBroken_ = false; // ������Ԃł͉��Ă��Ȃ�

	draftSprite_ = HE::Sprite("");
	draftSprite_.params.pos = floorPosition_;
	draftSprite_.params.siz = Math::Vector2(floorWidth_, floorHeight_);

	if (isBreakable_) {
	    //���鏰�͉��F
		draftSprite_.params.color = HE::Color(255, 255, 0, 255); // ���F�̃X�v���C�g
	}

	RenderingPath->AddSprite(&draftSprite_, 0);


}

Math::Rectangle FloorModel::GetCollision()
{
	if (isBroken_) return Math::Rectangle(); // �������Ă���ꍇ�͏Փ˔����Ԃ��Ȃ�

	Math::Rectangle collision;
	collision.x = (long)floorPosition_.x ;
	collision.y = (long)floorPosition_.y ;
	collision.width = (long)floorWidth_ ;
	collision.height = (long)floorHeight_;
	return collision;
}

void FloorModel::Update(float timer)
{
	if (!isBreakable_) return; // ���Ȃ����͍X�V���Ȃ� 
	if (isBroken_) return; // ���ɉ��Ă��鏰�͍X�V���Ȃ�
	if (timer >= breakTime_) { // �w�莞�Ԃ��o�߂����珰����
		BreakFloor();
	}
}

void FloorModel::BreakFloor()
{
	if (!isBroken_ ) {
		isBroken_ = true; // ������ꂽ��Ԃɂ���
		draftSprite_.SetHidden(true); // �X�v���C�g���\���ɂ���
	}
	else {
		return; 
	}
}