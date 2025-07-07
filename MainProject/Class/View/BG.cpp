//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{

	RenderingPath->AddSprite(&backgroundSprite_, -1000); // 背景をレンダリングパスに追加

}

void BG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	backgroundSprite_.params.color = HE::Color(200, 200, 200, 255); // 薄灰色のスプライト
}


