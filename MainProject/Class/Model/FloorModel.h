#pragma once

#include "../../HuEngine.h"

class FloorModel {
public:

	void Initialize(HE::Math::Vector2 floorPosition,float floorWidth,float floorHeight);
	HE::Math::Vector2 GetFloorPosition() const { return floorPosition_; } // ���̈ʒu���擾
	float GetFloorWidth() const { return floorWidth_; } // ���̕����擾
	float GetFloorHeight() const { return floorHeight_; } // ���̍������擾
	HE::Math::Rectangle GetCollision();


private:
	HE::Sprite draftSprite_; 
	HE::Math::Vector2 floorPosition_; // ���̈ʒu
	float floorWidth_; // ���̕�
	float floorHeight_; // ���̍���
};