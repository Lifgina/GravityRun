//
// Pillar.cpp
//

#include "Pillar.h"

using namespace HE;

void Pillar::Load()
{
	pillarSprite_1_ = HE::Sprite("wall.png"); // 左側の柱のスプライトを読み込む
	pillarSprite_2_ = HE::Sprite("wall.png"); // 右側の柱のスプライトを読み込む

	RenderingPath->AddSprite(&pillarSprite_1_, 0);
	RenderingPath->AddSprite(&pillarSprite_2_, 0);
}

void Pillar::Initialize()
{
	pillarSprite_1_.params.pos = Math::Vector2(0.0f, 0.0f); // 柱の位置を設定
	pillarSprite_1_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // 柱のサイズを設定
	pillarSprite_2_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 40.0f, 0.0f); // 右側の柱の位置を設定
	pillarSprite_2_.params.siz = Math::Vector2(40.0f, RenderingPath->GetLogicalHeight()); // 右側の柱のサイズを設定
}

