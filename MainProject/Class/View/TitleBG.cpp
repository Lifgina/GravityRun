//
// TitleBG.cpp
//

#include "TitleBG.h"

using namespace HE;

void TitleBG::Load()
{
	backgroundSprite_ = HE::Sprite("Title.png");
	ruleButtonSprite_ = HE::Sprite("rule.png");
	startButtonSprite_ = HE::Sprite("start.png");
	exitButtonSprite_ = HE::Sprite("exit.png");
	RenderingPath->AddSprite(&backgroundSprite_, -1000); // 背景をレンダリングパスに追加
	RenderingPath->AddSprite(&ruleButtonSprite_, 1000); // ルールボタンをレンダリングパスに追加
	RenderingPath->AddSprite(&startButtonSprite_, 1000); // スタートボタンをレンダリングパスに追加
	RenderingPath->AddSprite(&exitButtonSprite_, 1000); // エグジットボタンをレンダリングパスに追加

}

void TitleBG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	startButtonSprite_.params.pos = Math::Vector2(257.0f,438.5f);
	startButtonSprite_.params.siz = Math::Vector2(323.0f, 84.0f);
	ruleButtonSprite_.params.pos = Math::Vector2(285.5f, 531.5f);
	ruleButtonSprite_.params.siz = Math::Vector2(260.0f, 70.0f);
	exitButtonSprite_.params.pos = Math::Vector2(285.5f, 614.5f);
	exitButtonSprite_.params.siz = Math::Vector2(260.0f, 70.0f);

}


