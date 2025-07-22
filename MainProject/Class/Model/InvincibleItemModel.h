#pragma once

#include "../../HuEngine.h"

class InvincibleItemModel {
public:
	void Initialize();
	void Update(float timer); // �A�C�e���̍X�V����
	HE::Math::Rectangle GetCollision();
	void SetActive(HE::Math::Vector2 itemPos,float itemActivateTime); // �A�C�e�����A�N�e�B�u�ɂ���
	void SetInactive(); // �A�C�e�����A�N�e�B�u�ɂ���
	bool GetIsActive() const { return isActive_; } // �A�C�e�����A�N�e�B�u���ǂ������擾
	HE::Math::Vector2 GetItemPosition() const { return itemPosition_; } // �A�C�e���̈ʒu���擾


private:
	bool isActive_ = false; // �A�C�e�����A�N�e�B�u���ǂ���
	HE::Math::Vector2 itemPosition_; // �A�C�e���̈ʒu
	float itemActivateTime_ ; // �A�C�e�����A�N�e�B�u�ɂȂ�������
	float itemActiveDuration_ = 10.0f; // �A�C�e�����A�N�e�B�u�Ȏ���
	float itemWidth_ = 100.0f; // �A�C�e���̕�
	float itemHeight_ = 155.0f; // �A�C�e���̍���
};