#pragma once

#include "../../HuEngine.h"
#include "FloarData.h"

class PlayerModel {
public:
	void Load(); //���View�Ɉړ����A�v���C���[�̕`����L�q
	void Initialize(HE::Math::Vector2 initialPos);//�����ʒu��GameManager�Œ�`
	void SetStageData();
	void Update();
	void UpdatePlayerSprite(); // �v���C���[�̃X�v���C�g���X�V����A���View�Ɉړ�
	void PlayerMoveX();
	void PlayerMoveY();
	void GroundCheck(); // �v���C���[�����ɐڐG���Ă��邩�ǂ������m�F����
	void DirectionChange(); // �v���C���[�̈ړ�������ύX����A���MainScene�ɃX�N���v�g���ړ�


private:
	float playerSpeed_ = 300.0f; // �v���C���[�̈ړ����x
	float gravity_ = 980.0f; // �d�͂̋���


	//�ȉ��N���X���Ŏg�p����ϐ�
	HE::Sprite draftSprite_;
	HE::Math::Vector2 playerPosition_;
	bool isMovingToRight_ = true; // �v���C���[���E�Ɉړ������ǂ��� 
	bool isGravityUpward_ =false; // �v���C���[����ɏd�͂��󂯂Ă��邩�ǂ���
	bool isOnGround_X_ ; // �v���C���[�����ɐڐG���Ă��邩�ǂ���
	bool isOnGround_Y_; 
	float fallingSpeed_ ; // �������x

	//�ȉ�FloorData����ǂݍ��ރf�[�^��ۑ�����ϐ��B�z�񐔂�FloorData�̒�`�ɍ��킹�邱��
	FloorData floorData_; // ���̃f�[�^���Ǘ�����N���X
	int floorLines_ = 3; // ���̗�̐��AFloorData�̒�`�ɍ��킹�邱��
	int floorEdgeNum_ = 6; // ���̒[�̐��AFloorData�̒�`�ɍ��킹�邱��
	float floorHeight_ ; // ���̌���
	float floorPosition_Y_[3]; 
	float floorEdgePosition_X_[3][6];

};