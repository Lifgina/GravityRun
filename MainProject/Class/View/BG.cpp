//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{

	RenderingPath->AddSprite(&backgroundSprite_, -1000); // �w�i�������_�����O�p�X�ɒǉ�

}

void BG::Initialize()
{
	backgroundSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	backgroundSprite_.params.color = HE::Color(200, 200, 200, 255); // ���D�F�̃X�v���C�g
}


