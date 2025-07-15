//
// FloorView.cpp
//

#include "FloorView.h"

using namespace HE;

void FloorView::Load(bool isBreakable)
{
	//���邩�ǂ����œǂݍ��މ摜��ς���
	if (isBreakable) {
		floorSprite_ = HE::Sprite("floor_break.png"); // ���鏰�̃X�v���C�g
	}
	else {
		floorSprite_ = HE::Sprite("floor.png"); // ���Ȃ����̃X�v���C�g
	}
	RenderingPath->AddSprite(&floorSprite_, 0); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void FloorView::Initialize(Math::Vector2 floorPos, float floorHeight, float floorWidth)
{
	floorSprite_.params.pos = floorPos; // ���̈ʒu��ݒ�
	floorSprite_.params.siz = Math::Vector2(floorWidth, floorHeight); // ���̃T�C�Y��ݒ�
	floorSprite_.SetHidden(false); // ����\������
}
void FloorView::FloorBreak()
{
	floorSprite_.SetHidden(true); // �����\���ɂ���
}
