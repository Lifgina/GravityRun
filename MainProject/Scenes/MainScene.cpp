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
	gameOverView_.Initialize(); // ゲームオーバービューの初期化
	timerView_.Initialize(); // タイマーの初期化
	bg_.Initialize(); // 背景の初期化
	pillar_.Initialize(); // 柱の初期化
	gameState_= 0; // ゲームオーバー状態を初期化
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
	case 0: // ゲーム中
		if (InputSystem.Keyboard.wasPressedThisFrame.Space) {
			gameManager_.GravityChange(); // スペースキーが押されたら重力の向きを変更
		}
		gameManager_.Update();
		playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(),gameManager_.GetPlayerModel().GetIsMovingToRight()); // プレイヤーの位置を更新
		EnemyViewUpdate(); // 敵のビューを更新
		NotificateTime(); // タイマーの通知を表示

		break;
	case 1: // ゲームオーバー
		gameOverView_.ShowGameOver(1,gameManager_.GetTimerModel().GetTimer()); // ゲームオーバー画面を表示
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enterキーが押されたらシーンをリセット
		}
		break;
	case 2: // ゲームクリア
		gameOverView_.ShowGameOver(2, gameManager_.GetTimerModel().GetTimer()); // ゲームクリア画面を表示
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enterキーが押されたらシーンをリセット
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
			break; // 1つでも該当すれば通知
		}
	}
	if (!notified)
	{
		timerView_.HideNotification();
	}
}


void MainScene::MoniteringGameManager()
{
	gameState_ = gameManager_.GetGameState(); // ゲームオーバー状態を取得
}
