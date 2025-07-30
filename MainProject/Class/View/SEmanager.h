#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void PlaySE(int SEID);
	bool GetIsSEPlaying(int SEID) {
		if (SEID < 0 || SEID >= seCount_) {
			return false; // 無効なSEIDの場合はfalseを返す
		}
		return se_[SEID].isPlaying(); // 指定されたSEが再生中かどうかを返す
	}

private:
	int seCount_ = 12; // 管理するSEの数
	HE::Sound se_[12]; // SEを管理するオブジェクト
};