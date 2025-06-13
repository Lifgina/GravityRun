#pragma once

#include "../../HuEngine.h"
#include "FloarData.h"

class PlayerModel {
public:
	void Load(); //後でViewに移動し、プレイヤーの描画を記述
	void Initialize(HE::Math::Vector2 initialPos);//初期位置はGameManagerで定義
	void SetStageData();
	void Update();
	void UpdatePlayerSprite(); // プレイヤーのスプライトを更新する、後でViewに移動
	void PlayerMoveX();
	void PlayerMoveY();
	void GroundCheck(); // プレイヤーが床に接触しているかどうかを確認する
	void DirectionChange(); // プレイヤーの移動方向を変更する、後でMainSceneにスクリプトを移動


private:
	float playerSpeed_ = 300.0f; // プレイヤーの移動速度
	float gravity_ = 980.0f; // 重力の強さ


	//以下クラス内で使用する変数
	HE::Sprite draftSprite_;
	HE::Math::Vector2 playerPosition_;
	bool isMovingToRight_ = true; // プレイヤーが右に移動中かどうか 
	bool isGravityUpward_ =false; // プレイヤーが上に重力を受けているかどうか
	bool isOnGround_X_ ; // プレイヤーが床に接触しているかどうか
	bool isOnGround_Y_; 
	float fallingSpeed_ ; // 落下速度

	//以下FloorDataから読み込むデータを保存する変数。配列数はFloorDataの定義に合わせること
	FloorData floorData_; // 床のデータを管理するクラス
	int floorLines_ = 3; // 床の列の数、FloorDataの定義に合わせること
	int floorEdgeNum_ = 6; // 床の端の数、FloorDataの定義に合わせること
	float floorHeight_ ; // 床の厚さ
	float floorPosition_Y_[3]; 
	float floorEdgePosition_X_[3][6];

};