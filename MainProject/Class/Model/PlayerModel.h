#pragma once

#include "../../HuEngine.h"

class PlayerModel {
public:
	void Load(); //�R���C�_�[�f�o�b�O�p�̃X�v���C�g�����[�h
	void Initialize(HE::Math::Vector2 initialPos,float leftedge,float rightedge,bool isMovingToRightFirst,bool isGravityUpwardFirst,float playerWidth,float playerHeight);//�����ʒu��GameManager�Œ�`
	void Update(float timer);
	HE::Math::Rectangle GetCollision();
	bool GetIsOnGround() const { return isOnGround_; } // ���ɏ���Ă��邩�ǂ������擾
	bool GetIsMovingToRight() const { return isMovingToRight_; } // �v���C���[���E�Ɉړ������ǂ������擾
	bool GetIsGravityUpward() const { return isGravityUpward_; } // �v���C���[����ɏd�͂��󂯂Ă��邩�ǂ������擾
	HE::Math::Vector2 GetPlayerPosition() const { return playerPosition_; } // �v���C���[�̈ʒu���擾
	void OnCollisionGround(HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void OnGroundCheck(); // ���ɏ���Ă��邩�ǂ������m�F����
	void PlayerMoveX(float timer);
	void PlayerMoveY(float timer);
	void GravityChange(float timer); // �v���C���[�̈ړ�������ύX����


private:
	//�ȉ��v�����i�[���������Ă����ϐ�
	float initialPlayerSpeed_ = 300.0f; // �v���C���[�̈ړ����x
	float afterPlayerSpeed_ = 400.0f; // �v���C���[�̈ړ����x�i���x�ω���j
	float speedChangeTime_ = 20.0f; // �v���C���[�̑��x�ω��܂Ŏ���
	float gravity_ = 8000.0f; // �d�͂̋���
	float loopInterval_ = 0.5f; // �㉺���[�v���������ɋt������o�Ă���܂ł̎��ԕ␳
	float gravityChangeCooltime_ = 0.1f; // �d�͕ύX�̃N�[������

	float collisionSizeCorrection_x_ = 0.0f; // �Փ˔���̃T�C�Y�␳
	float collisionSizeCorrection_y_ = 0.0f; // �Փ˔���̃T�C�Y�␳
	float collisionPositionCorrection_x_ = 0.0f; // �Փ˔���̈ʒu�␳
	float collisionPositionCorrection_y_ = 0.0f; // �Փ˔���̈ʒu�␳
	//�v�����i�[���������Ă����ϐ������܂�
	
	//�ȉ��f�o�b�O�p
	bool isDebugMode_ = false; // �f�o�b�O���[�h���ǂ���


	//�ȉ��N���X���Ŏg�p����ϐ��B
	HE::Sprite draftSprite_;
	HE::Sprite collision_sprite_; // �Փ˔͈͕\���p�̃X�v���C�g
	HE::Math::Vector2 playerPosition_;
	float playerWidth_ ; // �v���C���[�̕�
	float playerHeight_ ; // �v���C���[�̍���
	float gameWindowLeftEdge_; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float gameWindowRightEdge_; // �Q�[���E�B���h�E�̉E�[�̈ʒu
	float floorRange_x_min_;
	float floorRange_x_max_;
	bool isMovingToRight_ ; // �v���C���[���E�Ɉړ������ǂ��� 
	bool isGravityUpward_ ; // �v���C���[����ɏd�͂��󂯂Ă��邩�ǂ���
	bool isOnGround_ ;
	bool isLoopWaiting_ ;
	float loopWaitStartTime_ ;
	float loopedVelocityY_ ;
	float fallingSpeed_ ; // �������x
	float prevGravityChangeTime_ ; // �O��̏d�͕ύX����

};