//
// ClassTemplete.cpp
//

#include "MarkerView.h"

using namespace HE;

void MarkerView::Load()
{
	markerSprite_ = Sprite("cursor.png");

	RenderingPath->AddSprite(&markerSprite_, 2000); // �����_�����O�p�X�ɒǉ�
	markerSprite_.params.siz = Math::Vector2(135.0f, 46.0f); // �}�[�J�[�̃T�C�Y��ݒ�
	markerSprite_.params.pos = Math::Vector2(-1000.0f, 0.0f); // �����ʒu��ݒ�

}

void MarkerView::UpdateMarker(Math::Vector2 pos)
{
	markerSprite_.params.pos = pos; // �}�[�J�[�̈ʒu���X�V
	
}

void MarkerView::MarkerDelete()
{
	markerSprite_.params.pos = Math::Vector2(-1000.0f, 0.0f); // �}�[�J�[�̈ʒu��������
}
