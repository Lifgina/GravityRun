//
// FusumaView.cpp
//

#include "FusumaView.h"

using namespace HE;

void FusumaView::Load(int husumaPattern, int husumaColor)
{
	switch (husumaColor)
	{
	case 0:
		fusumaBackgroundSprite_ = HE::Sprite("fusuma_red.png");
		break;
	case 1:
		fusumaBackgroundSprite_ = HE::Sprite("fusuma_blue.png");
		break;
	}
	switch (husumaPattern)
	{
	case 0:
		fusumaSprite_ = HE::Sprite("husuma_kawa.png");
		break;
	case 1:
		fusumaSprite_ = HE::Sprite("husuma_koi.png");
		break;
	case 2:
		fusumaSprite_ = HE::Sprite("husuma_matu.png");
		break;
	}
	fusumaSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 256.0f, 256.0f
	));
	fusumaSprite_.params.siz = Math::Vector2(fusumaWidth_, fusumaHeight_); // ふすまのサイズを設定
	fusumaBackgroundSprite_.params.siz = Math::Vector2((fusumaWidth_/2)-2.5, (fusumaHeight_/2)-5); // ふすまの背景のサイズを設定
	RenderingPath->AddSprite(&fusumaBackgroundSprite_, -990); // ふすまの背景スプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&fusumaSprite_, 30); // ふすまのスプライトをレンダリングパスに追加
}

void FusumaView::Initialize(Math::Vector2 fusumaPos)
{
	fusumaSprite_.params.pos = fusumaPos; // ふすまの位置を設定
	fusumaBackgroundSprite_.params.pos = fusumaPos+Math::Vector2(65.0f,132.5f); // ふすまの背景の位置を設定
	// アニメーションの設定
	fusumaSprite_.anim = Sprite::Anim();
	fusumaSprite_.anim.repeatable = false; // ループするかしないか
	fusumaSprite_.anim.drawRectAnim.frameRate = 0;
	fusumaSprite_.anim.drawRectAnim.frameCount = 6;             // 画像にアニメーションが何コマあるか
	fusumaSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数
}

void FusumaView::FusumaMove(bool isOpened)
{
	fusumaSprite_.anim.drawRectAnim.frameRate = 24;
	
	if(isOpened){
		fusumaSprite_.params.drawRect.x = 0.0f;
		fusumaSprite_.params.drawRect.y = 0.0f;
		fusumaSprite_.anim.drawRectAnim._currentFrame = 0; // アニメーションのフレームをリセット
		fusumaSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // アニメーションの経過時間をリセット
	}
	else{
		fusumaSprite_.params.drawRect.x = 0.0f;
		fusumaSprite_.params.drawRect.y = 256.0f;
		fusumaSprite_.anim.drawRectAnim._currentFrame = 0; // アニメーションのフレームをリセット
		fusumaSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // アニメーションの経過時間をリセット
		
	}
	

}

