//
// SuitonEnemy.cpp
//

#include "SuitonEnemy.h"

using namespace HE;

void SuitonEnemy::Load()
{

}

void SuitonEnemy::Initialize(float enemyPosY, float collisionHeight, float collisionWidth,float attackDirection)
{
	attackDirection_ = attackDirection; // 攻撃の方向を設定（1: 右, -1: 左）
	if (attackDirection_ == 1) {
		enemyPosition_.x = -collisionWidth;
	}
	else if (attackDirection == -1) {
		enemyPosition_.x = RenderingPath->GetLogicalWidth();
	}
	enemyPosition_.y = enemyPosY; // 敵の初期位置を設定
	collisionHeight_ = collisionHeight; // 敵の衝突判定の高さを設定
	collisionWidth_ = collisionWidth; // 敵の衝突判定の幅を設定
	isActive_ = false; // 敵は初期状態では非アクティブ
	suitonEnemyState_ = 0; // 敵の状態を待機に設定
}

void SuitonEnemy::Update(float timer)
{
	if (!isActive_) return;

	// 敵がアクティブな場合の処理
	switch (suitonEnemyState_)
	{
	case 0: // 待機状態
		if (timer - activateTime_ >= timeToAttack_) {
			suitonEnemyState_ = 1; // 攻撃状態に移行
		}
		break;
	case 1: // 攻撃状態
		enemyPosition_.x += ((RenderingPath->GetLogicalWidth() + collisionWidth_) / attackDuration_) * attackDirection_ * Time.deltaTime;
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_) {	
			suitonEnemyState_ = 2; // 攻撃後状態に移行
		}
		break;
	case 2: // 攻撃後状態
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_ + attackAfterTime_) {
			isActive_ = false; // 敵を非アクティブにする
			suitonEnemyState_ = 0; // 状態を待機に戻す
		}
		break;

	}


}

void SuitonEnemy::Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime)
{
	if (!isActive_) {
		isActive_ = true; // 敵をアクティブにする
		activateTime_ = timer; // アクティブになった時間を記録
		timeToAttack_ = timeToAttack; // 攻撃までの時間を設定
		attackDuration_ = attackDuration; // 攻撃の持続時間を設定
		attackAfterTime_ = attackAfterTime; // 攻撃後の待機時間を設定
	}
}

Math::Rectangle SuitonEnemy::GetCollision()
{
	if (isActive_&&suitonEnemyState_==1) {
		Math::Rectangle collision;
		collision.x = enemyPosition_.x;
		collision.y = enemyPosition_.y;
		collision.width = collisionWidth_;
		collision.height = collisionHeight_;
		return collision; // 敵がアクティブで攻撃状態の場合、衝突判定を返す
	}
}