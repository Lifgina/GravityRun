//
// Pillar.cpp
//

#include "Pillar.h"

using namespace HE;

void Pillar::Load()
{
	pillarSprite_1_ = HE::Sprite("wall.png"); // �����̒��̃X�v���C�g��ǂݍ���
	pillarSprite_2_ = HE::Sprite("wall.png"); // �E���̒��̃X�v���C�g��ǂݍ���

	RenderingPath->AddSprite(&pillarSprite_1_, 0);
	RenderingPath->AddSprite(&pillarSprite_2_, 0);
}

void Pillar::Initialize()
{
	pillarSprite_1_.params.pos = Math::Vector2(0.0f, 0.0f); // ���̈ʒu��ݒ�
	pillarSprite_1_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // ���̃T�C�Y��ݒ�
	pillarSprite_2_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 40.0f, 0.0f); // �E���̒��̈ʒu��ݒ�
	pillarSprite_2_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // �E���̒��̃T�C�Y��ݒ�
}

