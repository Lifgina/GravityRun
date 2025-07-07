#pragma once

#include "../../HuEngine.h"

class Pillar {
public:
	void Load();
	void Initialize();


private:
	HE::Sprite pillarSprite_1_; // 柱のスプライト
	HE::Sprite pillarSprite_2_; // 柱のスプライト
};