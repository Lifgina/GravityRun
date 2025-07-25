//
// KatonEnemyView.cpp
//

#include "KatonEnemyView.h"

using namespace HE;

void KatonEnemyView::Load()
{
	katonEnemySprite_ = HE::Sprite("KatonEnemy.png");
	katonEnemyAttackSprite_ = HE::Sprite("katon.png");
	katonHitRangeSprite_ = HE::Sprite("hit_red.png");
	RenderingPath->AddSprite(&katonEnemySprite_, 110); // �Γق̏p�̓G�̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&katonEnemyAttackSprite_, 100); // �Γق̏p�̍U���̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&katonHitRangeSprite_, 90); // �Γق̏p�̍U���̃q�b�g�͈͂̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void KatonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	katonEnemySprite_.params.pos = ninjaPos; // �Γق̏p�̓G�̏����ʒu��ݒ�
	katonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // �Γق̏p�̓G�̃T�C�Y��ݒ�
	katonEnemyAttackSprite_.params.pos = attackPos+Math::Vector2(-27.5f,0); // �Γق̏p�̍U���̏����ʒu��ݒ�
	katonEnemyAttackSprite_.params.siz = Math::Vector2(155.0f, 155.0f); // �Γق̏p�̍U���̃T�C�Y��ݒ�
	katonHitRangeSprite_.params.pos = attackPos; // �Γق̏p�̍U���̃q�b�g�͈͂̏����ʒu��ݒ�
	katonHitRangeSprite_.params.siz = Math::Vector2(100.0f, 155.0f); // �Γق̏p�̍U���̃q�b�g�͈͂̃T�C�Y��ݒ�

}

void KatonEnemyView::Update(bool isActive, int katonEnemyState)
{
	if (!isActive) {
		katonEnemySprite_.SetHidden(true);
		katonEnemyAttackSprite_.SetHidden(true);
		katonHitRangeSprite_.SetHidden(true); 
	}
	else {
		switch (katonEnemyState)
		{
		case 0: // �ҋ@���
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			katonHitRangeSprite_.SetHidden(false); 
			break;
		case 1: // �U�����
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(false);
			katonHitRangeSprite_.SetHidden(true); 
			break;
		case 2: // �U������
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			katonHitRangeSprite_.SetHidden(true);
			break;
		}
	
	}
}