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
	invincibleItemView_.Load();
	seManager_.Load();
	bgmManager_.Load();
	for (int i = 0; i < floorData_.GetFloorCount(); i++)
	{
		floorView_[i].Load(floorData_.GetIsBreakable(i)); 
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		silentEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Load();
		suitonFusumaView_[i].Load(0,1);
		
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Load();
		katonFusumaView_[i].Load(1, 0);
	}

	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	gameOverView_.Initialize(); // ゲームオーバービューの初期化
	playerView_.Initialize(); // プレイヤーの初期化
	timerView_.Initialize(); // タイマーの初期化
	bg_.Initialize(); // 背景の初期化
	pillar_.Initialize(); // 柱の初期化
	invincibleItemView_.Initialize(); // 無敵アイテムの初期化
	gameState_= 3; // ゲームオーバー状態を初期化
	gameManager_.Initialize(timeLimit_, floorData_.GetFloorCount(), enemyData_.GetSilentEnemyCount(), enemyData_.GetMoveEnemyCount(), enemyData_.GetSuitonEnemyCount(), enemyData_.GetSuitonAttackTimes(),enemyData_.GetKatonEnemyCount(),enemyData_.GetKatonAttackTimes());
	gameManager_.PlayerSetup(initialPlayerPosition_, leftEdge, rightEdge, isMovingToRightFirst_, isGravityUpwardFirst_, playerWidth_, playerHeight_);
	for (int i = 0; i <floorData_.GetFloorCount(); i++)
	{
		floorView_[i].Initialize(floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i)); 
		gameManager_.FloorSetup(i, floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i),floorData_.GetIsBreakable(i),floorData_.GetBreakTime(i));
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		silentEnemyView_[i].Initialize(enemyData_.GetSilentEnemyPosition(i),enemyData_.GetSilentEnemyDirection(i));
		gameManager_.SilentEnemySetup(i, enemyData_.GetSilentEnemyPosition(i),enemyData_.GetSilentEnemyTimeToActive(i),enemyData_.GetSilentEnemyActiveDuration(i));
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Initialize(enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyTimeToActive(i));
		gameManager_.MoveEnemySetup(i,enemyData_.GetMoveEnemyTimeToActive(i), enemyData_.GetMoveEnemySpeed(i),enemyData_.GetMoveEnemyDirection(i), enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyMaxRange_X(i), enemyData_.GetMoveEnemyMinRange_X(i));
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		gameManager_.SuitonEnemyPositionSetup(i, enemyData_.GetSuitonEnemyModelPosition(i).y,enemyData_.GetSuitonEnemyCollisionHeight(),enemyData_.GetSuitonEnemyCollisionWidth(),enemyData_.GetSuitonEnemyDirection(i));
		gameManager_.SuitonEnemyAttackSetup(i, enemyData_.GetSuitonEnemyApeearTime(i), enemyData_.GetSuitonEnemyAttackTime(i), enemyData_.GetSuitonEnemyAttackDuration(i), enemyData_.GetSuitonEnemyAttackAfterTime(i), enemyData_.GetAttackSuitonEnemyAmount(i));
		suitonEnemyView_[i].Initialize(enemyData_.GetSuitonEnemyViewPosition(i), enemyData_.GetSuitonEnemyDirection(i),enemyData_.GetSuitonEnemyModelPosition(i));
		suitonFusumaView_[i].Initialize(enemyData_.GetSuitonFusumaPosition(i)); // ふすまの初期化
		isPrevSuitonEnemyActive_[i] = false; // 前の水遁の術の敵がアクティブだったかどうか
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		gameManager_.KatonEnemyPositionSetup(i, enemyData_.GetKatonEnemyModelPosition(i), enemyData_.GetKatonEnemyCollisionHeight(), enemyData_.GetKatonEnemyCollisionWidth());
		gameManager_.KatonEnemyAttackSetup(i, enemyData_.GetKatonEnemyApeearTime(i), enemyData_.GetKatonEnemyAttackTime(i), enemyData_.GetKatonEnemyAttackDuration(i), enemyData_.GetKatonEnemyAttackAfterTime(i), enemyData_.GetAttackKatonEnemyAmount(i));
		katonEnemyView_[i].Initialize(enemyData_.GetKatonEnemyViewPosition(i), enemyData_.GetKatonEnemyModelPosition(i));
		katonFusumaView_[i].Initialize(enemyData_.GetKatonFusumaPosition(i)); // ふすまの初期化
		isPrevKatonEnemyActive_[i] = false; // 前の火遁の術の敵がアクティブだったかどうか
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
		playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(),gameManager_.GetPlayerModel().GetIsMovingToRight(),gameManager_.GetPlayerModel().GetIsGravityUpward(),gameManager_.GetPlayerInvincible().GetIsInvincible()); // プレイヤーの位置を更新
		invincibleItemView_.Update(gameManager_.GetInvincibleItemModel().GetItemPosition(),gameManager_.GetInvincibleItemModel().GetIsActive()); // 無敵アイテムの位置を更新
		EnemyViewUpdate(); // 敵のビューを更新
		NotificateTime(); // タイマーの通知を表示

		break;
	case 1: // ゲームオーバー
		gameOverView_.ShowGameOver(1,gameManager_.GetTimerModel().GetTimer()); // ゲームオーバー画面を表示
		timerView_.HideNotification(); // タイマーの通知を非表示
		playerView_.AnimStop(); // プレイヤーのアニメーションを停止
		for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
		{
			moveEnemyView_[i].AnimStop(); // 手裏剣のアニメーションを停止
		}
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enterキーが押されたらシーンをリセット
		}
		break;
	case 2: // ゲームクリア
		gameOverView_.ShowGameOver(2, gameManager_.GetTimerModel().GetTimer()); // ゲームクリア画面を表示
		timerView_.HideNotification(); // タイマーの通知を非表示s
		playerView_.AnimStop(); // プレイヤーのアニメーションを停止
		for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
		{
			moveEnemyView_[i].AnimStop(); // 手裏剣のアニメーションを停止
		}
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			SceneManager.SetNextScene(NextScene::MainScene); // Enterキーが押されたらシーンをリセット
		}
		break;
	case 3://ゲーム開始前
		break;
	}
	Scene::Update(deltaTime);
}


void MainScene::EnemyViewUpdate() {
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++) {
		silentEnemyView_[i].Update(gameManager_.GetSilentEnemy(i).GetIsActive());
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Update(gameManager_.GetMoveEnemy(i).GetEnemyPosition(), gameManager_.GetTimerModel().GetTimer());
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Update(gameManager_.GetSuitonEnemy(i).GetIsActive(), gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState(),gameManager_.GetSuitonEnemy(i).GetSuitonEnemyPosition());
		if (isPrevSuitonEnemyActive_[i] != gameManager_.GetSuitonEnemy(i).GetIsActive()) {
			suitonFusumaView_[i].Update(gameManager_.GetSuitonEnemy(i).GetIsActive()); // ふすまの表示を更新
			isPrevSuitonEnemyActive_[i] = gameManager_.GetSuitonEnemy(i).GetIsActive(); // 前の水遁の術の敵がアクティブだったかどうかを更新
		}
	
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Update(gameManager_.GetKatonEnemy(i).GetIsActive(), gameManager_.GetKatonEnemy(i).GetSuitonEnemyState());
		if (isPrevKatonEnemyActive_[i] != gameManager_.GetKatonEnemy(i).GetIsActive()) {
			katonFusumaView_[i].Update(gameManager_.GetKatonEnemy(i).GetIsActive()); // ふすまの表示を更新
			isPrevKatonEnemyActive_[i] = gameManager_.GetKatonEnemy(i).GetIsActive(); // 前の火遁の術の敵がアクティブだったかどうかを更新
		}
	}
}

void MainScene::NotificateTime()
{
	bool notified = false;
	for (int i = 0; i < notificationCount_; i++)
	{
		if (gameManager_.GetTimer() >= notificationTime_[i] && gameManager_.GetTimer() < notificationTime_[i] + notificatingTime)
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
	for (int i = 0; i < gameManager_.GetFloorCount(); i++) {
		if (gameManager_.GetFloorModel(i).GetIsBroken()) {
			floorView_[i].FloorBreak(); // 床が壊れたら床のビューを更新
		}
	}
}
