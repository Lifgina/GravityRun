#pragma once

#include "../../HuEngine.h"

class MarkerView {
public:
	void Load();
	void UpdateMarker(HE::Math::Vector2 pos);
	void MarkerDelete();

private:
	HE::Sprite markerSprite_; // マーカーのスプライト
};