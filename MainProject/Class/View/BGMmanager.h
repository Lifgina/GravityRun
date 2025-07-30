#pragma once

#include "../../HuEngine.h"

class BGMmanager {
public:
	void Load(); // BGMをロードする関数
	void PlayBGMFromTop(int BGMID);
	void PlayBGMContinue(int BGMID);
	void StopBGM() {
		if (currentBGMID_ != -1) {
			bgm_[currentBGMID_].Stop(); // 現在のBGMを停止
			currentBGMID_ = -1; // 現在のBGM ID をリセット
		}
	}

private:
	int bgmCount_ = 3; // 管理するBGMの数
	HE::Sound bgm_[3]; // BGMを管理するオブジェクト
	int currentBGMID_ = -1; // 現在再生中のBGMのIDを管理する変数
};