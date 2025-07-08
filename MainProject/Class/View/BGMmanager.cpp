//
// BGMmanager.cpp
//

#include "BGMmanager.h"

using namespace HE;

void BGMmanager::Load()
{
	bgm_[0] = Sound("mainBGM.wav", Sound::LoopCount::BGM); //メインシーンのBGM
	

}

void BGMmanager::PlayBGMFromTop(int BGMID)
{
	if (BGMID < 0 || BGMID >= bgmCount_) {
		return; // 無効なBGMIDの場合は何もしない
	}
	if (currentBGMID_ != -1) {
		bgm_[currentBGMID_].Stop(); // 前のBGMを停止
	}
	
	bgm_[BGMID].PlayFromTop(); // 指定されたBGMを再生
}