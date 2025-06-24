#pragma once

#include "../../HuEngine.h"

using namespace HE::Math;

class FloorData {
public:
	Vector2 GetFloorPosition(int floorID) const { return floorPosition_[floorID]; }
	int GetFloorHeight(int floorID) const { return floorHeight_[floorID]; }
	int GetFloorWidth(int floorID) const { return floorWidth_[floorID]; }
	int GetFloorCount() const { return floorCount_; }

private:

	// 床を定義するためのデータ
	// 見やすくするために改行を入れているだけで、実際の処理には影響しない。

	int floorCount_ = 16; // 床の数
	// 床の位置
	Vector2 floorPosition_[16] =
	{Vector2(210.0f,0.0f),  Vector2(910.0f,0.0f),  
	 Vector2(110.0f,142.0f),Vector2(610.0f,142.0f),Vector2(1110.0f,142.0f),
	 Vector2(10.0f,284.0f), Vector2(310.0f,284.0f),Vector2(810.0f,284.0f),
	 Vector2(110.0f,426.0f),Vector2(510.0f,426.0f),Vector2(910.0f,426.0f),
	 Vector2(10.0f,568.0f), Vector2(210.0f,568.0f),Vector2(710.0f,568.0f),
	 Vector2(210.0f,710.0f),Vector2(910.0f,710.0f),
	 }; 


	// 床の高さ
	float floorHeight_[16] = 
	{ 10.0f, 10.0f, 
	  10.0f, 10.0f,10.0f,
	  10.0f, 10.0f,10.0f,
	  10.0f, 10.0f,10.0f,
	  10.0f, 10.0f,10.0f,
	  10.0f, 10.0f, }; 

	float floorWidth_[16] = 
	{500.0f,300.0f,
	 400.0f,400.0f,100.0f,
	 100.0f,400.0f,300.0f,
	 300.0f,300.0f,300.0f,
	 100.0f,400.0f,300.0f,
	 500.0f,300.0f,}; // 床の幅
	
};