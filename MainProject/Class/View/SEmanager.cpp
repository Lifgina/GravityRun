//
// SEmanager.cpp
//

#include "SEmanager.h"

using namespace HE;

void SEmanager::Load()
{
	se_[0] = Sound("countdown.wav", Sound::LoopCount::SE);


}

void SEmanager::SEPlay(int SEID)
{
	if (SEID < 0 || SEID >= seCount_) {
		return; // –³Œø‚ÈSEID‚Ìê‡‚Í‰½‚à‚µ‚È‚¢
	}
	se_[SEID].PlayFromTop(); // w’è‚³‚ê‚½SE‚ğÄ¶
}

