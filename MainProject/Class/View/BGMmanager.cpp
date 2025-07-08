//
// BGMmanager.cpp
//

#include "BGMmanager.h"

using namespace HE;

void BGMmanager::Load()
{
	bgm_[0] = Sound("mainBGM.wav", Sound::LoopCount::BGM); //���C���V�[����BGM
	

}

void BGMmanager::PlayBGMFromTop(int BGMID)
{
	if (BGMID < 0 || BGMID >= bgmCount_) {
		return; // ������BGMID�̏ꍇ�͉������Ȃ�
	}
	if (currentBGMID_ != -1) {
		bgm_[currentBGMID_].Stop(); // �O��BGM���~
	}
	
	bgm_[BGMID].PlayFromTop(); // �w�肳�ꂽBGM���Đ�
}