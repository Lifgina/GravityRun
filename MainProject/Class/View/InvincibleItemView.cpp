//
// InvincibleItemView.cpp
//

#include "InvincibleItemView.h"

using namespace HE;

void InvincibleItemView::Load()
{
	invincibleItemSprite_ = HE::Sprite("makimono.png");
	RenderingPath->AddSprite(&invincibleItemSprite_, 40); // ���G�A�C�e���̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void InvincibleItemView::Initialize()
{
	invincibleItemSprite_.params.siz = HE::Math::Vector2(155.0f, 155.0f); // ���G�A�C�e���̃T�C�Y��ݒ�


}

void InvincibleItemView::Update(HE::Math::Vector2 itemPos,bool isActive)
{
	invincibleItemSprite_.SetHidden(!isActive); 
	invincibleItemSprite_.params.pos = itemPos; // ���G�A�C�e���̈ʒu��ݒ�
}

