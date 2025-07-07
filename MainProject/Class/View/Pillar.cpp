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
	pillarSprite_1_.params.pos = Math::Vector2(0.0f, 0.0f); // 柱の位置を設定
	pillarSprite_1_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // 柱のサイズを設定
	pillarSprite_2_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 40.0f, 0.0f); // 右側の柱の位置を設定
	pillarSprite_2_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // 右側の柱のサイズを設定
	pillarSprite_1_.params.color = Color(150, 75, 0, 255); // 柱の色を茶色に設定
	pillarSprite_2_.params.color = Color(150, 75, 0, 255); // 右側の柱の色を茶色に設定
}

