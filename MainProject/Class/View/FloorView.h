#pragma once

#include "../../HuEngine.h"

class FloorView {
public:
	void Load(bool isBreakable);
	void Initialize(HE::Math::Vector2 floorpos,float floorHeight,float floorWidth);
	void FloorBreak();


private:
	HE::Sprite floorSprite_; // 床のスプライト
};