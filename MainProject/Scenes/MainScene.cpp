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
	markerView_.Load();
	countdownView_.Load();
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
	countdownView_.Initialize(); // カウントダウンの初期化
	gameState_= 3; // ゲームオーバー状態を初期化
	prevGameState_ = gameState_; // 前のゲーム状態を初期化
	isStartShowed_ = false; // ゲーム開始が表示されたかどうかを初期化
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

	markerView_.MarkerDelete(); // マーカーを削除
	playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(), gameManager_.GetPlayerModel().GetIsMovingToRight(), gameManager_.GetPlayerModel().GetIsGravityUpward(), gameManager_.GetPlayerInvincible().GetIsInvincible(), gameManager_.GetPlayerInvincible().GetInvincibleRemainingTime(gameManager_.GetTimer())); // プレイヤーの位置を更新
	playerView_.AnimStop(); // プレイヤーのアニメーションを停止
	invincibleItemView_.Update(gameManager_.GetInvincibleItemModel().GetItemPosition(), gameManager_.GetInvincibleItemModel().GetIsActive()); // 無敵アイテムの位置を更新
	EnemyViewUpdate(); // 敵のビューを更新

	countdownView_.ShowCountDown();

	isPrevGravityUpward_ = gameManager_.GetPlayerModel().GetIsGravityUpward(); // 前の重力方向が上向きだったかどうかを初期化
	isPrevPlayerInvincible_ = gameManager_.GetPlayerInvincible().GetIsInvincible(); // 前のプレイヤーが無敵だったかどうかを初期化
	isSceceMovingToMain_ = false; // シーンが移動中かどうかを初期化
	isSceceMovingToTitle_ = false; // シーンがタイトルに移動中かどうかを初期化
	prevSelectedMenu_ = selectedMenu_ = 0; // 前回選択されたメニューを初期化
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	switch (gameState_)
	{
	case 0: // ゲーム中
		MoniteringGameManager();
		if (InputSystem.Keyboard.wasPressedThisFrame.Space) {
			gameManager_.GravityChange(); // スペースキーが押されたら重力の向きを変更
		}
		gameManager_.Update();
		playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(),gameManager_.GetPlayerModel().GetIsMovingToRight(),gameManager_.GetPlayerModel().GetIsGravityUpward(),gameManager_.GetPlayerInvincible().GetIsInvincible(),gameManager_.GetPlayerInvincible().GetInvincibleRemainingTime(gameManager_.GetTimer())); // プレイヤーの位置を更新
		invincibleItemView_.Update(gameManager_.GetInvincibleItemModel().GetItemPosition(),gameManager_.GetInvincibleItemModel().GetIsActive()); // 無敵アイテムの位置を更新
		EnemyViewUpdate(); // 敵のビューを更新
		NotificateTime(); // タイマーの通知を表示

		if (countdownView_.GetCurrentFrame() >= 10) {
			countdownView_.HideCountDown(); // カウントダウンを非表示にする
		}
		

		break;
	case 1: // ゲームオーバー
		gameOverView_.ShowGameOver(1,gameManager_.GetTimerModel().GetTimer()); // ゲームオーバー画面を表示
		timerView_.HideNotification(); // タイマーの通知を非表示
		playerView_.AnimStop(); // プレイヤーのアニメーションを停止
		for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
		{
			moveEnemyView_[i].AnimStop(); // 手裏剣のアニメーションを停止
		}
		SelectMenu(); // メニューを選択する
		MarkerUpdate(); // マーカーを更新
		if (isSceceMovingToMain_ && !seManager_.GetIsSEPlaying(2)) {
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		if (isSceceMovingToTitle_ && !seManager_.GetIsSEPlaying(1))
		{
			SceneManager.SetNextScene(NextScene::TitleScene); // タイトルシーンに移動
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
		SelectMenu(); // メニューを選択する
		MarkerUpdate(); // マーカーを更新
		if (isSceceMovingToMain_ && !seManager_.GetIsSEPlaying(2)) {
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		if (isSceceMovingToTitle_ && !seManager_.GetIsSEPlaying(1))
		{
			SceneManager.SetNextScene(NextScene::TitleScene); // タイトルシーンに移動
		}
		break;
	case 3://ゲーム開始前
		if (countdownView_.GetCurrentFrame() >= 30) {
			countdownView_.ShowStart(); // 開始
			playerView_.AnimStart(); // プレイヤーのアニメーションを開始
			gameState_ = 0; // ゲーム開始
		}
		if (countdownView_.GetCurrentFrame() % 10 == 1) {
			seManager_.PlaySE(3); // カウントダウンのSEを再生
		}

		break;
	}
	SoundControl(); // SEの制御
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
			suitonFusumaView_[i].FusumaMove(gameManager_.GetSuitonEnemy(i).GetIsActive()); // ふすまの表示を更新
			seManager_.PlaySE(7); // ふすまのSEを再生
			isPrevSuitonEnemyActive_[i] = gameManager_.GetSuitonEnemy(i).GetIsActive(); // 前の水遁の術の敵がアクティブだったかどうかを更新
		}
	
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Update(gameManager_.GetKatonEnemy(i).GetIsActive(), gameManager_.GetKatonEnemy(i).GetSuitonEnemyState());
		if (isPrevKatonEnemyActive_[i] != gameManager_.GetKatonEnemy(i).GetIsActive()) {
			katonFusumaView_[i].FusumaMove(gameManager_.GetKatonEnemy(i).GetIsActive()); // ふすまの表示を更新
			seManager_.PlaySE(7); // ふすまのSEを再生
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

void MainScene::SelectMenu()
{
	if (isSceceMovingToMain_ || isSceceMovingToTitle_)return; // シーンが移動中の場合はメニュー選択を無効化
	if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
		selectedMenu_--; // 上キーでメニューを上に移動
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
		selectedMenu_++; // 下キーでメニューを下に移動
	}
	if (selectedMenu_ <= 0)
	{
		selectedMenu_ = 0; // 上限を0に制限
	}
	if (selectedMenu_ >= menuCount_)
	{
		selectedMenu_ = menuCount_ - 1; // 下限をメニュー数-1に制限
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
		if (selectedMenu_ == 0) {

			seManager_.PlaySE(2); // SEを再生
			isSceceMovingToMain_ = true; // シーンが移動中であることを示す
		}
		else if (selectedMenu_ == 1) {
			seManager_.PlaySE(1); // SEを再生
			isSceceMovingToTitle_ = true; // シーンが移動中であることを示す
		}
	}
}

void MainScene::MarkerUpdate()
{
	switch (selectedMenu_)
	{
	case 0:
		markerView_.UpdateMarker(Math::Vector2(340.0f, 490.0f)); // Start menu position
		break;
	case 1:
		markerView_.UpdateMarker(Math::Vector2(340.0f, 605.0f)); // Tutorial menu position
		break;
	}
}

void MainScene::SoundControl()
{
	if (isPrevGravityUpward_ != gameManager_.GetPlayerModel().GetIsGravityUpward()) {
		seManager_.PlaySE(9);
		isPrevGravityUpward_ = gameManager_.GetPlayerModel().GetIsGravityUpward(); // 前の重力方向を更新
	}
	if (isPrevPlayerInvincible_ != gameManager_.GetPlayerInvincible().GetIsInvincible()) {
		if (gameManager_.GetPlayerInvincible().GetIsInvincible()) {
			bgmManager_.PlayBGMFromTop(2); // プレイヤーが無敵状態になったら無敵BGMを再生
		}
		else {
			bgmManager_.PlayBGMContinue(0); // プレイヤーが無敵状態でなくなったら通常BGMを再生
		}
		isPrevPlayerInvincible_ = gameManager_.GetPlayerInvincible().GetIsInvincible(); // 前のプレイヤーの無敵状態を更新
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		if (prevSuitonEnemyState_[i] != gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState()) {
			if (gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState() == 1) {
				seManager_.PlaySE(6); // 水遁の術の敵がアクティブになったらSEを再生
			}
			prevSuitonEnemyState_[i] = gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState(); // 前の水遁の術の敵の状態を更新
		}
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		if (prevKatonEnemyState_[i] != gameManager_.GetKatonEnemy(i).GetSuitonEnemyState()) {
			if (gameManager_.GetKatonEnemy(i).GetSuitonEnemyState() == 1) {
				seManager_.PlaySE(5); // 火遁の術の敵がアクティブになったらSEを再生
			}
			prevKatonEnemyState_[i] = gameManager_.GetKatonEnemy(i).GetSuitonEnemyState(); // 前の火遁の術の敵の状態を更新
		}
	}
	if (gameManager_.GetTimer() == 10.0f || gameManager_.GetTimer() == 30.0f) {
		seManager_.PlaySE(11);
	}
	if (prevSelectedMenu_ != selectedMenu_) {
		seManager_.PlaySE(1); // メニュー選択のSEを再生
		prevSelectedMenu_ = selectedMenu_; // 前回選択されたメニューを更新
	}
	if (prevGameState_ != gameState_) {
		switch (gameState_)
		{
		case 0: // ゲーム中
			bgmManager_.PlayBGMFromTop(0); // BGMを再生
			seManager_.PlaySE(4); // ゲーム中のSEを再生
			prevGameState_ = gameState_; // 前のゲーム状態を更新
			break;
		case 1: // ゲームオーバー
			bgmManager_.StopBGM(); // BGMを停止
			seManager_.PlaySE(8); // ゲームオーバーのSEを再生
			prevGameState_ = gameState_; // 前のゲーム状態を更新
			break;
		case 2: // ゲームクリア
			bgmManager_.StopBGM(); // BGMを停止
			seManager_.PlaySE(10); // ゲームクリアのSEを再生
			prevGameState_ = gameState_; // 前のゲーム状態を更新
			break;
		}
	   
	}


}

