//
// KatonEnemyView.cpp
//

#include "KatonEnemyView.h"

using namespace HE;

void KatonEnemyView::Load()
{
	katonEnemySprite_ = HE::Sprite("KatonEnemy.png");
	katonEnemyAttackSprite_ = HE::Sprite("katon.png");
	katonHitRangeSprite_ = HE::Sprite("hit_red.png");
	RenderingPath->AddSprite(&katonEnemySprite_, 110); // 火遁の術の敵のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&katonEnemyAttackSprite_, 100); // 火遁の術の攻撃のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&katonHitRangeSprite_, 90); // 火遁の術の攻撃のヒット範囲のスプライトをレンダリングパスに追加
}

void KatonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	katonEnemySprite_.params.pos = ninjaPos; // 火遁の術の敵の初期位置を設定
	katonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // 火遁の術の敵のサイズを設定
	katonEnemyAttackSprite_.params.pos = attackPos+Math::Vector2(-27.5f,0); // 火遁の術の攻撃の初期位置を設定
	katonEnemyAttackSprite_.params.siz = Math::Vector2(155.0f, 155.0f); // 火遁の術の攻撃のサイズを設定
	katonHitRangeSprite_.params.pos = attackPos; // 火遁の術の攻撃のヒット範囲の初期位置を設定
	katonHitRangeSprite_.params.siz = Math::Vector2(100.0f, 155.0f); // 火遁の術の攻撃のヒット範囲のサイズを設定

}

void KatonEnemyView::Update(bool isActive, int katonEnemyState)
{
	if (!isActive) {
		katonEnemySprite_.SetHidden(true);
		katonEnemyAttackSprite_.SetHidden(true);
		katonHitRangeSprite_.SetHidden(true); 
	}
	else {
		switch (katonEnemyState)
		{
		case 0: // 待機状態
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			katonHitRangeSprite_.SetHidden(false); 
			break;
		case 1: // 攻撃状態
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(false);
			katonHitRangeSprite_.SetHidden(true); 
			break;
		case 2: // 攻撃後状態
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			katonHitRangeSprite_.SetHidden(true);
			break;
		}
	
	}
}