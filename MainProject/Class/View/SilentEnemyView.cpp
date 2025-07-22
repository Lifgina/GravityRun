//
// SilentEnemyView.cpp
//

#include "SilentEnemyView.h"

using namespace HE;

void SilentEnemyView::Load()
{
	silentEnemySprite_ = HE::Sprite("makibisi.png"); // まきびしのスプライトを読み込む
	RenderingPath->AddSprite(&silentEnemySprite_, 10); // スプライトをレンダリングパスに追加
}

void SilentEnemyView::Initialize(Math::Vector2 pos, float spriteDirection)
{
	silentEnemySprite_.params.siz = Math::Vector2(spriteWidth_, spriteHeight_); // まきびしのサイズを設定
	silentEnemySprite_.params.pos = pos+Math::Vector2(-8,-2); // まきびしの位置を設定
	if (spriteDirection == -1) {
		silentEnemySprite_.params.scale.y = -1; // まきびしの向きを下向きに設定
		silentEnemySprite_.params.pos.y += spriteHeight_; // 位置を調整
	}

}
void SilentEnemyView::Update(bool isActive)
{
	silentEnemySprite_.SetHidden(!isActive); // まきびしの表示/非表示を切り替える
}
