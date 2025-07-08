#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void SEPlay(int SEID);

private:
	int seCount_ = 5; // 管理するSEの数
	HE::Sound se_[5]; // SEを管理するオブジェクト
};