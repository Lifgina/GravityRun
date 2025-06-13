#pragma once

#include "../../HuEngine.h"

class FloorData {
public:
	int GetFloorHeight() const {return floorHeight_;}
	int GetFloorPosition_Y(int line) const { return floorPosition_Y_[line]; }
	int GetFloorEdgePosition_X(int line,int num) const {return floorEdgePosition_X_[line][num];}

	void Load();

private:
	int floorNum_ = 6; // ���̐�
	HE::Sprite draftSprite_[6]; // ���̃X�v���C�g�B���ۂɂ��鏰�̐���[]�̒��ɋL��
	float floorHeight_ = 10.0f; //���̌���
	float floorPosition_Y_[3] = { 200.0f,400.0f,600.0f }; //���̏�[�̈ʒu
	float floorEdgePosition_X_[3][6] = {
	{0.0f,200.0f,400.0f,600.0f,800.0f,1000.0f},
	{-1,-1,-1,-1,300.0f,980.0f,},
	{-1,-1,300.0f,600.0f,900.0f,1200.0f} };
	//���̒[�̈ʒu(�O��:�����c�ɕ��Ԍ�,���:�[�Ƃ��Đݒ肷��ő吔)
	//(�s�ɂ���ď��̐������炷�ꍇ�͑O�ɉ�ʊO�̍��W���w��)
};