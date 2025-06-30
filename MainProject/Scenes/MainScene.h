#pragma once

#include "../HuEngine.h"
#include "../Class/Model/GameManager.h"
#include "../Class/Model/FloarData.h"
#include "../Class/Model/EnemyData.h"
#include "../Class/View/GameOverView.h"
#include "../Class/View/PlayerView.h"
#include "../Class/View/MoveEnemyView.h"

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

private:

	float timeLimit_ = 60.0f; // �^�C�����~�b�g
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(510.0f, 284.0f - 60.0f); // �����v���C���[�ʒu
	float leftEdge = 10.0f; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge = 1280.0f - 10.0f - 60.0f; // �Q�[���E�B���h�E�̉E�[�̈ʒu
	float playerWidth_ = 60.0f; // �v���C���[�̕�
	float playerHeight_ = 60.0f; // �v���C���[�̍���
	bool isMovingToRightFirst_ = true; // �v���C���[�̏����ړ�����
	bool isGravityUpwardFirst_ = false; // �v���C���[�̏����d�͕���

	bool isGameOver_ ; // �Q�[���I�[�o�[���
	GameManager gameManager_; // �Q�[���}�l�[�W���[�̃C���X�^���X
	FloorData floorData_; // ���f�[�^�̃C���X�^���X
	EnemyData enemyData_; // �G�f�[�^�̃C���X�^���X
	GameOverView gameOverView_; // �Q�[���I�[�o�[�r���[�̃C���X�^���X
	PlayerView playerView_; // �v���C���[�̃r���[�̃C���X�^���X
	MoveEnemyView moveEnemyView_[2]; // �藠���̃r���[�̃C���X�^���X

};
