//
// MoveEnemyView.cpp
//

#include "MoveEnemyView.h"

using namespace HE;

void MoveEnemyView::Load()
{
	moveEnemySprite_ = HE::Sprite("");
	moveEnemySprite_.params.color = HE::Color(0, 255, 0, 255); // �ΐF�̃X�v���C�g
	RenderingPath->AddSprite(&moveEnemySprite_, 0); // �X�v���C�g�������_�����O�p�X�ɒǉ�
}

void MoveEnemyView::Initialize(Math::Vector2 initialPos,float appearTime)
{
	apeearTime_ = appearTime; // �G���\�������܂ł̎��Ԃ�ݒ�
	moveEnemySprite_.params.pos = initialPos; // �����ʒu��ݒ�
	moveEnemySprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_); // �T�C�Y��ݒ�
	moveEnemySprite_.params.color = HE::Color(0, 255, 0, 255); // �ΐF�̃X�v���C�g
	moveEnemySprite_.SetHidden(true); // ������Ԃł͔�\���ɂ���
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
		moveEnemySprite_.params.pos = enemyPos; // �G�̈ʒu���X�V
	}

	
	
}