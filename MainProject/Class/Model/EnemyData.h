#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
	// �G�̈ʒu���擾
	HE::Math::Vector2 GetSilentEnemyPosition(int index) const { return SilentenemyPosition_[index]; }
	HE::Math::Vector2 GetMoveEnemyPosition(int index) const { return MoveEnemyPosition_[index]; }
	// �G�̌������擾
	float GetSilentEnemyDirection(int index) const { return silentEnemyDirection_[index]; }
	float GetMoveEnemyDirection(int index) const { return MoveEnemyDirection_[index]; }
	// �G�̈ړ����x���擾
	float GetMoveEnemySpeed(int index) const { return MoveEnemySpeed_[index]; }
	// �G�̈ړ��͈͂��擾
	float GetMoveEnemyMinRange_X(int index) const { return MoveEnemyMinRange_X_[index]; }
	float GetMoveEnemyMaxRange_X(int index) const { return MoveEnemyMaxRange_X_[index]; }

private:
	int silentEnemyCount_ = 7;
	int MoveEnemyCount_ = 0;

	//�܂��т��̃f�[�^
	// �G�̈ʒu
	HE::Math::Vector2 SilentenemyPosition_[7] = {
		HE::Math::Vector2(100.0f, 100.0f),
		HE::Math::Vector2(200.0f, 200.0f),
		HE::Math::Vector2(300.0f, 300.0f),
		HE::Math::Vector2(400.0f, 400.0f),
		HE::Math::Vector2(500.0f, 500.0f),
		HE::Math::Vector2(600.0f, 600.0f),
		HE::Math::Vector2(700.0f, 700.0f)
	
	};
	//�G�̌����@1:������@-1:������
	//View���Ŏg�p
	float silentEnemyDirection_[7] = {}; 

	//�藠���̃f�[�^
	// �G�̏����ʒu
	HE::Math::Vector2 MoveEnemyPosition_[1] = {

	};
	// �G�̍ŏ��̌����@1:�E�����@-1:������
	float MoveEnemyDirection_[7] = {};
	// �G�̈ړ����x
	float MoveEnemySpeed_[7] = {};
	// �G�̈ړ��͈�
	float MoveEnemyMinRange_X_[7] = {};
	float MoveEnemyMaxRange_X_[7] = {};
	
};