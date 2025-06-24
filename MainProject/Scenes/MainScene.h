#pragma once

#include "../HuEngine.h"
#include "../Class/Model/GameManager.h"
#include "../Class/Model/FloarData.h"
#include "../Class/Model/EnemyData.h"
#include "../Class/View/GameOverView.h"

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


	bool isGameOver_ ; // �Q�[���I�[�o�[���
	GameManager gameManager_; // �Q�[���}�l�[�W���[�̃C���X�^���X
	FloorData floorData_; // ���f�[�^�̃C���X�^���X
	EnemyData enemyData_; // �G�f�[�^�̃C���X�^���X
	GameOverView gameOverView_; // �Q�[���I�[�o�[�r���[�̃C���X�^���X

};
