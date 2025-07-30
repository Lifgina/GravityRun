//
// SEmanager.cpp
//

#include "SEmanager.h"

using namespace HE;

void SEmanager::Load()
{
	se_[0] = Sound("Sound/SE/se_button_rule.wav", Sound::LoopCount::SE);//操作説明を表示するときのSE
	se_[1] = Sound("Sound/SE/se_button_select.wav", Sound::LoopCount::SE); //メニューを選択するときのSE
	se_[2] = Sound("Sound/SE/se_button_start.wav", Sound::LoopCount::SE); //ゲーム開始するときのSE
	se_[3] = Sound("Sound/SE/se_countdown_count.wav", Sound::LoopCount::SE); //カウントダウンのSE
	se_[4] = Sound("Sound/SE/se_countdown_start.wav", Sound::LoopCount::SE); //カウントダウン開始のSE
	se_[5] = Sound("Sound/SE/se_enemy_fire.wav", Sound::LoopCount::SE);//敵が火遁の術を使うときのSE
	se_[6] = Sound("Sound/SE/se_enemy_water.wav", Sound::LoopCount::SE); //敵が水遁の術を使うときのSE
	se_[7] = Sound("Sound/SE/se_fusuma_open.wav", Sound::LoopCount::SE); //ふすまが開くときのSE
	se_[8] = Sound("Sound/SE/se_player_damage.wav", Sound::LoopCount::SE); //プレイヤーがダメージを受けたときのSE
	se_[9] = Sound("Sound/SE/se_player_gravity.wav", Sound::LoopCount::SE); //プレイヤーが重力を変更したときのSE
	se_[10] = Sound("Sound/SE/jingle_result.wav", Sound::LoopCount::SE); //ゲームクリアのSE
	se_[11] = Sound("Sound/SE/se_movefloar.wav", Sound::LoopCount::SE); //プレイヤーが無敵状態になったときのSE


}

void SEmanager::PlaySE(int SEID)
{
	if (SEID < 0 || SEID >= seCount_) {
		return; // 無効なSEIDの場合は何もしない
	}
	se_[SEID].PlayFromTop(); // 指定されたSEを再生
}

