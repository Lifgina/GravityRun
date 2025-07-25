//
// SuitonEnemyView.cpp
//

#include "SuitonEnemyView.h"

using namespace HE;

void SuitonEnemyView::Load()
{
	suitonEnemySprite_ = HE::Sprite("SuitonEnemy.png");
	suitonEnemyAttackSprite_ = HE::Sprite("suiton.png");
	suitonHitRangeSprite_ = HE::Sprite("hit_blue.png"); // 水遁の術の攻撃のヒット範囲のスプライトを読み込み
	RenderingPath->AddSprite(&suitonEnemySprite_, 110); // 水遁の術の敵のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&suitonEnemyAttackSprite_, 100); // 水遁の術の攻撃のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&suitonHitRangeSprite_, 90); // 水遁の術の攻撃のヒット範囲のスプライトをレンダリングパスに追加
}

void SuitonEnemyView::Initialize(Math::Vector2 ninjaPos,float attackDirection,Math::Vector2 attackPos)
{
	suitonEnemySprite_.params.pos = ninjaPos; // 水遁の術の敵の初期位置を設定
	suitonHitRangeSprite_.params.pos = attackPos; // 水遁の術の攻撃のヒット範囲の初期位置を設定
	suitonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // 水遁の術の敵のサイズを設定
	if (attackDirection == 1) {
		suitonEnemyAttackSprite_.params.enableMirror(); // 攻撃方向が右の場合、スプライトを反転
	}
	else if(attackDirection==-1) {
		suitonEnemyAttackSprite_.params.disableMirror(); // 攻撃方向が左の場合、スプライトを反転しない
	}
	suitonEnemyAttackSprite_.params.siz = Math::Vector2(1280.0f, 150.0f); // 水遁の術の攻撃のサイズを設定
	suitonHitRangeSprite_.params.siz = Math::Vector2(1200.0f, 161.0f);  // 水遁の術の攻撃のヒット範囲のサイズを設定

}


void SuitonEnemyView::Update(bool isActive, int suitonEnemyState,Math::Vector2 suitonAttackPos)
{
	suitonEnemyAttackSprite_.params.pos = suitonAttackPos;
	if (!isActive) {
		suitonEnemySprite_.SetHidden(true);
		suitonEnemyAttackSprite_.SetHidden(true);
		suitonHitRangeSprite_.SetHidden(true); // 水遁の術の攻撃のヒット範囲を非表示にする
	}
	else {
		switch (suitonEnemyState)
		{
		case 0: // 待機状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			suitonHitRangeSprite_.SetHidden(false); // 水遁の術の攻撃のヒット範囲を表示する
			break;
		case 1: // 攻撃状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(false);
			suitonHitRangeSprite_.SetHidden(true); 
			break;
		case 2: // 攻撃後状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			suitonHitRangeSprite_.SetHidden(true); 
			break;
		}
	
	}
}