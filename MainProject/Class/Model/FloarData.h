#pragma once

#include "../../HuEngine.h"

class FloorData {
public:
	int GetFloorHeight() const {return floorHeight_;}
	int GetFloorPosition_Y(int line) const { return floorPosition_Y_[line]; }
	int GetFloorEdgePosition_X(int line,int num) const {return floorEdgePosition_X_[line][num];}

	void Load();

private:
	int floorNum_ = 6; // 床の数
	HE::Sprite draftSprite_[6]; // 床のスプライト。実際にある床の数を[]の中に記入
	float floorHeight_ = 10.0f; //床の厚さ
	float floorPosition_Y_[3] = { 200.0f,400.0f,600.0f }; //床の上端の位置
	float floorEdgePosition_X_[3][6] = {
	{0.0f,200.0f,400.0f,600.0f,800.0f,1000.0f},
	{-1,-1,-1,-1,300.0f,980.0f,},
	{-1,-1,300.0f,600.0f,900.0f,1200.0f} };
	//床の端の位置(前者:床が縦に並ぶ個数,後者:端として設定する最大数)
	//(行によって床の数を減らす場合は前に画面外の座標を指定)
};