//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_ = HE::Sprite(""); // �^�C�}�[�\���p�̃X�v���C�g��ǂݍ���
	RenderingPath->AddSprite(&timerSprite_, 100); // �X�v���C�g�������_�����O�p�X�ɒǉ�

	timerBackgroundSprite_ = HE::Sprite(""); // �^�C�}�[�w�i�p�̃X�v���C�g��ǂݍ���
	RenderingPath->AddSprite(&timerBackgroundSprite_, 99); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void TimerView::Initialize(float timeLimit)
{
	timeLimit_ = timeLimit; // �^�C�����~�b�g��ݒ�
	timerSprite_.params.color = HE::Color(0, 0, 255, 255); // �^�C�}�[�̐F��ݒ�
	timerSprite_.params.siz = Math::Vector2(60, 720); // �X�v���C�g�̃T�C�Y��ݒ�
	timerSprite_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 60, 0); // �X�v���C�g�̈ʒu��ݒ�

	timerBackgroundSprite_.params.color = HE::Color(255, 255, 255, 255); // �^�C�}�[�w�i�̐F��ݒ�
	timerBackgroundSprite_.params.siz = Math::Vector2(60, 720); // �^�C�}�[�w�i�̃T�C�Y��ݒ�
	timerBackgroundSprite_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 60, 0); // �^�C�}�[�w�i�̈ʒu��ݒ�
}

void TimerView::Update(float timer)
{
	timerSprite_.params.siz.y = 720.0f * (1 - timer/ timeLimit_); // �^�C�}�[�̍������X�V
	timerSprite_.params.pos.y = 720.0f * (timer / timeLimit_); // �^�C�}�[�̈ʒu���X�V
}