#pragma once

#include "../../HuEngine.h"

class FloorModel {
public:

	void Initialize(HE::Math::Vector2 floorPosition,float floorWidth,float floorHeight,bool isBreakable,float breakTime);
	HE::Math::Vector2 GetFloorPosition() const { return floorPosition_; } // °‚ÌˆÊ’u‚ğæ“¾
	float GetFloorWidth() const { return floorWidth_; } // °‚Ì•‚ğæ“¾
	float GetFloorHeight() const { return floorHeight_; } // °‚Ì‚‚³‚ğæ“¾
	bool GetIsBroken() const { return isBroken_; } // °‚ª‰ó‚ê‚½‚©‚Ç‚¤‚©‚ğæ“¾
	HE::Math::Rectangle GetCollision();
	void Update(float timer);
	void BreakFloor();

private:

	bool isBreakable_ ; // °‚ª‰ó‚ê‚é‚©‚Ç‚¤‚©
	bool isBroken_ ; // °‚ª‰ó‚ê‚½‚©‚Ç‚¤‚©

	HE::Sprite draftSprite_; 
	HE::Math::Vector2 floorPosition_; // °‚ÌˆÊ’u
	float floorWidth_; // °‚Ì•
	float floorHeight_; // °‚Ì‚‚³
	float breakTime_; // °‚ª‰ó‚ê‚é‚Ü‚Å‚ÌŠÔ
};