#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
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

private:
	int silentEnemyCount_ = 4; // �܂��т��̐� 
	int MoveEnemyCount_ = 2; // �藠���̐�

	//�܂��т��̃f�[�^
	// �G�̈ʒu
	HE::Math::Vector2 SilentenemyPosition_[4] = {
		HE::Math::Vector2(1010.0-64.0f, 142.0f-32.0f),
		HE::Math::Vector2(460.0f-32.0f, 284.0f-32.0f),
		HE::Math::Vector2(310.0f-64.0f, 568.0f-32.0f),
		HE::Math::Vector2(910.0f, 710.0f-32.0f),
	
	};
	//�G�̌����@1:������@-1:������
	//View���Ŏg�p
	float silentEnemyDirection_[4] = {}; 

	//�藠���̃f�[�^
	// �G�̏����ʒu
	HE::Math::Vector2 moveEnemyPosition_[2] = {
		HE::Math::Vector2(360.0f-16.0f, 284.0f-32.0f),
		HE::Math::Vector2(760.0f-16.0f ,  568.0f-32.0f),
	};
	float moveEnemyTimeToActive_[2] = {15.0f,15.0f}; // �G���A�N�e�B�u�ɂȂ�܂ł̎���
	// �G�̍ŏ��̌����@1:�E�����@-1:������
	float moveEnemyDirection_[2] = {1,1};
	// �G�̈ړ����x
	float moveEnemySpeed_[2] = {300.0f,300.0f};
	// �G�̈ړ��͈�
	float moveEnemyMinRange_X_[2] = {310.0f,210.0f};
	float moveEnemyMaxRange_X_[2] = { 1110.0f-32.0f , 1110.0f-32.0f};
	
};