//
// SuitonEnemyView.cpp
//

#include "SuitonEnemyView.h"

using namespace HE;

void SuitonEnemyView::Load()
{
	suitonEnemySprite_ = HE::Sprite("");
	suitonEnemyAttackSprite_ = HE::Sprite("suiton.png");
}

void SuitonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	suitonEnemySprite_.params.pos = ninjaPos; // ���ق̏p�̓G�̏����ʒu��ݒ�
	suitonEnemySprite_.params.siz = Math::Vector2(60.0f, 60.0f); // ���ق̏p�̓G�̃T�C�Y��ݒ�
	suitonEnemySprite_.params.color = HE::Color(255, 255, 255, 255); // ���ق̏p�̓G�̐F��ݒ�
	suitonEnemyAttackSprite_.params.pos = attackPos; // ���ق̏p�̍U���̏����ʒu��ݒ�
	suitonEnemyAttackSprite_.params.siz = Math::Vector2(1280.0f, 132.0f); // ���ق̏p�̍U���̃T�C�Y��ݒ�
	suitonEnemyAttackSprite_.params.color = HE::Color(0, 0, 255, 200); // ���ق̏p�̍U���̐F��ݒ�
	RenderingPath->AddSprite(&suitonEnemySprite_, 0); // ���ق̏p�̓G�̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&suitonEnemyAttackSprite_, 0); // ���ق̏p�̍U���̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void SuitonEnemyView::Update(bool isActive, int suitonEnemyState)
{
	if (!isActive) {
		suitonEnemySprite_.SetHidden(true);
		suitonEnemyAttackSprite_.SetHidden(true);
	}
	else {
		switch (suitonEnemyState)
		{
		case 0: // �ҋ@���
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		case 1: // �U�����
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(false);
			break;
		case 2: // �U������
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		}
	
	}
}