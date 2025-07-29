//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("player.png");

	RenderingPath->AddSprite(&playerSprite_, 120); // �X�v���C�g�������_�����O�p�X�ɒǉ�
	effectSprite_ = HE::Sprite("effect.png");
	RenderingPath->AddSprite(&effectSprite_, 130); // �G�t�F�N�g�X�v���C�g�������_�����O�p�X�ɒǉ�

}

void PlayerView::Initialize()
{
	playerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f, 1000.0f
	));
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	effectSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f, 1000.0f
	));
	effectSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	prevColorChangeTime =INT_MAX;
	isBlack = true; // �v���C���[�̃X�v���C�g�������Ȃ邩�ǂ����̏����l
	// �A�j���[�V�����̐ݒ�
	playerSprite_.anim = Sprite::Anim();
	playerSprite_.anim.repeatable = true;                       // ���[�v���邩���Ȃ���
	playerSprite_.anim.drawRectAnim.frameRate = 15;             // �A�j���[�V�����̑��x
	playerSprite_.anim.drawRectAnim.frameCount = 6;             // �摜�ɃA�j���[�V���������R�}���邩
	playerSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // ���ɕ���ł���R�}��

	effectSprite_.anim = Sprite::Anim();
	effectSprite_.anim.repeatable = true;                       // ���[�v���邩���Ȃ���
	effectSprite_.anim.drawRectAnim.frameRate = 15;             // �A�j���[�V�����̑��x
	effectSprite_.anim.drawRectAnim.frameCount = 30;             // �摜�ɃA�j���[�V���������R�}���邩
	effectSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // ���ɕ���ł���R�}��

	effectSprite_.SetHidden(true); // �G�t�F�N�g�X�v���C�g���\���ɂ���
}
void PlayerView::Update(Math::Vector2 playerPos,bool isMovingRight,bool isGravityUp,bool isInvincible, float invincibleRemainingTime)
{
	playerSprite_.params.pos.x = playerPos.x; // �v���C���[�̈ʒu���X�V
	effectSprite_.params.pos.x = playerPos.x; // �G�t�F�N�g�̈ʒu���X�V

	if (isGravityUp) {
        playerSprite_.params.scale.y = -1.0;
		effectSprite_.params.scale.y = -1.0; // �G�t�F�N�g�̃X�P�[�����X�V
		playerSprite_.params.pos.y = playerPos.y+playerHeight_;
		effectSprite_.params.pos.y = playerPos.y + playerHeight_; // �G�t�F�N�g�̈ʒu���X�V
	}
	else
	{
		playerSprite_.params.scale.y = 1.0;
		effectSprite_.params.scale.y = 1.0; // �G�t�F�N�g�̃X�P�[�����X�V
		playerSprite_.params.pos.y = playerPos.y ;
		effectSprite_.params.pos.y = playerPos.y; // �G�t�F�N�g�̈ʒu���X�V
	}

	if (isMovingRight) {
		playerSprite_.params.enableMirror();
	}
	else {
		playerSprite_.params.disableMirror();
	}



	if (isInvincible) {
		
		effectSprite_.SetHidden(false);
		if  (invincibleRemainingTime <= startBlinkTime_) {
			if (prevColorChangeTime - invincibleRemainingTime >=blinkinterval_ )
			{
				isBlack = !isBlack; // ���G��Ԃ̎c�莞�Ԃ�2�b�ȉ��̏ꍇ�A�����_�ł���
				prevColorChangeTime = invincibleRemainingTime; 
			}
		}
		else
		{
			isBlack = false; 
		}
	
	}
	else {
		isBlack = true; 
		prevColorChangeTime = INT_MAX; 
		effectSprite_.SetHidden(true); // ���G��ԂłȂ��ꍇ�A�G�t�F�N�g���\���ɂ���
	}

	if (isBlack) {
		playerSprite_.params.drawRect.y = 0;
	}
	else
	{
		playerSprite_.params.drawRect.y = 1000;
	}

}