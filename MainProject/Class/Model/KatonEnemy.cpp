//
// KatonEnemy.cpp
//

#include "KatonEnemy.h"

using namespace HE;

void KatonEnemy::Load()
{

}

void KatonEnemy::Initialize(HE::Math::Vector2 enemyPos, float collisionHeight, float collisonWidth)
{
	enemyPosition_ = enemyPos; // 敵の初期位置を設定
	collisionHeight_ = collisionHeight; // 敵の衝突判定の高さを設定
	collisionWidth_ = collisonWidth; // 敵の衝突判定の幅を設定
	isActive_ = false; // 敵は初期状態では非アクティブ
	katonEnemyState_ = 0; // 敵の状態を待機に設定
}

void KatonEnemy::Update(float timer)
{
	if (!isActive_) return;

	// 敵がアクティブな場合の処理
	switch (katonEnemyState_)
	{
	case 0: // 待機状態
		if (timer - activateTime_ >= timeToAttack_) {
			katonEnemyState_ = 1; // 攻撃状態に移行
		}
		break;
	case 1: // 攻撃状態
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_) {
			katonEnemyState_ = 2; // 攻撃後状態に移行
		}
		break;
	case 2: // 攻撃後状態
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_ + attackAfterTime_) {
			isActive_ = false; // 敵を非アクティブにする
			katonEnemyState_ = 0; // 状態を待機に戻す
		}
		break;

	}


}

void KatonEnemy::Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime)
{
	if (!isActive_) {
		isActive_ = true; // 敵をアクティブにする
		activateTime_ = timer; // アクティブになった時間を記録
		timeToAttack_ = timeToAttack; // 攻撃までの時間を設定
		attackDuration_ = attackDuration; // 攻撃の持続時間を設定
		attackAfterTime_ = attackAfterTime; // 攻撃後の待機時間を設定
	}
}

Math::Rectangle KatonEnemy::GetCollision()
{
	if (isActive_&&katonEnemyState_==1) {
		Math::Rectangle collision;
		collision.x = enemyPosition_.x;
		collision.y = enemyPosition_.y;
		collision.width = collisionWidth_;
		collision.height = collisionHeight_;
		return collision; // 敵がアクティブで攻撃状態の場合、衝突判定を返す
	}
}