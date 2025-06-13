//
// FloarData.cpp
//

#include "FloarData.h"

using namespace HE;

void FloorData::Load()
{
	for (int i = 0; i < floorNum_ ; ++i) {
		draftSprite_[i] = HE::Sprite("");
		if (i < 3) {
			draftSprite_[i].params.siz = Math::Vector2(200, floorHeight_);
			draftSprite_[i].params.pos = Math::Vector2(floorEdgePosition_X_[0][i*2], floorPosition_Y_[0]);
		}
		else if (i < 4) {
			draftSprite_[i].params.siz = Math::Vector2(680, floorHeight_);
			draftSprite_[i].params.pos = Math::Vector2(floorEdgePosition_X_[1][(i - 4+3)*2], floorPosition_Y_[1]);
		}
		else {
			draftSprite_[i].params.siz = Math::Vector2(300, floorHeight_);
			draftSprite_[i].params.pos = Math::Vector2(floorEdgePosition_X_[2][(i - 5+2)*2], floorPosition_Y_[2]);
		}
		RenderingPath->AddSprite(&draftSprite_[i], 0);
	}
}
