//
// MainScene.cpp
//

#include "MainScene.h"

using namespace HE;

// initialize member variables.
MainScene::MainScene()
{

}

// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
	Scene::ResizeLayout();



}

// load resources.
void MainScene::Load()
{
	gameManager_.Load();
	gameOverView_.Load();


	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	gameOverView_.Initialize(); // �Q�[���I�[�o�[�r���[�̏�����
	isGameOver_ = false; // �Q�[���I�[�o�[��Ԃ�������
	gameManager_.Initialize(timeLimit_);
	for (int i = 0; i <floorData_.GetFloorCount(); i++)
	{
		gameManager_.FloorSetup(i, floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i));
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		gameManager_.SilentEnemySetup(i, enemyData_.GetSilentEnemyPosition(i));
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		gameManager_.MoveEnemySetup(i, enemyData_.GetMoveEnemySpeed(i),enemyData_.GetMoveEnemyDirection(i), enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyMaxRange_X(i), enemyData_.GetMoveEnemyMinRange_X(i));
	}

}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	if (isGameOver_) {
		gameOverView_.ShowGameOver(); // �Q�[���I�[�o�[��ʂ�\��
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enter�L�[�������ꂽ��V�[�������Z�b�g
		}
		return; // �Q�[���I�[�o�[��Ԃł͍X�V�������s��Ȃ�
	}
	gameManager_.Update();
	MoniteringGameManager();


	Scene::Update(deltaTime);
}

void MainScene::MoniteringGameManager()
{
	isGameOver_ = gameManager_.GetIsGameOver(); // �Q�[���I�[�o�[��Ԃ��擾
}
