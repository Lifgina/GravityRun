#pragma once

#include "../../HuEngine.h"

class MoveEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos,float apeearTime); // ���������\�b�h
	void Update(HE::Math::Vector2 enemyPos,float timer);
	void AnimStop() { moveEnemySprite_.anim.drawRectAnim.frameRate = 0; } // �A�j���[�V�������~����


private:
	float enemyWidth_ = 32.0f; // �G�̕�
	float enemyHeight_ = 32.0f; // �G�̍���
	HE::Sprite moveEnemySprite_; // �G�̃X�v���C�g
	float apeearTime_ ; // �G���\�������܂ł̎���
	float apeearBafa_ = 3.0f; // �G���\�������܂ł̎��ԕ␳
};