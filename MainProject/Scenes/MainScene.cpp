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
	bg_.Load();
	playerView_.Load();
	timerView_.Load();
	pillar_.Load();
	seManager_.Load();
	bgmManager_.Load();
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Load();
	}
	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	gameOverView_.Initialize(); // �Q�[���I�[�o�[�r���[�̏�����
	timerView_.Initialize(); // �^�C�}�[�̏�����
	bg_.Initialize(); // �w�i�̏�����
	pillar_.Initialize(); // ���̏�����
	gameState_= 0; // �Q�[���I�[�o�[��Ԃ�������
	gameManager_.Initialize(timeLimit_, floorData_.GetFloorCount(), enemyData_.GetSilentEnemyCount(), enemyData_.GetMoveEnemyCount(), enemyData_.GetSuitonEnemyCount(), enemyData_.GetSuitonAttackTimes(),enemyData_.GetKatonEnemyCount(),enemyData_.GetKatonAttackTimes());
	gameManager_.PlayerSetup(initialPlayerPosition_, leftEdge, rightEdge, isMovingToRightFirst_, isGravityUpwardFirst_, playerWidth_, playerHeight_);
	for (int i = 0; i <floorData_.GetFloorCount(); i++)
	{
		gameManager_.FloorSetup(i, floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i),floorData_.GetIsBreakable(i),floorData_.GetBreakTime(i));
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		gameManager_.SilentEnemySetup(i, enemyData_.GetSilentEnemyPosition(i));
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Initialize(enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyTimeToActive(i));
		gameManager_.MoveEnemySetup(i,enemyData_.GetMoveEnemyTimeToActive(i), enemyData_.GetMoveEnemySpeed(i),enemyData_.GetMoveEnemyDirection(i), enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyMaxRange_X(i), enemyData_.GetMoveEnemyMinRange_X(i));
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		gameManager_.SuitonEnemyPositionSetup(i, enemyData_.GetSuitonEnemyModelPosition(i),enemyData_.GetSuitonEnemyCollisionHeight(),enemyData_.GetSuitonEnemyCollisionWidth());
		gameManager_.SuitonEnemyAttackSetup(i, enemyData_.GetSuitonEnemyApeearTime(i), enemyData_.GetSuitonEnemyAttackTime(i), enemyData_.GetSuitonEnemyAttackDuration(i), enemyData_.GetSuitonEnemyAttackAfterTime(i), enemyData_.GetAttackSuitonEnemyAmount(i));
		suitonEnemyView_[i].Initialize(enemyData_.GetSuitonEnemyViewPosition(i), enemyData_.GetSuitonEnemyModelPosition(i));
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		gameManager_.KatonEnemyPositionSetup(i, enemyData_.GetKatonEnemyModelPosition(i), enemyData_.GetKatonEnemyCollisionHeight(), enemyData_.GetKatonEnemyCollisionWidth());
		gameManager_.KatonEnemyAttackSetup(i, enemyData_.GetKatonEnemyApeearTime(i), enemyData_.GetKatonEnemyAttackTime(i), enemyData_.GetKatonEnemyAttackDuration(i), enemyData_.GetKatonEnemyAttackAfterTime(i), enemyData_.GetAttackKatonEnemyAmount(i));
		katonEnemyView_[i].Initialize(enemyData_.GetKatonEnemyViewPosition(i), enemyData_.GetKatonEnemyModelPosition(i));
	}
	
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	MoniteringGameManager();
	switch (gameState_)
	{
	case 0: // �Q�[����
		if (InputSystem.Keyboard.wasPressedThisFrame.Space) {
			gameManager_.GravityChange(); // �X�y�[�X�L�[�������ꂽ��d�͂̌�����ύX
		}
		gameManager_.Update();
		playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(),gameManager_.GetPlayerModel().GetIsMovingToRight()); // �v���C���[�̈ʒu���X�V
		EnemyViewUpdate(); // �G�̃r���[���X�V
		NotificateTime(); // �^�C�}�[�̒ʒm��\��

		break;
	case 1: // �Q�[���I�[�o�[
		gameOverView_.ShowGameOver(1,gameManager_.GetTimerModel().GetTimer()); // �Q�[���I�[�o�[��ʂ�\��
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enter�L�[�������ꂽ��V�[�������Z�b�g
		}
		break;
	case 2: // �Q�[���N���A
		gameOverView_.ShowGameOver(2, gameManager_.GetTimerModel().GetTimer()); // �Q�[���N���A��ʂ�\��
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enter�L�[�������ꂽ��V�[�������Z�b�g
		}
		break;
	}
	Scene::Update(deltaTime);
}


void MainScene::EnemyViewUpdate() {
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Update(gameManager_.GetMoveEnemy(i).GetEnemyPosition(), gameManager_.GetTimerModel().GetTimer());
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Update(gameManager_.GetSuitonEnemy(i).GetIsActive(), gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState());
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Update(gameManager_.GetKatonEnemy(i).GetIsActive(), gameManager_.GetKatonEnemy(i).GetSuitonEnemyState());
	}
}

void MainScene::NotificateTime()
{
	bool notified = false;
	for (int i = 0; i < notificationCount_; i++)
	{
		if (gameManager_.GetTimer() >= notificationTime_[i] && gameManager_.GetTimer() < notificationTime_[i] + notificatingTIme)
		{
			timerView_.NotifiCateTime(timeLimit_ - notificationTime_[i]);
			notified = true;
			break; // 1�ł��Y������Βʒm
		}
	}
	if (!notified)
	{
		timerView_.HideNotification();
	}
}


void MainScene::MoniteringGameManager()
{
	gameState_ = gameManager_.GetGameState(); // �Q�[���I�[�o�[��Ԃ��擾
}
