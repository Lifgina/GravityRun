#pragma once

#include "../../HuEngine.h"

class PlayerModel {
public:
	void Load(); //後でViewに移動し、プレイヤーの描画を記述
	void Initialize(HE::Math::Vector2 initialPos,float leftedge,float rightedge);//初期位置はGameManagerで定義
	void Update(float timer);
	void UpdatePlayerSprite(); // プレイヤーのスプライトを更新する、後でViewに移動
	HE::Math::Rectangle GetCollision();
	bool GetIsOnGround() const { return isOnGround_; } // 床に乗っているかどうかを取得
	void OnCollisionGround(HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void OnGroundCheck(); // 床に乗っているかどうかを確認する
	void PlayerMoveX(float timer);
	void PlayerMoveY(float timer);
	void GravityChange(); // プレイヤーの移動方向を変更する、後でMainSceneにスクリプトを移動


private:
	//以下プランナーがいじっていい変数
	float initialPlayerSpeed_ = 300.0f; // プレイヤーの移動速度
	float afterPlayerSpeed_ = 450.0f; // プレイヤーの移動速度（速度変化後）
	float speedChangeTime_ = 20.0f; // プレイヤーの速度変化まで時間
	float gravity_ = 8000.0f; // 重力の強さ
	float loopInterval_ = 0.5f; // 上下ループをした時に逆側から出てくるまでの時間補正

	float collisionSizeCorrection_x_ = 0.0f; // 衝突判定のサイズ補正
	float collisionSizeCorrection_y_ = 0.0f; // 衝突判定のサイズ補正
	float collisionPositionCorrection_x_ = 0.0f; // 衝突判定の位置補正
	float collisionPositionCorrection_y_ = 0.0f; // 衝突判定の位置補正
	//プランナーがいじっていい変数ここまで
	


	//以下クラス内で使用する変数。
	HE::Sprite draftSprite_;
	HE::Sprite collision_sprite_; // 衝突範囲表示用のスプライト
	HE::Math::Vector2 playerPosition_;
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ
	float gameWindowLeftEdge_; // ゲームウィンドウの左端の位置
	float gameWindowRightEdge_; // ゲームウィンドウの右端の位置
	float floorRange_x_min_;
	float floorRange_x_max_;
	bool isMovingToRight_ = true; // プレイヤーが右に移動中かどうか 
	bool isGravityUpward_ =false; // プレイヤーが上に重力を受けているかどうか
	bool isOnGround_ = false;
	bool isLoopWaiting_ = false;
	float loopWaitStartTime_ = 0.0f;
	float loopedVelocityY_ = 0.0f;
	float fallingSpeed_ ; // 落下速度

};