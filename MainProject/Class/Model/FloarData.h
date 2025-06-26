#pragma once

#include "../../HuEngine.h"

using namespace HE::Math;

class FloorData {
public:
	Vector2 GetFloorPosition(int floorID) const { return floorPosition_[floorID]; }
	int GetFloorHeight(int floorID) const { return floorHeight_[floorID]; }
	int GetFloorWidth(int floorID) const { return floorWidth_[floorID]; }
	int GetFloorCount() const { return floorCount_; }
	bool GetIsBreakable(int floorID) const { return isBreakable_[floorID]; }

private:

	// �����`���邽�߂̃f�[�^
	// ���₷�����邽�߂ɉ��s�����Ă��邾���ŁA���ۂ̏����ɂ͉e�����Ȃ��B

	int floorCount_ =23; // ���̐�
	// ���̈ʒu
	Vector2 floorPosition_[23] =
	{Vector2(210.0f,0.0f),  Vector2(910.0f,0.0f),  
	 Vector2(110.0f,142.0f),Vector2(510.0f,142.0f),Vector2(610.0f,142.0f),Vector2(1110.0f,142.0f),
	 Vector2(10.0f,284.0f), Vector2(210.0f,142.0f),Vector2(310.0f,284.0f),Vector2(710.0f,284.0f),Vector2(810.0f,284.0f),
	 Vector2(110.0f,426.0f),Vector2(410.0f,426.0f),Vector2(510.0f,426.0f),Vector2(810.0f,426.0f),Vector2(910.0f,426.0f),
	 Vector2(10.0f,568.0f), Vector2(110.0f,568.0f),Vector2(210.0f,568.0f),Vector2(610.0f,568.0f),Vector2(710.0f,568.0f),
	 Vector2(210.0f,710.0f),Vector2(910.0f,710.0f),
	 }; 


	// ���̍���
	float floorHeight_[23] = 
	{ 10.0f, 10.0f, 
	  10.0f, 10.0f,10.0f,10.0f,
	  10.0f, 10.0f,10.0f,10.0f,10.0f,
	  10.0f, 10.0f,10.0f,10.0f,10.0f,
	  10.0f, 10.0f,10.0f,10.0f,10.0f,
	  10.0f, 10.0f, }; 

	// ���̕�
	float floorWidth_[23] = 
	{500.0f,300.0f,
	 400.0f,100.0f,400.0f,100.0f,
	 200.0f,100.0f,400.0f,100.0f,300.0f,
	 300.0f,100.0f,300.0f,100.0f,300.0f,
	 100.0f,100.0f,400.0f,100.0f,400.0f,
	 500.0f,300.0f,}; 

	// �������邩�ǂ���
	bool isBreakable_[23] =
	{
		false, false,
		false, true,false,false,
		false,true,false,true,false,
		false,true,false,true,false,
        false,true,false,true,false,
		false,false,
	};
	
};