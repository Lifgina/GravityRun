#pragma once

#include "../../HuEngine.h"

class SEmanager {
public:
	void Load();
	void PlaySE(int SEID);

private:
	int seCount_ = 11; // 管理するSEの数
	HE::Sound se_[11]; // SEを管理するオブジェクト
};