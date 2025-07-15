//
// SuitonEnemyView.cpp
//

#include "SuitonEnemyView.h"

using namespace HE;

void SuitonEnemyView::Load()
{
	suitonEnemySprite_ = HE::Sprite("SuitonEnemy.png");
	suitonEnemyAttackSprite_ = HE::Sprite("suiton.png");
}

void SuitonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos,float attackDirection)
{
	suitonEnemySprite_.params.pos = ninjaPos; // 水遁の術の敵の初期位置を設定
	suitonEnemySprite_.params.siz = Math::Vector2(64.0f, 64.0f); // 水遁の術の敵のサイズを設定
	suitonEnemyAttackSprite_.params.pos = attackPos; // 水遁の術の攻撃の初期位置を設定
	if (attackDirection == 1) {
		suitonEnemyAttackSprite_.params.enableMirror(); // 攻撃方向が右の場合、スプライトを反転
	}
	else if(attackDirection==-1) {
		suitonEnemyAttackSprite_.params.disableMirror(); // 攻撃方向が左の場合、スプライトを反転しない
	}
	suitonEnemyAttackSprite_.params.siz = Math::Vector2(1280.0f, 132.0f); // 水遁の術の攻撃のサイズを設定
	RenderingPath->AddSprite(&suitonEnemySprite_, 10); // 水遁の術の敵のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&suitonEnemyAttackSprite_, 0); // 水遁の術の攻撃のスプライトをレンダリングパスに追加
}

void SuitonEnemyView::Update(bool isActive, int suitonEnemyState)
{
	if (!isActive) {
		suitonEnemySprite_.SetHidden(true);
		suitonEnemyAttackSprite_.SetHidden(true);
	}
	else {
		switch (suitonEnemyState)
		{
		case 0: // 待機状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		case 1: // 攻撃状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(false);
			break;
		case 2: // 攻撃後状態
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		}
	
	}
}