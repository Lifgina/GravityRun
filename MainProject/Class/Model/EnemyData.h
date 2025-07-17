#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
	int GetSuitonEnemyCount() const { return suitonEnemyCount_; }
	int GetKatonEnemyCount() const { return katonEnemyCount_; }

	// �G�̈ʒu���擾
	HE::Math::Vector2 GetSilentEnemyPosition(int index) const { return SilentenemyPosition_[index]; }
	HE::Math::Vector2 GetMoveEnemyPosition(int index) const { return moveEnemyPosition_[index]; }
	// �G�̌������擾
	float GetSilentEnemyDirection(int index) const { return silentEnemyDirection_[index]; }
	float GetMoveEnemyDirection(int index) const { return moveEnemyDirection_[index]; }
	// �G�̈ړ����x���擾
	float GetMoveEnemySpeed(int index) const { return moveEnemySpeed_[index]; }
	// �G�̈ړ��͈͂��擾
	float GetMoveEnemyMinRange_X(int index) const { return moveEnemyMinRange_X_[index]; }
	float GetMoveEnemyMaxRange_X(int index) const { return moveEnemyMaxRange_X_[index]; }

	// �G���A�N�e�B�u�ɂȂ�܂ł̎��Ԃ��擾
	float GetMoveEnemyTimeToActive(int index) const { return moveEnemyTimeToActive_[index]; }

	// ���ٔE�҂̃f�[�^���擾
	// ���ٔE�҂̈ʒu���擾
	HE::Math::Vector2 GetSuitonEnemyModelPosition(int index) const { return suitonEnemyModelPosition_[index]; }
	HE::Math::Vector2 GetSuitonEnemyViewPosition(int index) const { return suitonEnemyViewPosition_[index]; }
	// ���ٔE�҂̌������擾
	int GetSuitonEnemyDirection(int index) const { return suitonEnemyDirection_[index]; }
	// ���ٔE�҂̏Փ˔���̍������擾
	float GetSuitonEnemyCollisionHeight() const { return suitonEnemyCollisionHeight_; }
	// ���ٔE�҂̏Փ˔���̕����擾
	float GetSuitonEnemyCollisionWidth() const { return suitonEnemyCollisionWidth_; }
	// ���ٔE�҂̍U���񐔂��擾
	int GetSuitonAttackTimes() const { return suitonAttackTimes_; }
	// ���ٔE�҂̏o�����Ԃ��擾
	float GetSuitonEnemyApeearTime(int index) const { return suitonEnemyApeearTime_[index]; }
	// ���ٔE�҂̍U�����Ԃ��擾
	float GetSuitonEnemyAttackTime(int index) const { return suitonEnemyAttackTime_[index]; }
	// ���ٔE�҂̍U����̑ҋ@���Ԃ��擾
	float GetSuitonEnemyAttackAfterTime(int index) const { return suitonEnemyAttackAfterTime_[index]; }
	// ���ٔE�҂̍U���̎������Ԃ��擾
	float GetSuitonEnemyAttackDuration(int index) const { return suitonEnemyAttackDuration_[index]; }
	// ���ٔE�҂̍U���ŏo������G�̐����擾
	int GetAttackSuitonEnemyAmount(int index) const { return attackSuitonEnemyAmount_[index]; }

	//�ΓٔE�҂̃f�[�^���擾
	//�ΓٔE�҂̈ʒu���擾
	HE::Math::Vector2 GetKatonEnemyModelPosition(int index) const { return katonEnemyModelPosition_[index]; }
	HE::Math::Vector2 GetKatonEnemyViewPosition(int index) const { return katonEnemyViewPosition_[index]; }
	//�ΓٔE�҂̏Փ˔���̍������擾
	float GetKatonEnemyCollisionHeight() const { return katonEnemyCollisionHeight_; }
	//�ΓٔE�҂̏Փ˔���̕����擾
	float GetKatonEnemyCollisionWidth() const { return katonEnemyCollisionWidth_; }
	//�ΓٔE�҂̍U���񐔂��擾
	int GetKatonAttackTimes() const { return katonAttackTimes_; }
	//�ΓٔE�҂̏o�����Ԃ��擾
	float GetKatonEnemyApeearTime(int index) const { return katonEnemyApeearTime_[index]; }
	//�ΓٔE�҂̍U�����Ԃ��擾
	float GetKatonEnemyAttackTime(int index) const { return katonEnemyAttackTime_[index]; }
	//�ΓٔE�҂̍U����̑ҋ@���Ԃ��擾
	float GetKatonEnemyAttackAfterTime(int index) const { return katonEnemyAttackAfterTime_[index]; }
	//�ΓٔE�҂̍U���̎������Ԃ��擾
	float GetKatonEnemyAttackDuration(int index) const { return katonEnemyAttackDuration_[index]; }
	//�ΓٔE�҂̍U���ŏo������G�̐����擾
	int GetAttackKatonEnemyAmount(int index) const { return attackKatonEnemyAmount_[index]; }

private:
	//�܂��т��̃f�[�^
	int silentEnemyCount_ = 4; // �܂��т��̐� 
	
	// �G�̈ʒu
	HE::Math::Vector2 SilentenemyPosition_[4] = {
		HE::Math::Vector2(540.0f,20.0f),
		HE::Math::Vector2(340.0f,195.0f),
		HE::Math::Vector2(875.0f,370.0f),
		HE::Math::Vector2(840.0f,545.0f),
	};
	//�G�̌����@1:������@-1:������
	//View���Ŏg�p
	float silentEnemyDirection_[4] = {-1,-1,-1,-1}; 

	//�藠���̃f�[�^
	int MoveEnemyCount_ = 2; // �藠���̐�
	// �G�̏����ʒu
	HE::Math::Vector2 moveEnemyPosition_[2] = {
		HE::Math::Vector2(940.0f+50-16, 350.0f-32.0f),
		HE::Math::Vector2(390.0f-16.0f ,  525.0f-32.0f),
	};
	float moveEnemyTimeToActive_[2] = {10.0f,10.0f}; // �G���A�N�e�B�u�ɂȂ�܂ł̎���
	// �G�̍ŏ��̌����@1:�E�����@-1:������
	float moveEnemyDirection_[2] = {-1,1};
	// �G�̈ړ����x
	float moveEnemySpeed_[2] = {300.0f,300.0f};
	// �G�̈ړ��͈�
	float moveEnemyMinRange_X_[2] = {240.0f,140.0f};
	float moveEnemyMaxRange_X_[2] = { 1140.0f-32.0f , 1040.0f-32.0f};

	//���ٔE�҂̃f�[�^
	int suitonEnemyCount_ = 4; // ���ٔE�҂̐�

	float suitonEnemyCollisionHeight_ = 155.0f; // ���ٔE�҂̏Փ˔���̍���
	float suitonEnemyCollisionWidth_ = 1200.0f; // ���ٔE�҂̏Փ˔���̕�

	// �G�̈ʒu
	HE::Math::Vector2 suitonEnemyModelPosition_[4] = {
		HE::Math::Vector2(40,0.0f+20.0f),
		HE::Math::Vector2(40,175.0f+20.0f),
		HE::Math::Vector2(40,350.0f + 20.0f),
		HE::Math::Vector2(40,525.0f + 20.0f),
	};
	
	HE::Math::Vector2 suitonEnemyViewPosition_[4] = {
		HE::Math::Vector2(1140.0f+18,175.0f-64.0f),
		HE::Math::Vector2(40+18,350.0f-64.0f),
		HE::Math::Vector2(1140.0f+18,525.0f -64.0f),
		HE::Math::Vector2(40+18,700.0f -64.0f),
	};

	int suitonEnemyDirection_[4] = { -1,1,-1,1 }; // �G�̌����@1:�E�����@-1:�������AView���Ŏg�p

	//�ȉ��̔z��͎��ԂƕR�Â��Ďg�p����
	int suitonAttackTimes_ = 4; // ���ٔE�҂̍U���̉�
	float suitonEnemyApeearTime_[4] = { 30.0f-3,35.0f-3,50.0f-3,55.0f-3 }; // �G���\������鎞��(�\�����n�߂鎞��)
	float suitonEnemyAttackTime_[4] = { 3.0f,3.0f,3.0f,3.0f }; // �G�̍U���܂ł̎���(�\�����o�̎���)
	float suitonEnemyAttackDuration_[4] = { 1.0f,1.0f,1.0f,1.0f }; // �G�̍U���̎�������
	float suitonEnemyAttackAfterTime_[4] = { 0.2f,0.2f,0.2f,0.2f }; // �G�̍U����̑ҋ@����
	int attackSuitonEnemyAmount_[4] = { 1,1,1,2 }; // �G�̍U���̐�

	//�ΓٔE�҂̃f�[�^
	int katonEnemyCount_ = 8; // �ΓٔE�҂̐�

	float katonEnemyCollisionHeight_ = 155.0f; // �ΓٔE�҂̏Փ˔���̍���
	float katonEnemyCollisionWidth_ = 100.0f; // �ΓٔE�҂̏Փ˔���̕�

	// �G�̈ʒu
	HE::Math::Vector2 katonEnemyModelPosition_[8] = {
		HE::Math::Vector2(340.0f,175.0f - 155.0f),
		HE::Math::Vector2(740.0f,175.0f - 155.0f),
		HE::Math::Vector2(440.0f,350.0f - 155.0f),
		HE::Math::Vector2(940.0f,350.0f - 155.0f),
		HE::Math::Vector2(340.0f,525.0f - 155.0f),
		HE::Math::Vector2(640.0f,525.0f - 155.0f),
		HE::Math::Vector2(340.0f,700.0f - 155.0f),
		HE::Math::Vector2(940.0f,700.0f - 155.0f)
	};

	HE::Math::Vector2 katonEnemyViewPosition_[8] = {
		HE::Math::Vector2(340.0f+18,175.0f - 64.0f),
		HE::Math::Vector2(740.0f+18,175.0f - 64.0f),
		HE::Math::Vector2(440.0f+18,350.0f - 64.0f),
		HE::Math::Vector2(940.0f+18,350.0f - 64.0f),
		HE::Math::Vector2(340.0f+18,525.0f - 64.0f),
		HE::Math::Vector2(640.0f+18,525.0f - 64.0f),
		HE::Math::Vector2(340.0f+18,700.0f - 64.0f),
		HE::Math::Vector2(940.0f+18,700.0f - 64.0f)
	};

	//�ȉ��̔z��͎��ԂƕR�Â��Ďg�p����
	int katonAttackTimes_ = 4; // �ΓٔE�҂̍U���̉�
	float katonEnemyApeearTime_[4] = { 20.0f - 3,35.0f - 3,45.0f - 3,50.0f - 3 }; // �G���\������鎞��
	float katonEnemyAttackTime_[4] = { 3.0f,3.0f,3.0f,3.0f }; // �G�̍U���܂ł̎���
	float katonEnemyAttackDuration_[4] = { 4.5f,4.5f,4.5f,4.5f }; // �G�̍U���̎�������
	float katonEnemyAttackAfterTime_[4] = { 0.3f,0.3f,0.3f,0.3f, }; // �G�̍U����̑ҋ@����
	int attackKatonEnemyAmount_[4] = { 1,1,2,2 }; // �G�̍U���̐�

	
};