//
// JutsuEnemy.cpp
//

#include "JutsuEnemy.h"

using namespace HE;

void JutsuEnemy::Load()
{

}

void JutsuEnemy::Initialize(HE::Math::Vector2 enemyPos, float collisionHeight, float collisonWidth)
{
	enemyPosition_ = enemyPos; // 敵の初期位置を設定
	collisionHeight_ = collisionHeight; // 敵の衝突判定の高さを設定
	collisionWidth_ = collisonWidth; // 敵の衝突判定の幅を設定
	isActive_ = false; // 敵は初期状態では非アクティブ
	jutsuEnemyState_ = 0; // 敵の状態を待機に設定
}

void JutsuEnemy::Update(float timer)
{
	if (!isActive_) return;

	// 敵がアクティブな場合の処理
	switch (jutsuEnemyState_)
	{
	case 0: // 待機状態
		if (timer - activateTime_ >= timeToAttack_) {
			jutsuEnemyState_ = 1; // 攻撃状態に移行
		}
		break;
	case 1: // 攻撃状態
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_) {
			jutsuEnemyState_ = 2; // 攻撃後状態に移行
		}
		break;
	case 2: // 攻撃後状態
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_ + attackAfterTime_) {
			isActive_ = false; // 敵を非アクティブにする
			jutsuEnemyState_ = 0; // 状態を待機に戻す
		}
		break;

	}


}

void JutsuEnemy::Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime)
{
	if (!isActive_) {
		isActive_ = true; // 敵をアクティブにする
		activateTime_ = timer; // アクティブになった時間を記録
		timeToAttack_ = timeToAttack; // 攻撃までの時間を設定
		attackDuration_ = attackDuration; // 攻撃の持続時間を設定
		attackAfterTime_ = attackAfterTime; // 攻撃後の待機時間を設定
	}
}

Math::Rectangle JutsuEnemy::GetCollision()
{
	if (isActive_&&jutsuEnemyState_==1) {
		Math::Rectangle collision;
		collision.x = enemyPosition_.x;
		collision.y = enemyPosition_.y;
		collision.width = collisionWidth_;
		collision.height = collisionHeight_;
		return collision; // 敵がアクティブで攻撃状態の場合、衝突判定を返す
	}
}