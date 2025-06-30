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

	float timeLimit_ = 60.0f; // タイムリミット
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(510.0f, 284.0f - 60.0f); // 初期プレイヤー位置
	float leftEdge = 10.0f; // ゲームウィンドウの左端の位置
	float rightEdge = 1280.0f - 10.0f - 60.0f; // ゲームウィンドウの右端の位置
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ
	bool isMovingToRightFirst_ = true; // プレイヤーの初期移動方向
	bool isGravityUpwardFirst_ = false; // プレイヤーの初期重力方向

	bool isGameOver_ ; // ゲームオーバー状態
	GameManager gameManager_; // ゲームマネージャーのインスタンス
	FloorData floorData_; // 床データのインスタンス
	EnemyData enemyData_; // 敵データのインスタンス
	GameOverView gameOverView_; // ゲームオーバービューのインスタンス
	PlayerView playerView_; // プレイヤーのビューのインスタンス
	MoveEnemyView moveEnemyView_[2]; // 手裏剣のビューのインスタンス

};
