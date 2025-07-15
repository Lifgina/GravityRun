#pragma once

#include "../HuEngine.h"
#include "../Class/Model/GameManager.h"
#include "../Class/Model/FloarData.h"
#include "../Class/Model/EnemyData.h"
#include "../Class/View/GameOverView.h"
#include "../Class/View/PlayerView.h"
#include "../Class/View/FloorView.h"
#include "../Class/View/MoveEnemyView.h"
#include "../Class/View/SuitonEnemyView.h"
#include "../Class/View/KatonEnemyView.h"
#include "../Class/View/TimerView.h"
#include "../Class/View/MainBG.h"
#include "../Class/View/Pillar.h"
#include "../Class/View/SEmanager.h"
#include "../Class/View/BGMmanager.h"

class MainScene : public HE::Scene
{
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

	void MoniteringGameManager();

	void EnemyViewUpdate();

	void NotificateTime();


private:

	//�Q�[���̏��������Ɋւ��ύX�ł���ϐ�
	float timeLimit_ = 60.0f; // �^�C�����~�b�g
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(610.0f-30, 284.0f - 60.0f); // �����v���C���[�ʒu
	float leftEdge = 40.0f; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge = 1280.0f - 40.0f; // �Q�[���E�B���h�E�̉E�[�̈ʒu
	float playerWidth_ = 60.0f; // �v���C���[�̕�
	float playerHeight_ = 60.0f; // �v���C���[�̍���
	bool isMovingToRightFirst_ = true; // �v���C���[�̏����ړ�����
	bool isGravityUpwardFirst_ = false; // �v���C���[�̏����d�͕���

	//�Q�[���̕\�������Ɋւ��ύX�ł���ϐ�
	int notificationCount_ = 2; // �^�C�}�[�̒ʒm�̃J�E���g
	float notificationTime_[2] = {30.0f,50.0f}; // �^�C�}�[�̒ʒm��\������
	float notificatingTIme = 2.0f; // �^�C�}�[�̒ʒm��\�����鎞��


	int gameState_ ; // �Q�[���̏��
	GameManager gameManager_; // �Q�[���}�l�[�W���[�̃C���X�^���X
	FloorData floorData_; // ���f�[�^�̃C���X�^���X
	EnemyData enemyData_; // �G�f�[�^�̃C���X�^���X
	GameOverView gameOverView_; // �Q�[���I�[�o�[�r���[�̃C���X�^���X
	PlayerView playerView_; // �v���C���[�̃r���[�̃C���X�^���X
	FloorView floorView_[25]; // ���̃r���[�̃C���X�^���X 
	MoveEnemyView moveEnemyView_[2]; // �藠���̃r���[�̃C���X�^���X
	SuitonEnemyView suitonEnemyView_[5]; // ���ق̏p�̓G�̃r���[�̃C���X�^���X
	KatonEnemyView katonEnemyView_[12]; // �Γق̏p�̓G�̃r���[�̃C���X�^���X
	TimerView timerView_; // �^�C�}�[�̃r���[�̃C���X�^���X
	MainBG bg_; // �w�i�̃C���X�^���X
	Pillar pillar_; // ���̃C���X�^���X
	SEmanager seManager_; // SE�}�l�[�W���[�̃C���X�^���X
	BGMmanager bgmManager_; // BGM�}�l�[�W���[�̃C���X�^���X

};
