//
// SuitonEnemyView.cpp
//

#include "SuitonEnemyView.h"

using namespace HE;

void SuitonEnemyView::Load()
{
	suitonEnemySprite_ = HE::Sprite("SuitonEnemy.png");
	suitonEnemyAttackSprite_ = HE::Sprite("suiton.png");
	suitonHitRangeSprite_ = HE::Sprite("hit_blue.png"); // ���ق̏p�̍U���̃q�b�g�͈͂̃X�v���C�g��ǂݍ���
	RenderingPath->AddSprite(&suitonEnemySprite_, 110); // ���ق̏p�̓G�̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&suitonEnemyAttackSprite_, 100); // ���ق̏p�̍U���̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&suitonHitRangeSprite_, 90); // ���ق̏p�̍U���̃q�b�g�͈͂̃X�v���C�g�������_�����O�p�X�ɒǉ�
}

void SuitonEnemyView::Initialize(Math::Vector2 ninjaPos,float attackDirection,Math::Vector2 attackPos)
{
	suitonEnemySprite_.params.pos = ninjaPos; // ���ق̏p�̓G�̏����ʒu��ݒ�
	suitonHitRangeSprite_.params.pos = attackPos; // ���ق̏p�̍U���̃q�b�g�͈͂̏����ʒu��ݒ�
	suitonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // ���ق̏p�̓G�̃T�C�Y��ݒ�
	if (attackDirection == 1) {
		suitonEnemyAttackSprite_.params.enableMirror(); // �U���������E�̏ꍇ�A�X�v���C�g�𔽓]
	}
	else if(attackDirection==-1) {
		suitonEnemyAttackSprite_.params.disableMirror(); // �U�����������̏ꍇ�A�X�v���C�g�𔽓]���Ȃ�
	}
	suitonEnemyAttackSprite_.params.siz = Math::Vector2(1280.0f, 150.0f); // ���ق̏p�̍U���̃T�C�Y��ݒ�
	suitonHitRangeSprite_.params.siz = Math::Vector2(1200.0f, 161.0f);  // ���ق̏p�̍U���̃q�b�g�͈͂̃T�C�Y��ݒ�

}


void SuitonEnemyView::Update(bool isActive, int suitonEnemyState,Math::Vector2 suitonAttackPos)
{
	suitonEnemyAttackSprite_.params.pos = suitonAttackPos;
	if (!isActive) {
		suitonEnemySprite_.SetHidden(true);
		suitonEnemyAttackSprite_.SetHidden(true);
		suitonHitRangeSprite_.SetHidden(true); // ���ق̏p�̍U���̃q�b�g�͈͂��\���ɂ���
	}
	else {
		switch (suitonEnemyState)
		{
		case 0: // �ҋ@���
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			suitonHitRangeSprite_.SetHidden(false); // ���ق̏p�̍U���̃q�b�g�͈͂�\������
			break;
		case 1: // �U�����
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(false);
			suitonHitRangeSprite_.SetHidden(true); 
			break;
		case 2: // �U������
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			suitonHitRangeSprite_.SetHidden(true); 
			break;
		}
	
	}
}