//
// FusumaView.cpp
//

#include "FusumaView.h"

using namespace HE;

void FusumaView::Load(int husumaPattern, int husumaColor)
{
	switch (husumaColor)
	{
	case 0:
		fusumaBackgroundSprite_ = HE::Sprite("fusuma_red.png");
		break;
	case 1:
		fusumaBackgroundSprite_ = HE::Sprite("fusuma_blue.png");
		break;
	}
	switch (husumaPattern)
	{
	case 0:
		fusumaSprite_ = HE::Sprite("husuma_kawa.png");
		break;
	case 1:
		fusumaSprite_ = HE::Sprite("husuma_koi.png");
		break;
	case 2:
		fusumaSprite_ = HE::Sprite("husuma_matu.png");
		break;
	}
	fusumaSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 256.0f, 256.0f
	));
	fusumaSprite_.params.siz = Math::Vector2(fusumaWidth_, fusumaHeight_); // �ӂ��܂̃T�C�Y��ݒ�
	fusumaBackgroundSprite_.params.siz = Math::Vector2((fusumaWidth_/2)-2.5, (fusumaHeight_/2)-5); // �ӂ��܂̔w�i�̃T�C�Y��ݒ�
	RenderingPath->AddSprite(&fusumaBackgroundSprite_, -990); // �ӂ��܂̔w�i�X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&fusumaSprite_, 30); // �ӂ��܂̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void FusumaView::Initialize(Math::Vector2 fusumaPos)
{
	fusumaSprite_.params.pos = fusumaPos; // �ӂ��܂̈ʒu��ݒ�
	fusumaBackgroundSprite_.params.pos = fusumaPos+Math::Vector2(65.0f,132.5f); // �ӂ��܂̔w�i�̈ʒu��ݒ�
	// �A�j���[�V�����̐ݒ�
	fusumaSprite_.anim = Sprite::Anim();
	fusumaSprite_.anim.repeatable = false; // ���[�v���邩���Ȃ���
	fusumaSprite_.anim.drawRectAnim.frameRate = 0;
	fusumaSprite_.anim.drawRectAnim.frameCount = 6;             // �摜�ɃA�j���[�V���������R�}���邩
	fusumaSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // ���ɕ���ł���R�}��
}

void FusumaView::FusumaMove(bool isOpened)
{
	fusumaSprite_.anim.drawRectAnim.frameRate = 24;
	
	if(isOpened){
		fusumaSprite_.params.drawRect.x = 0.0f;
		fusumaSprite_.params.drawRect.y = 0.0f;
		fusumaSprite_.anim.drawRectAnim._currentFrame = 0; // �A�j���[�V�����̃t���[�������Z�b�g
		fusumaSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // �A�j���[�V�����̌o�ߎ��Ԃ����Z�b�g
	}
	else{
		fusumaSprite_.params.drawRect.x = 0.0f;
		fusumaSprite_.params.drawRect.y = 256.0f;
		fusumaSprite_.anim.drawRectAnim._currentFrame = 0; // �A�j���[�V�����̃t���[�������Z�b�g
		fusumaSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // �A�j���[�V�����̌o�ߎ��Ԃ����Z�b�g
		
	}
	

}

