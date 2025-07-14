//
// MainBG.cpp
//

#include "MainBG.h"

using namespace HE;

void MainBG::Load()
{

	RenderingPath->AddSprite(&backgroundSprite_, -1000); // 背景をレンダリングパスに追加

}

void MainBG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	backgroundSprite_.params.color = HE::Color(200, 200, 200, 255); // 薄灰色のスプライト
}


