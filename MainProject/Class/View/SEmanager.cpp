//
// SEmanager.cpp
//

#include "SEmanager.h"

using namespace HE;

void SEmanager::Load()
{
	se_[0] = Sound("Sound/SE/se_button_rule.wav", Sound::LoopCount::SE);//���������\������Ƃ���SE
	se_[1] = Sound("Sound/SE/se_button_select.wav", Sound::LoopCount::SE); //���j���[��I������Ƃ���SE
	se_[2] = Sound("Sound/SE/se_button_start.wav", Sound::LoopCount::SE); //�Q�[���J�n����Ƃ���SE
	se_[3] = Sound("Sound/SE/se_countdown_count.wav", Sound::LoopCount::SE); //�J�E���g�_�E����SE
	se_[4] = Sound("Sound/SE/se_countdown_start.wav", Sound::LoopCount::SE); //�J�E���g�_�E���J�n��SE
	se_[5] = Sound("Sound/SE/se_enemy_fire.wav", Sound::LoopCount::SE);//�G���Γق̏p���g���Ƃ���SE
	se_[6] = Sound("Sound/SE/se_enemy_water.wav", Sound::LoopCount::SE); //�G�����ق̏p���g���Ƃ���SE
	se_[7] = Sound("Sound/SE/se_fusuma_open.wav", Sound::LoopCount::SE); //�ӂ��܂��J���Ƃ���SE
	se_[8] = Sound("Sound/SE/se_player_damage.wav", Sound::LoopCount::SE); //�v���C���[���_���[�W���󂯂��Ƃ���SE
	se_[9] = Sound("Sound/SE/se_player_gravity.wav", Sound::LoopCount::SE); //�v���C���[���d�͂�ύX�����Ƃ���SE
	se_[10] = Sound("Sound/SE/jingle_result.wav", Sound::LoopCount::SE); //�Q�[���N���A��SE
	se_[11] = Sound("Sound/SE/se_movefloar.wav", Sound::LoopCount::SE); //�v���C���[�����G��ԂɂȂ����Ƃ���SE


}

void SEmanager::PlaySE(int SEID)
{
	if (SEID < 0 || SEID >= seCount_) {
		return; // ������SEID�̏ꍇ�͉������Ȃ�
	}
	se_[SEID].PlayFromTop(); // �w�肳�ꂽSE���Đ�
}

