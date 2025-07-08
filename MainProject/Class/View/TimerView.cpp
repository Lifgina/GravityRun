//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // �t�H���g�X�^�C����ǉ�
	RenderingPath->AddFont(&timerSprite_, 1200); // �t�H���g�������_�����O�p�X�ɒǉ�
}

void TimerView::Initialize()
{
	timerSprite_.params.color = HE::Color(0, 0, 0, 200); // �^�C�}�[�̐F��ݒ�
	timerSprite_.params.size = 128; // �^�C�}�[�̃t�H���g�T�C�Y��ݒ�
	timerSprite_.params.posX = 300; // �^�C�}�[�̕\���ʒuX
	timerSprite_.params.posY = 300; // �^�C�}�[�̕\���ʒuY


}

void TimerView::NotifiCateTime(float timer)
{
	timerSprite_.SetHidden(false); // �^�C�}�[�̒ʒm��\������
	//�u�c�聛�b�v�ƕ\��
	timerSprite_.SetText( L"�c��" + std::to_wstring(static_cast<int>(timer)) + L"�b�I�I");
}