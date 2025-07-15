//
// MainBG.cpp
//

#include "MainBG.h"

using namespace HE;

void MainBG::Load()
{
	backgroundSprite_ = HE::Sprite("MainBG.png"); // ”wŒi‚ÌƒXƒvƒ‰ƒCƒg‚ð“Ç‚Ýž‚Þ
	RenderingPath->AddSprite(&backgroundSprite_, -1000); // ”wŒi‚ðƒŒƒ“ƒ_ƒŠƒ“ƒOƒpƒX‚É’Ç‰Á

}

void MainBG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());

}


