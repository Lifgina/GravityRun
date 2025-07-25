//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_10 = HE::Sprite("timer_10.png");
	timerSprite_30 = HE::Sprite("timer_30.png");
	RenderingPath->AddSprite(&timerSprite_10, 1000);
	RenderingPath->AddSprite(&timerSprite_30, 1000);
}

void TimerView::Initialize()
{
	timerSprite_10.params.siz = HE::Math::Vector2(512.0f, 512.0f); // �X�v���C�g�̃T�C�Y��ݒ�
	timerSprite_30.params.siz = HE::Math::Vector2(512.0f, 512.0f); // �X�v���C�g�̃T�C�Y��ݒ�
	timerSprite_10.params.pos = HE::Math::Vector2(640.0f-256.0f,360.0f-256.0f); // �X�v���C�g�̈ʒu��ݒ�
	timerSprite_30.params.pos = HE::Math::Vector2(640.0f - 256.0f, 360.0f - 256.0f); // �X�v���C�g�̈ʒu��ݒ�
	timerSprite_10.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); 
	timerSprite_30.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); // �X�v���C�g�̕`���`��ݒ�

	// �A�j���[�V�����̐ݒ�
	timerSprite_10.anim = Sprite::Anim();
	timerSprite_10.anim.repeatable = false;                       // ���[�v���邩���Ȃ���
	timerSprite_10.anim.drawRectAnim.frameCount = 80;             // �摜�ɃA�j���[�V���������R�}���邩
	timerSprite_10.anim.drawRectAnim.horizontalFrameCount = 10;   // ���ɕ���ł���R�}��

	timerSprite_30.anim = Sprite::Anim();
	timerSprite_30.anim.repeatable = false;                       // ���[�v���邩���Ȃ���
	timerSprite_30.anim.drawRectAnim.frameCount = 80;             // �摜�ɃA�j���[�V���������R�}���邩
	timerSprite_30.anim.drawRectAnim.horizontalFrameCount = 10;   // ���ɕ���ł���R�}��

	HideNotification(); // ������Ԃł̓^�C�}�[�̒ʒm���\���ɂ���


}

void TimerView::NotifiCateTime(float timer)
{
	if (timer == 30) {
		timerSprite_30.SetHidden(false); // 30�b�̃^�C�}�[��\��
		timerSprite_30.anim.drawRectAnim.frameRate = 15; // �A�j���[�V�����̑��x��ݒ�
	}
	else if (timer == 10) {
		timerSprite_10.SetHidden(false); // 10�b�̃^�C�}�[��\��
		timerSprite_10.anim.drawRectAnim.frameRate = 15; // �A�j���[�V�����̑��x��ݒ�

	}
}

void TimerView::HideNotification()
{
	timerSprite_10.SetHidden(true); // 10�b�̃^�C�}�[���\��
	timerSprite_30.SetHidden(true); // 30�b�̃^�C�}�[���\��
	timerSprite_10.anim.drawRectAnim.frameRate = 0; // �A�j���[�V�����̑��x�����Z�b�g
	timerSprite_30.anim.drawRectAnim.frameRate = 0; // �A�j���[�V�����̑��x�����Z�b�g
}