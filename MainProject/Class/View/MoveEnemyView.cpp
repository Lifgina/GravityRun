//
// MoveEnemyView.cpp
//

#include "MoveEnemyView.h"

using namespace HE;

void MoveEnemyView::Load()
{
	moveEnemySprite_ = HE::Sprite("syuriken.png");
	RenderingPath->AddSprite(&moveEnemySprite_, 100); // スプライトをレンダリングパスに追加
}

void MoveEnemyView::Initialize(Math::Vector2 initialPos,float appearTime)
{
	apeearTime_ = appearTime; // 敵が表示されるまでの時間を設定
	moveEnemySprite_.params.pos = initialPos; // 初期位置を設定
	moveEnemySprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_); // サイズを設定
	moveEnemySprite_.SetHidden(true); // 初期状態では非表示にする

	moveEnemySprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); 
	// アニメーションの設定
	moveEnemySprite_.anim = Sprite::Anim();
	moveEnemySprite_.anim.repeatable = true;                       // ループするかしないか
	moveEnemySprite_.anim.drawRectAnim.frameRate = 0;             // アニメーションの速度
	moveEnemySprite_.anim.drawRectAnim.frameCount = 5;             // 画像にアニメーションが何コマあるか
	moveEnemySprite_.anim.drawRectAnim.horizontalFrameCount = 5;   // 横に並んでいるコマ数
	
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
		moveEnemySprite_.anim.drawRectAnim.frameRate = 20;             // アニメーションの速度
		moveEnemySprite_.params.pos = enemyPos; // 敵の位置を更新
	}

	
	
}