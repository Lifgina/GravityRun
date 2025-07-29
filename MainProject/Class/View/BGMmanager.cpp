//
// BGMmanager.cpp
//

#include "BGMmanager.h"

using namespace HE;

void BGMmanager::Load()
{
	bgm_[0] = Sound("Sound/BGM/bgm_main.wav", Sound::LoopCount::BGM); //���C���V�[����BGM
	bgm_[1] = Sound("Sound/BGM/bgm_title.wav", Sound::LoopCount::BGM); //�^�C�g���V�[����BGM
	bgm_[2] = Sound("Sound/BGM/jingle_muteki.wav", Sound::LoopCount::BGM); //�Q�[���I�[�o�[�V�[����BGM
	

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