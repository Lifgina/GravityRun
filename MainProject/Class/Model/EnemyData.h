#pragma once

#include "../../HuEngine.h"

class EnemyData {
public:
	int GetSilentEnemyCount() const { return silentEnemyCount_; }
	int GetMoveEnemyCount() const { return MoveEnemyCount_; }
	int GetSuitonEnemyCount() const { return suitonEnemyCount_; }
	int GetKatonEnemyCount() const { return katonEnemyCount_; }

	// “G‚ÌˆÊ’u‚ğæ“¾
	HE::Math::Vector2 GetSilentEnemyPosition(int index) const { return SilentenemyPosition_[index]; }
	HE::Math::Vector2 GetMoveEnemyPosition(int index) const { return moveEnemyPosition_[index]; }
	// “G‚ÌŒü‚«‚ğæ“¾
	float GetSilentEnemyDirection(int index) const { return silentEnemyDirection_[index]; }
	float GetMoveEnemyDirection(int index) const { return moveEnemyDirection_[index]; }
	// “G‚ÌˆÚ“®‘¬“x‚ğæ“¾
	float GetMoveEnemySpeed(int index) const { return moveEnemySpeed_[index]; }
	// “G‚ÌˆÚ“®”ÍˆÍ‚ğæ“¾
	float GetMoveEnemyMinRange_X(int index) const { return moveEnemyMinRange_X_[index]; }
	float GetMoveEnemyMaxRange_X(int index) const { return moveEnemyMaxRange_X_[index]; }

	// “G‚ªƒAƒNƒeƒBƒu‚É‚È‚é‚Ü‚Å‚ÌŠÔ‚ğæ“¾
	float GetMoveEnemyTimeToActive(int index) const { return moveEnemyTimeToActive_[index]; }

	// …“Ù”EÒ‚Ìƒf[ƒ^‚ğæ“¾
	// …“Ù”EÒ‚ÌˆÊ’u‚ğæ“¾
	HE::Math::Vector2 GetSuitonEnemyModelPosition(int index) const { return suitonEnemyModelPosition_[index]; }
	HE::Math::Vector2 GetSuitonEnemyViewPosition(int index) const { return suitonEnemyViewPosition_[index]; }
	// …“Ù”EÒ‚ÌŒü‚«‚ğæ“¾
	int GetSuitonEnemyViewDirection(int index) const { return suitonEnemyViewDirection_[index]; }
	// …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³‚ğæ“¾
	float GetSuitonEnemyCollisionHeight() const { return suitonEnemyCollisionHeight_; }
	// …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•‚ğæ“¾
	float GetSuitonEnemyCollisionWidth() const { return suitonEnemyCollisionWidth_; }
	// …“Ù”EÒ‚ÌUŒ‚‰ñ”‚ğæ“¾
	int GetSuitonAttackTimes() const { return suitonAttackTimes_; }
	// …“Ù”EÒ‚ÌoŒ»ŠÔ‚ğæ“¾
	float GetSuitonEnemyApeearTime(int index) const { return suitonEnemyApeearTime_[index]; }
	// …“Ù”EÒ‚ÌUŒ‚ŠÔ‚ğæ“¾
	float GetSuitonEnemyAttackTime(int index) const { return suitonEnemyAttackTime_[index]; }
	// …“Ù”EÒ‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ‚ğæ“¾
	float GetSuitonEnemyAttackAfterTime(int index) const { return suitonEnemyAttackAfterTime_[index]; }
	// …“Ù”EÒ‚ÌUŒ‚‚Ì‘±ŠÔ‚ğæ“¾
	float GetSuitonEnemyAttackDuration(int index) const { return suitonEnemyAttackDuration_[index]; }
	// …“Ù”EÒ‚ÌUŒ‚‚ÅoŒ»‚·‚é“G‚Ì”‚ğæ“¾
	int GetAttackSuitonEnemyAmount(int index) const { return attackSuitonEnemyAmount_[index]; }

	//‰Î“Ù”EÒ‚Ìƒf[ƒ^‚ğæ“¾
	//‰Î“Ù”EÒ‚ÌˆÊ’u‚ğæ“¾
	HE::Math::Vector2 GetKatonEnemyModelPosition(int index) const { return katonEnemyModelPosition_[index]; }
	HE::Math::Vector2 GetKatonEnemyViewPosition(int index) const { return katonEnemyViewPosition_[index]; }
	//‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³‚ğæ“¾
	float GetKatonEnemyCollisionHeight() const { return katonEnemyCollisionHeight_; }
	//‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•‚ğæ“¾
	float GetKatonEnemyCollisionWidth() const { return katonEnemyCollisionWidth_; }
	//‰Î“Ù”EÒ‚ÌUŒ‚‰ñ”‚ğæ“¾
	int GetKatonAttackTimes() const { return katonAttackTimes_; }
	//‰Î“Ù”EÒ‚ÌoŒ»ŠÔ‚ğæ“¾
	float GetKatonEnemyApeearTime(int index) const { return katonEnemyApeearTime_[index]; }
	//‰Î“Ù”EÒ‚ÌUŒ‚ŠÔ‚ğæ“¾
	float GetKatonEnemyAttackTime(int index) const { return katonEnemyAttackTime_[index]; }
	//‰Î“Ù”EÒ‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ‚ğæ“¾
	float GetKatonEnemyAttackAfterTime(int index) const { return katonEnemyAttackAfterTime_[index]; }
	//‰Î“Ù”EÒ‚ÌUŒ‚‚Ì‘±ŠÔ‚ğæ“¾
	float GetKatonEnemyAttackDuration(int index) const { return katonEnemyAttackDuration_[index]; }
	//‰Î“Ù”EÒ‚ÌUŒ‚‚ÅoŒ»‚·‚é“G‚Ì”‚ğæ“¾
	int GetAttackKatonEnemyAmount(int index) const { return attackKatonEnemyAmount_[index]; }

private:
	//‚Ü‚«‚Ñ‚µ‚Ìƒf[ƒ^
	int silentEnemyCount_ = 12; // ‚Ü‚«‚Ñ‚µ‚Ì” 
	
	// “G‚ÌˆÊ’u
	HE::Math::Vector2 SilentenemyPosition_[12] = {
		HE::Math::Vector2(410.0f,0.0f+10.0f),
		HE::Math::Vector2(210.0f, 142.0f-32.0f),
		HE::Math::Vector2(1010.0f-64.0f, 142.0f - 32.0f),
		HE::Math::Vector2(910.0f - 64.0f, 142.0f +10.0f),
		HE::Math::Vector2(410.0f, 284.0f-32.0f),
		HE::Math::Vector2(610.0f, 284.0f + 10.0f),
		HE::Math::Vector2(110.0f, 426.0f - 32.0f),
		HE::Math::Vector2(1010.0f-64.0f, 426.0f - 32.0f),
		HE::Math::Vector2(310.0f, 426.0f +10.0f),
		HE::Math::Vector2(310.0f, 568.0f+10.0f),
		HE::Math::Vector2(1010.0f, 568.0f + 10.0f),
		HE::Math::Vector2(610.0f, 710.0f-32.0f),
	
	};
	//“G‚ÌŒü‚«@1:ãŒü‚«@-1:‰ºŒü‚«
	//View‘¤‚Åg—p
	float silentEnemyDirection_[12] = {}; 

	//è— Œ•‚Ìƒf[ƒ^
	int MoveEnemyCount_ = 2; // è— Œ•‚Ì”
	// “G‚Ì‰ŠúˆÊ’u
	HE::Math::Vector2 moveEnemyPosition_[2] = {
		HE::Math::Vector2(360.0f-16.0f, 284.0f-32.0f),
		HE::Math::Vector2(760.0f-16.0f ,  568.0f-32.0f),
	};
	float moveEnemyTimeToActive_[2] = {15.0f,15.0f}; // “G‚ªƒAƒNƒeƒBƒu‚É‚È‚é‚Ü‚Å‚ÌŠÔ
	// “G‚ÌÅ‰‚ÌŒü‚«@1:‰EŒü‚«@-1:¶Œü‚«
	float moveEnemyDirection_[2] = {1,1};
	// “G‚ÌˆÚ“®‘¬“x
	float moveEnemySpeed_[2] = {300.0f,300.0f};
	// “G‚ÌˆÚ“®”ÍˆÍ
	float moveEnemyMinRange_X_[2] = {310.0f,210.0f};
	float moveEnemyMaxRange_X_[2] = { 1110.0f-32.0f , 1110.0f-32.0f};

	//…“Ù”EÒ‚Ìƒf[ƒ^
	int suitonEnemyCount_ = 5; // …“Ù”EÒ‚Ì”

	float suitonEnemyCollisionHeight_ = 132.0f; // …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³
	float suitonEnemyCollisionWidth_ = 1280.0f; // …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•

	// “G‚ÌˆÊ’u
	HE::Math::Vector2 suitonEnemyModelPosition_[5] = {
		HE::Math::Vector2(0,0.0f+10.0f),
		HE::Math::Vector2(0,132.0f+20.0f),
		HE::Math::Vector2(0,264.0f + 30.0f),
		HE::Math::Vector2(0,396.0f + 40.0f),
		HE::Math::Vector2(0,528.0f + 50.0f),
	};
	
	HE::Math::Vector2 suitonEnemyViewPosition_[5] = {
		HE::Math::Vector2(1110.0f + 10.0f),
		HE::Math::Vector2(0,132.0f + 20.0f),
		HE::Math::Vector2(1110.0f,264.0f + 30.0f),
		HE::Math::Vector2(0,396.0f + 40.0f),
		HE::Math::Vector2(1110.0f,528.0f + 50.0f),
	};

	int suitonEnemyViewDirection_[5] = { -1,1,-1,1,-1 }; // “G‚ÌŒü‚«@1:‰EŒü‚«@-1:¶Œü‚«AView‘¤‚Åg—p

	//ˆÈ‰º‚Ì”z—ñ‚ÍŠÔ‚Æ•R‚Ã‚¯‚Äg—p‚·‚é
	int suitonAttackTimes_ = 5; // …“Ù”EÒ‚ÌUŒ‚‚Ì‰ñ”
	float suitonEnemyApeearTime_[5] = { 35.0f-3,40.0f-3,45.0f-3,50.0f-3,55.0f-3 }; // “G‚ª•\¦‚³‚ê‚éŠÔ
	float suitonEnemyAttackTime_[5] = { 3.0f,3.0f,3.0f,3.0f,3.0f }; // “G‚ÌUŒ‚‚Ü‚Å‚ÌŠÔ
	float suitonEnemyAttackDuration_[5] = { 1.0f,1.0f,1.0f,1.0f,1.0f }; // “G‚ÌUŒ‚‚Ì‘±ŠÔ
	float suitonEnemyAttackAfterTime_[5] = { 0.2f,0.2f,0.2f,0.2f,0.2f }; // “G‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ
	int attackSuitonEnemyAmount_[5] = { 2,1,1,2,3 }; // “G‚ÌUŒ‚‚Ì”

	//‰Î“Ù”EÒ‚Ìƒf[ƒ^
	int katonEnemyCount_ = 8; // ‰Î“Ù”EÒ‚Ì”

	float katonEnemyCollisionHeight_ = 132.0f; // ‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³
	float katonEnemyCollisionWidth_ = 100.0f; // ‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•

	// “G‚ÌˆÊ’u
	HE::Math::Vector2 katonEnemyModelPosition_[8] = {
		HE::Math::Vector2(810.0f,142.0f - 132.0f),
		HE::Math::Vector2(410.0f,284.0f - 132.0f),
		HE::Math::Vector2(810.0f,284.0f - 132.0f),
		HE::Math::Vector2(210.0f,426.0f - 132.0f),
		HE::Math::Vector2(710.0f,426.0f - 132.0f),
		HE::Math::Vector2(610.0f,528.0f - 132.0f),
		HE::Math::Vector2(810.0f,528.0f - 132.0f),
		HE::Math::Vector2(410.0f,710.0f - 132.0f),
	};

	HE::Math::Vector2 katonEnemyViewPosition_[8] = {
		HE::Math::Vector2(810.0f,142.0f - 132.0f),
		HE::Math::Vector2(410.0f,284.0f - 132.0f),
		HE::Math::Vector2(810.0f,284.0f - 132.0f),
		HE::Math::Vector2(210.0f,426.0f - 132.0f),
		HE::Math::Vector2(710.0f,426.0f - 132.0f),
		HE::Math::Vector2(610.0f,528.0f - 132.0f),
		HE::Math::Vector2(810.0f,528.0f - 132.0f),
		HE::Math::Vector2(410.0f,710.0f - 132.0f),
	};

	//ˆÈ‰º‚Ì”z—ñ‚ÍŠÔ‚Æ•R‚Ã‚¯‚Äg—p‚·‚é
	int katonAttackTimes_ = 4; // ‰Î“Ù”EÒ‚ÌUŒ‚‚Ì‰ñ”
	float katonEnemyApeearTime_[4] = { 5.0f - 3,40.0f - 3,45.0f - 3,50.0f - 3 }; // “G‚ª•\¦‚³‚ê‚éŠÔ
	float katonEnemyAttackTime_[4] = { 3.0f,3.0f,3.0f,3.0f }; // “G‚ÌUŒ‚‚Ü‚Å‚ÌŠÔ
	float katonEnemyAttackDuration_[4] = { 4.5f,4.5f,4.5f,4.5f }; // “G‚ÌUŒ‚‚Ì‘±ŠÔ
	float katonEnemyAttackAfterTime_[4] = { 0.3f,0.3f,0.3f,0.3f, }; // “G‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ
	int attackKatonEnemyAmount_[4] = { 2,1,2,1 }; // “G‚ÌUŒ‚‚Ì”

	
};