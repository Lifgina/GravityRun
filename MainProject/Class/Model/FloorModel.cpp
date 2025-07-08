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
		floorHPDebug_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // �t�H���g�X�^�C����ǉ�
		floorHPDebug_.params.size = 24; // �t�H���g�T�C�Y��ݒ�
		floorHPDebug_.params.color = HE::Color(255, 0, 0, 255); // �t�H���g�̐F��ݒ�
		floorHPDebug_.params.posX = floorPosition_.x ; // ���̒����ɔz�u
		floorHPDebug_.params.posY = floorPosition_.y ; // ���̒����ɔz�u
		RenderingPath->AddFont(&floorHPDebug_, 1000); // �t�H���g�������_�����O�p�X�ɒǉ�
		floorHPDebug_.SetText(std::to_wstring(touchCountToBreak_));
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
	floorHPDebug_.SetText(std::to_wstring(touchCountToBreak_ - touchCount_)); // �c��̃^�b�`����\��
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