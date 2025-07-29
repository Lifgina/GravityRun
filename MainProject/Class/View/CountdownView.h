#pragma once

#include "../../HuEngine.h"

class CountdownView {
public:
	void Load();
	void Initialize();
	void ShowCountDown();
	void ShowStart();
	void HideCountDown() { countdownSprite_.SetHidden(true); } // カウントダウンを非表示にする
	int GetCurrentFrame() const { return countdownSprite_.anim.drawRectAnim._currentFrame; } // 現在のフレームを取得


private:
	HE::Sprite countdownSprite_; // カウントダウン用のスプライト
};