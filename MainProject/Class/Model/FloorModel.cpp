//
// FloorModel.cpp
//

#include "FloorModel.h"

using namespace HE;

void FloorModel::Initialize(Math::Vector2 floorPosition, float floorWidth, float floorHeight,bool isBreakable)
{
	floorPosition_ = floorPosition;
	floorWidth_ = floorWidth;
	floorHeight_ = floorHeight;
	isBreakable_ = isBreakable; 

	isBroken_ = false; // ������Ԃł͉��Ă��Ȃ�
	touchCount_ = 0; // �^�b�`����������
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

void FloorModel::BreakFloor()
{
	touchCount_++;
	if (touchCount_ < touchCountToBreak_) {
		return; // ����܂ł̃^�b�`���ɒB���Ă��Ȃ��ꍇ�͉������Ȃ�
	}
	if (isBreakable_ ) {
		isBroken_ = true; // ������ꂽ��Ԃɂ���
		draftSprite_.SetHidden(true); // �X�v���C�g���\���ɂ���
	}
	else {
		return; // ���łɉ��Ă���ꍇ�͉������Ȃ�
	}
}