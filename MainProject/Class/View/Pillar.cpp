//
// Pillar.cpp
//

#include "Pillar.h"

using namespace HE;

void Pillar::Load()
{
	RenderingPath->AddSprite(&pillarSprite_1_, 0);
	RenderingPath->AddSprite(&pillarSprite_2_, 0);
}

void Pillar::Initialize()
{
	pillarSprite_1_.params.pos = Math::Vector2(0.0f, 0.0f); // ���̈ʒu��ݒ�
	pillarSprite_1_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // ���̃T�C�Y��ݒ�
	pillarSprite_2_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 40.0f, 0.0f); // �E���̒��̈ʒu��ݒ�
	pillarSprite_2_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // �E���̒��̃T�C�Y��ݒ�
	pillarSprite_1_.params.color = Color(150, 75, 0, 255); // ���̐F�𒃐F�ɐݒ�
	pillarSprite_2_.params.color = Color(150, 75, 0, 255); // �E���̒��̐F�𒃐F�ɐݒ�
}

