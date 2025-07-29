//
// CountdownView.cpp
//

#include "CountdownView.h"

using namespace HE;

void CountdownView::Load()
{
	countdownSprite_ = Sprite("CountDown.png");
	RenderingPath->AddSprite(&countdownSprite_, 2000); // �����_�����O�p�X�ɒǉ�
}

void CountdownView::Initialize()
{
	countdownSprite_.params.siz = Math::Vector2(250.0f, 100.0f); // �J�E���g�_�E���̃T�C�Y��ݒ�
	countdownSprite_.params.pos = Math::Vector2(640.0f-125.0f, 200.0f); // �J�E���g�_�E���̏����ʒu��ݒ�
	countdownSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 500.0f, 200.0f
	)); 
	// �A�j���[�V�����̐ݒ�
	countdownSprite_.anim = Sprite::Anim();
	countdownSprite_.anim.repeatable = false;                       // ���[�v���邩���Ȃ���
	countdownSprite_.anim.drawRectAnim.frameRate = 10;             // �A�j���[�V�����̑��x
	countdownSprite_.anim.drawRectAnim.horizontalFrameCount = 5;   // ���ɕ���ł���R�}��
}

void CountdownView::ShowCountDown()
{
	countdownSprite_.SetHidden(false); // �J�E���g�_�E����\��
	countdownSprite_.params.drawRect.x = 0.0f; 
	countdownSprite_.params.drawRect.y = 0.0f; 
	countdownSprite_.anim.drawRectAnim._currentFrame = 0; // �A�j���[�V�����̃t���[�������Z�b�g
	countdownSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // �A�j���[�V�����̌o�ߎ��Ԃ����Z�b�g
	countdownSprite_.anim.drawRectAnim.frameCount = 30;             // �摜�ɃA�j���[�V���������R�}���邩
}

void CountdownView::ShowStart()
{
	countdownSprite_.anim.drawRectAnim._currentFrame = 0; // �A�j���[�V�����̃t���[�������Z�b�g
	countdownSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // �A�j���[�V�����̌o�ߎ��Ԃ����Z�b�g
	countdownSprite_.params.drawRect.x = 0.0f; 
	countdownSprite_.params.drawRect.y = 1200.0f; 
	countdownSprite_.anim.drawRectAnim.frameCount = 10;             // �摜�ɃA�j���[�V���������R�}���邩
}