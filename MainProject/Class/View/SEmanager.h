#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void SEPlay(int SEID);

private:
	int seCount_ = 5; // �Ǘ�����SE�̐�
	HE::Sound se_[5]; // SE���Ǘ�����I�u�W�F�N�g
};