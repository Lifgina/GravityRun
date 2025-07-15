//
// KatonEnemyView.cpp
//

#include "KatonEnemyView.h"

using namespace HE;

void KatonEnemyView::Load()
{
	katonEnemySprite_ = HE::Sprite("KatonEnemy.png");
	katonEnemyAttackSprite_ = HE::Sprite("katon.png");
}

void KatonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	katonEnemySprite_.params.pos = ninjaPos; // �Γق̏p�̓G�̏����ʒu��ݒ�
	katonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // �Γق̏p�̓G�̃T�C�Y��ݒ�
	katonEnemyAttackSprite_.params.pos = attackPos+Math::Vector2(-27.5f,0); // �Γق̏p�̍U���̏����ʒu��ݒ�
	katonEnemyAttackSprite_.params.siz = Math::Vector2(155.0f, 155.0f); // �Γق̏p�̍U���̃T�C�Y��ݒ�
	RenderingPath->AddSprite(&katonEnemySprite_, 10); // �Γق̏p�̓G�̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&katonEnemyAttackSprite_, 0); // �Γق̏p�̍U���̃X�v���C�g�������_�����O�p�X�ɒǉ�
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