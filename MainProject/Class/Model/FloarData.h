#pragma once

#include "../../HuEngine.h"

class FloorData {
public:
	void Load();

private:
	float floorHeight_ = 10.0f; //床の厚さ
	float floorPosition_Y_[3] = { 300.0f,600.0f,900.0f }; //床の上端の位置
	float floorEdgePosition_X_[3] = { 0.0f, 400.0f, 800.0f }; //床の左端の位置
};