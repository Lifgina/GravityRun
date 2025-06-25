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
	int silentEnemyCount_ = 4; // �܂��т��̐� GameManager.h�Œ�`����Ă���G�̐��ɍ��킹��
	int MoveEnemyCount_ = 6; // �藠���̐� GameManager.h�Œ�`����Ă���G�̐��ɍ��킹��

	//�܂��т��̃f�[�^
	// �G�̈ʒu
	HE::Math::Vector2 SilentenemyPosition_[4] = {
		HE::Math::Vector2(1010.0-64.0f, 142.0f-64.0f),
		HE::Math::Vector2(460.0f-32.0f, 284.0f-64.0f),
		HE::Math::Vector2(310.0f-64.0f, 568.0f-64.0f),
		HE::Math::Vector2(900.0f+64.0f, 710.0f-64.0f),
	
	};
	//�G�̌����@1:������@-1:������
	//View���Ŏg�p
	float silentEnemyDirection_[4] = {}; 

	//�藠���̃f�[�^
	// �G�̏����ʒu
	HE::Math::Vector2 MoveEnemyPosition_[6] = {
		HE::Math::Vector2(1110.0f-64.0f, 142.0f-64.0f),
		HE::Math::Vector2(110.0f+64.0f ,  142.0f+10.0f),
		HE::Math::Vector2(310.0f + 64.0f,  284.0f+10.0f),
		HE::Math::Vector2(910.0f + 64.0f,  426.0f -64.0f),
		HE::Math::Vector2(110.0f + 64.0f,  568.0f - 64.0f),
		HE::Math::Vector2(1110.0f - 64.0f, 568.0f +10.0f),
	};
	// �G�̍ŏ��̌����@1:�E�����@-1:������
	float MoveEnemyDirection_[6] = {-1,1,1,-1,1,-1};
	// �G�̈ړ����x
	float MoveEnemySpeed_[6] = {300.0f,300.0f,300.0f,300.0f,300.0f,300.0f};
	// �G�̈ړ��͈�
	float MoveEnemyMinRange_X_[6] = {10.0f,10.0f, 10.0f, 10.0f, 10.0f, 10.0f};
	float MoveEnemyMaxRange_X_[6] = { 1146.0f , 1146.0f , 1146.0f , 1146.0f , 1146.0f , 1146.0f  };
	
};