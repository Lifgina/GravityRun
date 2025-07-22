//
// InvincibleItemView.cpp
//

#include "InvincibleItemView.h"

using namespace HE;

void InvincibleItemView::Load()
{
	invincibleItemSprite_ = HE::Sprite("");
	RenderingPath->AddSprite(&invincibleItemSprite_, 10); // ���G�A�C�e���̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void InvincibleItemView::Initialize()
{
	invincibleItemSprite_.params.siz = HE::Math::Vector2(100.0f, 155.0f); // ���G�A�C�e���̃T�C�Y��ݒ�
	invincibleItemSprite_.params.color = HE::Color(255, 255, 0, 100); // ���G�A�C�e���̐F��ݒ�

}

void InvincibleItemView::Update(HE::Math::Vector2 itemPos,bool isActive)
{
	invincibleItemSprite_.SetHidden(!isActive); 
	invincibleItemSprite_.params.pos = itemPos; // ���G�A�C�e���̈ʒu��ݒ�
}

