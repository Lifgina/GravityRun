//
// SEmanager.cpp
//

#include "SEmanager.h"

using namespace HE;

void SEmanager::Load()
{
	se_[0] = Sound("countdown.wav", Sound::LoopCount::SE);// �J�E���g�_�E����SE


}

void SEmanager::SEPlay(int SEID)
{
	if (SEID < 0 || SEID >= seCount_) {
		return; // ������SEID�̏ꍇ�͉������Ȃ�
	}
	se_[SEID].PlayFromTop(); // �w�肳�ꂽSE���Đ�
}

