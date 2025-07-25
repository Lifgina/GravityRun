//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("player.png");
	playerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f,1000.0f
	));
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	RenderingPath->AddSprite(&playerSprite_, 120); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void PlayerView::Initialize()
{
	// �A�j���[�V�����̐ݒ�
	playerSprite_.anim = Sprite::Anim();
	playerSprite_.anim.repeatable = true;                       // ���[�v���邩���Ȃ���
	playerSprite_.anim.drawRectAnim.frameRate = 15;             // �A�j���[�V�����̑��x
	playerSprite_.anim.drawRectAnim.frameCount = 6;             // �摜�ɃA�j���[�V���������R�}���邩
	playerSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // ���ɕ���ł���R�}��
}
void PlayerView::Update(Math::Vector2 playerPos,bool isMovingRight,bool isGravityUp,bool isInvincible)
{
	playerSprite_.params.pos.x = playerPos.x; // �v���C���[�̈ʒu���X�V
	if (isGravityUp) {
        playerSprite_.params.scale.y = -1.0;
		playerSprite_.params.pos.y = playerPos.y+playerHeight_;
	}
	else
	{
		playerSprite_.params.scale.y = 1.0;
		playerSprite_.params.pos.y = playerPos.y ;
	}

	if (isMovingRight) {
		playerSprite_.params.enableMirror();
	}
	else {
		playerSprite_.params.disableMirror();
	}

	if (isInvincible) {
		playerSprite_.params.color = HE::Color(255, 255, 255, 150); // ���G��Ԃ̎��͓����ɂ���
	}
	else {
		playerSprite_.params.color = HE::Color(255, 255, 255, 255); 
	}

}