#pragma once

#include "../../HuEngine.h"

using namespace HE::Math;

class FloorData {
public:
	Vector2 GetFloorPosition(int floorID) const { return floorPosition_[floorID]; }
	int GetFloorHeight(int floorID) const { return floorHeight_[floorID]; }
	int GetFloorWidth(int floorID) const { return floorWidth_[floorID]; }
	float GetBreakTime(int floorID) const { return breakTime_[floorID]; }
	int GetFloorCount() const { return floorCount_; }
	bool GetIsBreakable(int floorID) const { return isBreakable_[floorID]; }

private:

	// �����`���邽�߂̃f�[�^
	// ���₷�����邽�߂ɉ��s�����Ă��邾���ŁA���ۂ̏����ɂ͉e�����Ȃ��B

	int floorCount_ = 26; // ���̐�
	// ���̈ʒu
	Vector2 floorPosition_[26] =
	{ Vector2(40.0f,0.0f),  Vector2(440.0f,0.0f),Vector2(540.0f,0.0f),Vector2(640.0f,0.0f),Vector2(740.0f,0.0f),
	 Vector2(40.0f,175.0f),Vector2(140.0f,175.0f),Vector2(240.0f,175.0f),Vector2(340.0f,175.0f),Vector2(940.0f,175.0f),Vector2(1040.0f,175.0f),
	 Vector2(40.0f,350.0f), Vector2(240.0f,350.0f),Vector2(640.0f,350.0f),Vector2(740.0f,350.0f),
	Vector2(40.0f,525.0f),Vector2(140.0f,525.0f),Vector2(240.0f,525.0f),Vector2(340.0f,525.0f),Vector2(1040.0f,525.0f),Vector2(1140.0f,525.0f),
	Vector2(40.0f,700.0f),  Vector2(440.0f,700.0f),Vector2(540.0f,700.0f),Vector2(640.0f,700.0f),Vector2(740.0f,700.0f),
	};


	// ���̍���
	float floorHeight_[26] ={ 
	20.0f,20.0f,20.0f,20.0f,20.0f,
	20.0f,20.0f,20.0f,20.0f,20.0f,20.0f,
	20.0f,20.0f,20.0f,20.0f,
	20.0f,20.0f,20.0f,20.0f,20.0f,20.0f,
	20.0f,20.0f,20.0f,20.0f,20.0f
	};

	// ���̕�
	float floorWidth_[26] ={
     400.0f,100.0f,100.0f,100.0f,400.0f,
	 100.0f,100.0f,100.0f,600.0f,100.0f,200.0f,
	 100.0f,400.0f,100.0f,400.0f,
	 100.0f,100.0f,100.0f,700.0f,100.0f,100.0f,
	 400.0f,100.0f,100.0f,100.0f,400.0f,
	};

	// �������邩�ǂ���
	bool isBreakable_[26] =
	{
		false,true,false,true,false,
		true,false, true,false,true,false,
		false,false,true,false,
		true,false,true,false,true,false,
		false,true,false,true,false
	};

	//�������鎞��
	float breakTime_[26] = {
		0.0f, 10.0f, 0.0f, 30.0f, 0.0f,
		10.0f, 0.0f, 30.0f, 0.0f, 10.0f,0.0f,
		0.0f, 0.0f, 10.0f, 0.0f, 
		10.0f, 0.0f, 30.0f, 0.0f, 10.0f,0.0f,
		0.0f, 10.0f, 0.0f, 30.0f, 0.0f
	};

};