#pragma once

#include "../../HuEngine.h"

class PlayerModel {
public:
	void Load();
	void Initialize();
	void Update();


private:
	HE::Sprite draftSprite_;
	HE::Math::Vector2 playerposition_;

};