#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void PlaySE(int SEID);

private:
	int seCount_ = 11; // �Ǘ�����SE�̐�
	HE::Sound se_[11]; // SE���Ǘ�����I�u�W�F�N�g
};