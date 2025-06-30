//
// MoveEnemyView.cpp
//

#include "MoveEnemyView.h"

using namespace HE;

void MoveEnemyView::Load()
{
	moveEnemySprite_ = HE::Sprite("");
	moveEnemySprite_.params.color = HE::Color(0, 255, 0, 255); // 緑色のスプライト
	RenderingPath->AddSprite(&moveEnemySprite_, 0); // スプライトをレンダリングパスに追加
}

void MoveEnemyView::Initialize(Math::Vector2 initialPos,float appearTime)
{
	apeearTime_ = appearTime; // 敵が表示されるまでの時間を設定
	moveEnemySprite_.params.pos = initialPos; // 初期位置を設定
	moveEnemySprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_); // サイズを設定
	moveEnemySprite_.params.color = HE::Color(0, 255, 0, 255); // 緑色のスプライト
	moveEnemySprite_.SetHidden(true); // 初期状態では非表示にする
}

void MoveEnemyView::Update(Math::Vector2 enemyPos,float time)
{
	if (time < apeearTime_-apeearBafa_) {
		moveEnemySprite_.SetHidden(true); // 指定時間が経過するまで非表示
	}
	else{
		moveEnemySprite_.SetHidden(false); // 指定時間が経過したら表示
	}

	if (apeearTime_ <= time) {
		moveEnemySprite_.params.pos = enemyPos; // 敵の位置を更新
	}

	
	
}