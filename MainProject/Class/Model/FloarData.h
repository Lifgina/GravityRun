#pragma once

#include "../../HuEngine.h"

using namespace HE::Math;

class FloorData {
public:
	Vector2 GetFloorPosition(int floorID) const { return floorPosition_[floorID]; }
	int GetFloorHeight(int floorID) const { return floorHeight_[floorID]; }
	int GetFloorWidth(int floorID) const { return floorWidth_[floorID]; }

private:

	// �����`���邽�߂̃f�[�^
	// ���₷�����邽�߂ɉ��s�����Ă��邾���ŁA���ۂ̏����ɂ͉e�����Ȃ��B

	// ���̈ʒu
	Vector2 floorPosition_[11] =
	{Vector2(0.0f,0.0f),    Vector2(512.0f,0.0f),  Vector2(1024.0f,0.0f),
	 Vector2(256.0f,177.5f),Vector2(768.0f,177.5f),
	 Vector2(384.0f,355.0f),
	 Vector2(256.0f,532.5f),Vector2(768.0f,532.5f),
	 Vector2(0.0f,710.0f),  Vector2(512.0f,710.0f),Vector2(1024.0f,710.0f)
	 }; 


	// ���̍���
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
	 256.0f,256.0f,256.0f}; // ���̕�
	
};