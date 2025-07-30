#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void PlaySE(int SEID);
	bool GetIsSEPlaying(int SEID) {
		if (SEID < 0 || SEID >= seCount_) {
			return false; // ������SEID�̏ꍇ��false��Ԃ�
		}
		return se_[SEID].isPlaying(); // �w�肳�ꂽSE���Đ������ǂ�����Ԃ�
	}

private:
	int seCount_ = 12; // �Ǘ�����SE�̐�
	HE::Sound se_[12]; // SE���Ǘ�����I�u�W�F�N�g
};