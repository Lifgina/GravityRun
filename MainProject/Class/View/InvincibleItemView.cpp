//
// InvincibleItemView.cpp
//

#include "InvincibleItemView.h"

using namespace HE;

void InvincibleItemView::Load()
{
	invincibleItemSprite_ = HE::Sprite("makimono.png");
	RenderingPath->AddSprite(&invincibleItemSprite_, 40); // 無敵アイテムのスプライトをレンダリングパスに追加
}

void InvincibleItemView::Initialize()
{
	invincibleItemSprite_.params.siz = HE::Math::Vector2(155.0f, 155.0f); // 無敵アイテムのサイズを設定


}

void InvincibleItemView::Update(HE::Math::Vector2 itemPos,bool isActive)
{
	invincibleItemSprite_.SetHidden(!isActive); 
	invincibleItemSprite_.params.pos = itemPos; // 無敵アイテムの位置を設定
}

