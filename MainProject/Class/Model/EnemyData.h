#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
	// 敵の位置を取得
	HE::Math::Vector2 GetSilentEnemyPosition(int index) const { return SilentenemyPosition_[index]; }
	HE::Math::Vector2 GetMoveEnemyPosition(int index) const { return moveEnemyPosition_[index]; }
	// 敵の向きを取得
	float GetSilentEnemyDirection(int index) const { return silentEnemyDirection_[index]; }
	float GetMoveEnemyDirection(int index) const { return moveEnemyDirection_[index]; }
	// 敵の移動速度を取得
	float GetMoveEnemySpeed(int index) const { return moveEnemySpeed_[index]; }
	// 敵の移動範囲を取得
	float GetMoveEnemyMinRange_X(int index) const { return moveEnemyMinRange_X_[index]; }
	float GetMoveEnemyMaxRange_X(int index) const { return moveEnemyMaxRange_X_[index]; }

	// 敵がアクティブになるまでの時間を取得
	float GetMoveEnemyTimeToActive(int index) const { return moveEnemyTimeToActive_[index]; }

private:
	int silentEnemyCount_ = 4; // まきびしの数 GameManager.hで定義されている敵の数に合わせる
	int MoveEnemyCount_ = 6; // 手裏剣の数 GameManager.hで定義されている敵の数に合わせる

	//まきびしのデータ
	// 敵の位置
	HE::Math::Vector2 SilentenemyPosition_[4] = {
		HE::Math::Vector2(1010.0-64.0f, 142.0f-64.0f),
		HE::Math::Vector2(460.0f-32.0f, 284.0f-64.0f),
		HE::Math::Vector2(310.0f-64.0f, 568.0f-64.0f),
		HE::Math::Vector2(900.0f+64.0f, 710.0f-64.0f),
	
	};
	//敵の向き　1:上向き　-1:下向き
	//View側で使用
	float silentEnemyDirection_[4] = {}; 

	//手裏剣のデータ
	// 敵の初期位置
	HE::Math::Vector2 moveEnemyPosition_[6] = {
		HE::Math::Vector2(1110.0f-64.0f, 142.0f-64.0f),
		HE::Math::Vector2(110.0f+64.0f ,  142.0f+10.0f),
		HE::Math::Vector2(310.0f + 64.0f,  284.0f+10.0f),
		HE::Math::Vector2(910.0f + 64.0f,  426.0f -64.0f),
		HE::Math::Vector2(110.0f + 64.0f,  568.0f - 64.0f),
		HE::Math::Vector2(1110.0f - 64.0f, 568.0f +10.0f),
	};
	float moveEnemyTimeToActive_[6] = {0,0,0,0,0,0}; // 敵がアクティブになるまでの時間
	// 敵の最初の向き　1:右向き　-1:左向き
	float moveEnemyDirection_[6] = {-1,1,1,-1,1,-1};
	// 敵の移動速度
	float moveEnemySpeed_[6] = {300.0f,300.0f,300.0f,300.0f,300.0f,300.0f};
	// 敵の移動範囲
	float moveEnemyMinRange_X_[6] = {10.0f,10.0f, 10.0f, 10.0f, 10.0f, 10.0f};
	float moveEnemyMaxRange_X_[6] = { 1146.0f , 1146.0f , 1146.0f , 1146.0f , 1146.0f , 1146.0f  };
	
};