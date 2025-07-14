//
// TitleBG.cpp
//

#include "TitleBG.h"

using namespace HE;

void TitleBG::Load()
{
	backgroundSprite_ = HE::Sprite("Title.png");
	RenderingPath->AddSprite(&backgroundSprite_, -1000); // �w�i�������_�����O�p�X�ɒǉ�

}

void TitleBG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
}


