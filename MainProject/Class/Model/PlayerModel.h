#pragma once

#include "../../HuEngine.h"

class PlayerModel {
public:
	void Load(); //���View�Ɉړ����A�v���C���[�̕`����L�q
	void Initialize(HE::Math::Vector2 initialPos,float leftedge,float rightedge);//�����ʒu��GameManager�Œ�`
	void Update();
	void UpdatePlayerSprite(); // �v���C���[�̃X�v���C�g���X�V����A���View�Ɉړ�
	HE::Math::Rectangle GetCollision();
	void OnCollisionGround(HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void OnGroundCheck(); // ���ɏ���Ă��邩�ǂ������m�F����
	void PlayerMoveX();
	void PlayerMoveY();
	void GravityChange(); // �v���C���[�̈ړ�������ύX����A���MainScene�ɃX�N���v�g���ړ�


private:
	//�ȉ��v�����i�[���������Ă����ϐ�
	float playerSpeed_ = 450.0f; // �v���C���[�̈ړ����x
	float gravity_ = 16000.0f; // �d�͂̋���
	float roopInterval_ = 10.0f; // �㉺���[�v���������ɋt������o�Ă���܂ł̎��ԕ␳

	float collisionSizeCorrection_x_ = 0.0f; // �Փ˔���̃T�C�Y�␳
	float collisionSizeCorrection_y_ = 0.0f; // �Փ˔���̃T�C�Y�␳
	float collisionPositionCorrection_x_ = 0.0f; // �Փ˔���̈ʒu�␳
	float collisionPositionCorrection_y_ = 0.0f; // �Փ˔���̈ʒu�␳
	//�v�����i�[���������Ă����ϐ������܂�


	//�ȉ��N���X���Ŏg�p����ϐ��B
	HE::Sprite draftSprite_;
	HE::Sprite collision_sprite_; // �Փ˔͈͕\���p�̃X�v���C�g
	HE::Math::Vector2 playerPosition_;
	float playerWidth_ = 50.0f; // �v���C���[�̕�
	float playerHeight_ = 50.0f; // �v���C���[�̍���
	float gameWindowLeftEdge_; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float gameWindowRightEdge_; // �Q�[���E�B���h�E�̉E�[�̈ʒu
	float floorRange_x_min_;
	float floorRange_x_max_;
	bool isMovingToRight_ = true; // �v���C���[���E�Ɉړ������ǂ��� 
	bool isGravityUpward_ =false; // �v���C���[����ɏd�͂��󂯂Ă��邩�ǂ���
	bool isOnGround_ = false;
	float fallingSpeed_ ; // �������x

};