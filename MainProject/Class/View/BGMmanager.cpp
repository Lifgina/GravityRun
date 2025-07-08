//
// BGMmanager.cpp
//

#include "BGMmanager.h"

using namespace HE;

void BGMmanager::Load()
{
	bgm_[0] = Sound("mainBGM.wav", Sound::LoopCount::BGM);
	

}

void BGMmanager::PlayBGMFromTop(int BGMID)
{
	if (BGMID < 0 || BGMID >= bgmCount_) {
		return; // –³Œø‚ÈBGMID‚Ìê‡‚Í‰½‚à‚µ‚È‚¢
	}
	if (currentBGMID_ != -1) {
		bgm_[currentBGMID_].Stop(); // ‘O‚ÌBGM‚ğ’â~
	}
	
	bgm_[BGMID].PlayFromTop(); // w’è‚³‚ê‚½BGM‚ğÄ¶
}