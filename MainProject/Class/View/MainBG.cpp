//
// MainBG.cpp
//

#include "MainBG.h"

using namespace HE;

void MainBG::Load()
{
	backgroundSprite_ = HE::Sprite("MainBG.png"); // �w�i�̃X�v���C�g��ǂݍ���
	RenderingPath->AddSprite(&backgroundSprite_, -1000); // �w�i�������_�����O�p�X�ɒǉ�

}

void MainBG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());

}


