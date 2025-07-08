//
// KatonEnemyView.cpp
//

#include "KatonEnemyView.h"

using namespace HE;

void KatonEnemyView::Load()
{
	katonEnemySprite_ = HE::Sprite("");
	katonEnemyAttackSprite_ = HE::Sprite("");
}

void KatonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	katonEnemySprite_.params.pos = ninjaPos; // ���ق̏p�̓G�̏����ʒu��ݒ�
	katonEnemySprite_.params.siz = Math::Vector2(100.0f, 155.0f); // ���ق̏p�̓G�̃T�C�Y��ݒ�
	katonEnemySprite_.params.color = HE::Color(255, 255, 255, 255); // ���ق̏p�̓G�̐F��ݒ�
	katonEnemyAttackSprite_.params.pos = attackPos; // ���ق̏p�̍U���̏����ʒu��ݒ�
	katonEnemyAttackSprite_.params.siz = Math::Vector2(100.0f, 155.0f); // ���ق̏p�̍U���̃T�C�Y��ݒ�
	katonEnemyAttackSprite_.params.color = HE::Color(255, 0, 0, 200); // ���ق̏p�̍U���̐F��ݒ�
	RenderingPath->AddSprite(&katonEnemySprite_, 0); // ���ق̏p�̓G�̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&katonEnemyAttackSprite_, 0); // ���ق̏p�̍U���̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void KatonEnemyView::Update(bool isActive, int katonEnemyState)
{
	if (!isActive) {
		katonEnemySprite_.SetHidden(true);
		katonEnemyAttackSprite_.SetHidden(true);
	}
	else {
		switch (katonEnemyState)
		{
		case 0: // �ҋ@���
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			break;
		case 1: // �U�����
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(false);
			break;
		case 2: // �U������
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			break;
		}
	
	}
}