//
// MoveEnemyView.cpp
//

#include "MoveEnemyView.h"

using namespace HE;

void MoveEnemyView::Load()
{
	moveEnemySprite_ = HE::Sprite("syuriken.png");
	RenderingPath->AddSprite(&moveEnemySprite_, 100); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void MoveEnemyView::Initialize(Math::Vector2 initialPos,float appearTime)
{
	apeearTime_ = appearTime; // �G���\�������܂ł̎��Ԃ�ݒ�
	moveEnemySprite_.params.pos = initialPos; // �����ʒu��ݒ�
	moveEnemySprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_); // �T�C�Y��ݒ�
	moveEnemySprite_.SetHidden(true); // ������Ԃł͔�\���ɂ���

	moveEnemySprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); 
	// �A�j���[�V�����̐ݒ�
	moveEnemySprite_.anim = Sprite::Anim();
	moveEnemySprite_.anim.repeatable = true;                       // ���[�v���邩���Ȃ���
	moveEnemySprite_.anim.drawRectAnim.frameRate = 0;             // �A�j���[�V�����̑��x
	moveEnemySprite_.anim.drawRectAnim.frameCount = 5;             // �摜�ɃA�j���[�V���������R�}���邩
	moveEnemySprite_.anim.drawRectAnim.horizontalFrameCount = 5;   // ���ɕ���ł���R�}��
	
}

void MoveEnemyView::Update(Math::Vector2 enemyPos,float time)
{
	if (time < apeearTime_-apeearBafa_) {
		moveEnemySprite_.SetHidden(true); // �w�莞�Ԃ��o�߂���܂Ŕ�\��
	}
	else{
		moveEnemySprite_.SetHidden(false); // �w�莞�Ԃ��o�߂�����\��
	}

	if (apeearTime_ <= time) {
		moveEnemySprite_.anim.drawRectAnim.frameRate = 20;             // �A�j���[�V�����̑��x
		moveEnemySprite_.params.pos = enemyPos; // �G�̈ʒu���X�V
	}

	
	
}