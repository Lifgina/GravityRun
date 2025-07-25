//
// TutorialView.cpp
//

#include "TutorialView.h"

using namespace HE;

void TutorialView::Load()
{
	tutorialSprite_ = HE::Sprite("tutorial.png");
	RenderingPath->AddSprite(&tutorialSprite_, 1000);
}

void TutorialView::Initialize()
{
	tutorialSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // スプライトのサイズを設定
	tutorialSprite_.SetHidden(true); // 初期状態では非表示
}

void TutorialView::Update(bool isActive)
{
	tutorialSprite_.SetHidden(!isActive);
}