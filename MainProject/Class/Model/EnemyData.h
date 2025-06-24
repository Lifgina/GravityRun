#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
	// 敵の位置を取得
	HE::Math::Vector2 GetSilentEnemyPosition(int index) const { return SilentenemyPosition_[index]; }
	HE::Math::Vector2 GetMoveEnemyPosition(int index) const { return MoveEnemyPosition_[index]; }
	// 敵の向きを取得
	float GetSilentEnemyDirection(int index) const { return silentEnemyDirection_[index]; }
	float GetMoveEnemyDirection(int index) const { return MoveEnemyDirection_[index]; }
	// 敵の移動速度を取得
	float GetMoveEnemySpeed(int index) const { return MoveEnemySpeed_[index]; }
	// 敵の移動範囲を取得
	float GetMoveEnemyMinRange_X(int index) const { return MoveEnemyMinRange_X_[index]; }
	float GetMoveEnemyMaxRange_X(int index) const { return MoveEnemyMaxRange_X_[index]; }

private:
	int silentEnemyCount_ = 7;
	int MoveEnemyCount_ = 0;

	//まきびしのデータ
	// 敵の位置
	HE::Math::Vector2 SilentenemyPosition_[7] = {
		HE::Math::Vector2(100.0f, 100.0f),
		HE::Math::Vector2(200.0f, 200.0f),
		HE::Math::Vector2(300.0f, 300.0f),
		HE::Math::Vector2(400.0f, 400.0f),
		HE::Math::Vector2(500.0f, 500.0f),
		HE::Math::Vector2(600.0f, 600.0f),
		HE::Math::Vector2(700.0f, 700.0f)
	
	};
	//敵の向き　1:上向き　-1:下向き
	//View側で使用
	float silentEnemyDirection_[7] = {}; 

	//手裏剣のデータ
	// 敵の初期位置
	HE::Math::Vector2 MoveEnemyPosition_[1] = {

	};
	// 敵の最初の向き　1:右向き　-1:左向き
	float MoveEnemyDirection_[7] = {};
	// 敵の移動速度
	float MoveEnemySpeed_[7] = {};
	// 敵の移動範囲
	float MoveEnemyMinRange_X_[7] = {};
	float MoveEnemyMaxRange_X_[7] = {};
	
};