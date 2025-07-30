#pragma once

#include "../../HuEngine.h"

class BGMmanager {
public:
	void Load(); // BGM�����[�h����֐�
	void PlayBGMFromTop(int BGMID);
	void PlayBGMContinue(int BGMID);
	void StopBGM() {
		if (currentBGMID_ != -1) {
			bgm_[currentBGMID_].Stop(); // ���݂�BGM���~
			currentBGMID_ = -1; // ���݂�BGM ID �����Z�b�g
		}
	}

private:
	int bgmCount_ = 3; // �Ǘ�����BGM�̐�
	HE::Sound bgm_[3]; // BGM���Ǘ�����I�u�W�F�N�g
	int currentBGMID_ = -1; // ���ݍĐ�����BGM��ID���Ǘ�����ϐ�
};