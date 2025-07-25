#pragma once

#include "../../HuEngine.h"

class TitleBG {
public:
	void Load();
	void Initialize();



private:
	HE::Sprite backgroundSprite_; // 背景のスプライト
	HE::Sprite ruleButtonSprite_; // ルールボタンのスプライト
	HE::Sprite startButtonSprite_; // スタートボタンのスプライト
	HE::Sprite exitButtonSprite_; // 終了ボタンのスプライト
};