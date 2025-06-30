//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("");
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	playerSprite_.params.color = HE::Color(255, 255, 255, 255); // ���F�̃X�v���C�g
	RenderingPath->AddSprite(&playerSprite_, 0); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}


void PlayerView::Update(Math::Vector2 playerPos)
{
	playerSprite_.params.pos = playerPos; // �v���C���[�̈ʒu���X�V
}