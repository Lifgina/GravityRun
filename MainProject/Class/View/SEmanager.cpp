//
// SEmanager.cpp
//

#include "SEmanager.h"

using namespace HE;

void SEmanager::Load()
{
	se_[0] = Sound("countdown.wav", Sound::LoopCount::SE);// カウントダウンのSE


}

void SEmanager::SEPlay(int SEID)
{
	if (SEID < 0 || SEID >= seCount_) {
		return; // 無効なSEIDの場合は何もしない
	}
	se_[SEID].PlayFromTop(); // 指定されたSEを再生
}

