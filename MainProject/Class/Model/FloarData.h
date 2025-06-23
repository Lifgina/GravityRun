#pragma once

#include "../../HuEngine.h"

using namespace HE::Math;

class FloorData {
public:
	Vector2 GetFloorPosition(int floorID) const { return floorPosition_[floorID]; }
	int GetFloorHeight(int floorID) const { return floorHeight_[floorID]; }
	int GetFloorWidth(int floorID) const { return floorWidth_[floorID]; }

private:

	// 床を定義するためのデータ
	// 見やすくするために改行を入れているだけで、実際の処理には影響しない。

	// 床の位置
	Vector2 floorPosition_[11] =
	{Vector2(0.0f,0.0f),    Vector2(512.0f,0.0f),  Vector2(1024.0f,0.0f),
	 Vector2(256.0f,177.5f),Vector2(768.0f,177.5f),
	 Vector2(384.0f,355.0f),
	 Vector2(256.0f,532.5f),Vector2(768.0f,532.5f),
	 Vector2(0.0f,710.0f),  Vector2(512.0f,710.0f),Vector2(1024.0f,710.0f)
	 }; 


	// 床の高さ
	float floorHeight_[11] = 
	{ 10.0f, 10.0f, 10.0f, 
	  10.0f, 10.0f,
	  10.0f,
	  10.0f, 10.0f,
	  10.0f, 10.0f, 10.0f }; 

	float floorWidth_[11] = 
	{256.0f,256.0f,256.0f,
	 256.0f,256.0f,
	 512.0f,
	 256.0f,256.0f,
	 256.0f,256.0f,256.0f}; // 床の幅
	
};