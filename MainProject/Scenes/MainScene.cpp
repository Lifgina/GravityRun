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
	playerView_.Load();
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Load();
	}
	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	gameOverView_.Initialize(); // ゲームオーバービューの初期化
	isGameOver_ = false; // ゲームオーバー状態を初期化
	gameManager_.Initialize(timeLimit_, floorData_.GetFloorCount(), enemyData_.GetSilentEnemyCount(), enemyData_.GetMoveEnemyCount(), enemyData_.GetSuitonEnemyCount(), enemyData_.GetSuitonAttackTimes());
	gameManager_.PlayerSetup(initialPlayerPosition_, leftEdge, rightEdge, isMovingToRightFirst_, isGravityUpwardFirst_, playerWidth_, playerHeight_);
	for (int i = 0; i <floorData_.GetFloorCount(); i++)
	{
		gameManager_.FloorSetup(i, floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i),floorData_.GetIsBreakable(i));
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
		gameManager_.SuitonEnemyPositionSetup(i, enemyData_.GetSuitonEnemyModelPosition(i));
		gameManager_.SuitonEnemyAttackSetup(i, enemyData_.GetSuitonEnemyApeearTime(i), enemyData_.GetSuitonEnemyAttackTime(i), enemyData_.GetSuitonEnemyAttackDuration(i), enemyData_.GetSuitonEnemyAttackAfterTime(i), enemyData_.GetAttackSuitonEnemyAmount(i));
		suitonEnemyView_[i].Initialize(enemyData_.GetSuitonEnemyViewPosition(i), enemyData_.GetSuitonEnemyModelPosition(i));
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
		gameOverView_.ShowGameOver(); // ゲームオーバー画面を表示
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enterキーが押されたらシーンをリセット
		}
		return; // ゲームオーバー状態では更新処理を行わない
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Space) {
		gameManager_.GravityChange(); // スペースキーが押されたら重力の向きを変更
	}
	gameManager_.Update();
	playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition()); // プレイヤーの位置を更新
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Update(gameManager_.GetMoveEnemy(i).GetEnemyPosition(), gameManager_.GetTimerModel().GetTimer());
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Update(gameManager_.GetSuitonEnemy(i).GetIsActive(),gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState());
	}
	MoniteringGameManager();


	Scene::Update(deltaTime);
}

void MainScene::MoniteringGameManager()
{
	isGameOver_ = gameManager_.GetIsGameOver(); // ゲームオーバー状態を取得
}
