//
// SilentEnemyView.cpp
//

#include "SilentEnemyView.h"

using namespace HE;

void SilentEnemyView::Load()
{
	silentEnemySprite_ = HE::Sprite("makibisi.png"); // �܂��т��̃X�v���C�g��ǂݍ���
	RenderingPath->AddSprite(&silentEnemySprite_, 10); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void SilentEnemyView::Initialize(Math::Vector2 pos, float spriteDirection)
{
	silentEnemySprite_.params.siz = Math::Vector2(spriteWidth_, spriteHeight_); // �܂��т��̃T�C�Y��ݒ�
	silentEnemySprite_.params.pos = pos+Math::Vector2(-8,-2); // �܂��т��̈ʒu��ݒ�
	if (spriteDirection == -1) {
		silentEnemySprite_.params.scale.y = -1; // �܂��т��̌������������ɐݒ�
		silentEnemySprite_.params.pos.y += spriteHeight_; // �ʒu�𒲐�
	}

}
void SilentEnemyView::Update(bool isActive)
{
	silentEnemySprite_.SetHidden(!isActive); // �܂��т��̕\��/��\����؂�ւ���
}
