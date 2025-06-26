#pragma once

#include "../../HuEngine.h"

class FloorModel {
public:

	void Initialize(HE::Math::Vector2 floorPosition,float floorWidth,float floorHeight,bool isBreakable);
	HE::Math::Vector2 GetFloorPosition() const { return floorPosition_; } // °‚ÌˆÊ’u‚ğæ“¾
	float GetFloorWidth() const { return floorWidth_; } // °‚Ì•‚ğæ“¾
	float GetFloorHeight() const { return floorHeight_; } // °‚Ì‚‚³‚ğæ“¾
	HE::Math::Rectangle GetCollision();
	void BreakFloor();

private:

	bool isBreakable_ ; // °‚ª‰ó‚ê‚é‚©‚Ç‚¤‚©
	bool isBroken_ ; // °‚ª‰ó‚ê‚½‚©‚Ç‚¤‚©

	int touchCountToBreak_=2; 
	int touchCount_;

	HE::Sprite draftSprite_; 
	HE::Math::Vector2 floorPosition_; // °‚ÌˆÊ’u
	float floorWidth_; // °‚Ì•
	float floorHeight_; // °‚Ì‚‚³
};