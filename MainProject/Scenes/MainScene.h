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

	//ゲームの処理部分に関わる変更できる変数
	float timeLimit_ = 60.0f; // タイムリミット
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(610.0f-30, 284.0f - 60.0f); // 初期プレイヤー位置
	float leftEdge = 40.0f; // ゲームウィンドウの左端の位置
	float rightEdge = 1280.0f - 40.0f; // ゲームウィンドウの右端の位置
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ
	bool isMovingToRightFirst_ = true; // プレイヤーの初期移動方向
	bool isGravityUpwardFirst_ = false; // プレイヤーの初期重力方向

	//ゲームの表示部分に関わる変更できる変数
	int notificationCount_ = 2; // タイマーの通知のカウント
	float notificationTime_[2] = {30.0f,50.0f}; // タイマーの通知を表示時間
	float notificatingTIme = 2.0f; // タイマーの通知を表示する時間


	int gameState_ ; // ゲームの状態
	GameManager gameManager_; // ゲームマネージャーのインスタンス
	FloorData floorData_; // 床データのインスタンス
	EnemyData enemyData_; // 敵データのインスタンス
	GameOverView gameOverView_; // ゲームオーバービューのインスタンス
	PlayerView playerView_; // プレイヤーのビューのインスタンス
	FloorView floorView_[25]; // 床のビューのインスタンス 
	MoveEnemyView moveEnemyView_[2]; // 手裏剣のビューのインスタンス
	SuitonEnemyView suitonEnemyView_[5]; // 水遁の術の敵のビューのインスタンス
	KatonEnemyView katonEnemyView_[12]; // 火遁の術の敵のビューのインスタンス
	TimerView timerView_; // タイマーのビューのインスタンス
	MainBG bg_; // 背景のインスタンス
	Pillar pillar_; // 柱のインスタンス
	SEmanager seManager_; // SEマネージャーのインスタンス
	BGMmanager bgmManager_; // BGMマネージャーのインスタンス

};
