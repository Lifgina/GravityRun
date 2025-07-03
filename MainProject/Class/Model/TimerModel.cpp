//
// TimerModel.cpp
//

#include "TimerModel.h"

using namespace HE;


void TimerModel::Initialize(float timeLimit)
{
	timer_ = 0.0f; // �^�C�}�[�̏�����
	timeLimit_ = timeLimit; // �^�C�����~�b�g�̐ݒ�
}

void TimerModel::Update()
{
	timer_ += Time.deltaTime; // �^�C�}�[���X�V
}
