//
// BGMmanager.cpp
//

#include "BGMmanager.h"

using namespace HE;

void BGMmanager::Load()
{
	bgm_[0] = Sound("Sound/BGM/bgm_main.wav", Sound::LoopCount::BGM); //メインシーンのBGM
	bgm_[1] = Sound("Sound/BGM/bgm_title.wav", Sound::LoopCount::BGM); //タイトルシーンのBGM
	bgm_[2] = Sound("Sound/BGM/jingle_muteki.wav", Sound::LoopCount::BGM); //ゲームオーバーシーンのBGM
	

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