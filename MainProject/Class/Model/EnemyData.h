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
	int GetSuitonEnemyDirection(int index) const { return suitonEnemyDirection_[index]; }
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
	int silentEnemyCount_ = 4; // ‚Ü‚«‚Ñ‚µ‚Ì” 
	
	// “G‚ÌˆÊ’u
	HE::Math::Vector2 SilentenemyPosition_[4] = {
		HE::Math::Vector2(540.0f,20.0f),
		HE::Math::Vector2(340.0f,195.0f),
		HE::Math::Vector2(875.0f,370.0f),
		HE::Math::Vector2(840.0f,545.0f),
	};
	//“G‚ÌŒü‚«@1:ãŒü‚«@-1:‰ºŒü‚«
	//View‘¤‚Åg—p
	float silentEnemyDirection_[4] = {-1,-1,-1,-1}; 

	//è— Œ•‚Ìƒf[ƒ^
	int MoveEnemyCount_ = 2; // è— Œ•‚Ì”
	// “G‚Ì‰ŠúˆÊ’u
	HE::Math::Vector2 moveEnemyPosition_[2] = {
		HE::Math::Vector2(940.0f+50-16, 350.0f-32.0f),
		HE::Math::Vector2(390.0f-16.0f ,  525.0f-32.0f),
	};
	float moveEnemyTimeToActive_[2] = {10.0f,10.0f}; // “G‚ªƒAƒNƒeƒBƒu‚É‚È‚é‚Ü‚Å‚ÌŠÔ
	// “G‚ÌÅ‰‚ÌŒü‚«@1:‰EŒü‚«@-1:¶Œü‚«
	float moveEnemyDirection_[2] = {-1,1};
	// “G‚ÌˆÚ“®‘¬“x
	float moveEnemySpeed_[2] = {300.0f,300.0f};
	// “G‚ÌˆÚ“®”ÍˆÍ
	float moveEnemyMinRange_X_[2] = {240.0f,140.0f};
	float moveEnemyMaxRange_X_[2] = { 1140.0f-32.0f , 1040.0f-32.0f};

	//…“Ù”EÒ‚Ìƒf[ƒ^
	int suitonEnemyCount_ = 4; // …“Ù”EÒ‚Ì”

	float suitonEnemyCollisionHeight_ = 155.0f; // …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³
	float suitonEnemyCollisionWidth_ = 1200.0f; // …“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•

	// “G‚ÌˆÊ’u
	HE::Math::Vector2 suitonEnemyModelPosition_[4] = {
		HE::Math::Vector2(40,0.0f+20.0f),
		HE::Math::Vector2(40,175.0f+20.0f),
		HE::Math::Vector2(40,350.0f + 20.0f),
		HE::Math::Vector2(40,525.0f + 20.0f),
	};
	
	HE::Math::Vector2 suitonEnemyViewPosition_[4] = {
		HE::Math::Vector2(1140.0f+18,175.0f-64.0f),
		HE::Math::Vector2(40+18,350.0f-64.0f),
		HE::Math::Vector2(1140.0f+18,525.0f -64.0f),
		HE::Math::Vector2(40+18,700.0f -64.0f),
	};

	int suitonEnemyDirection_[4] = { -1,1,-1,1 }; // “G‚ÌŒü‚«@1:‰EŒü‚«@-1:¶Œü‚«AView‘¤‚Åg—p

	//ˆÈ‰º‚Ì”z—ñ‚ÍŠÔ‚Æ•R‚Ã‚¯‚Äg—p‚·‚é
	int suitonAttackTimes_ = 4; // …“Ù”EÒ‚ÌUŒ‚‚Ì‰ñ”
	float suitonEnemyApeearTime_[4] = { 30.0f-3,35.0f-3,50.0f-3,55.0f-3 }; // “G‚ª•\¦‚³‚ê‚éŠÔ(—\’›‚ğn‚ß‚éŠÔ)
	float suitonEnemyAttackTime_[4] = { 3.0f,3.0f,3.0f,3.0f }; // “G‚ÌUŒ‚‚Ü‚Å‚ÌŠÔ(—\’›‰‰o‚ÌŠÔ)
	float suitonEnemyAttackDuration_[4] = { 1.0f,1.0f,1.0f,1.0f }; // “G‚ÌUŒ‚‚Ì‘±ŠÔ
	float suitonEnemyAttackAfterTime_[4] = { 0.2f,0.2f,0.2f,0.2f }; // “G‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ
	int attackSuitonEnemyAmount_[4] = { 1,1,1,2 }; // “G‚ÌUŒ‚‚Ì”

	//‰Î“Ù”EÒ‚Ìƒf[ƒ^
	int katonEnemyCount_ = 8; // ‰Î“Ù”EÒ‚Ì”

	float katonEnemyCollisionHeight_ = 155.0f; // ‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì‚‚³
	float katonEnemyCollisionWidth_ = 100.0f; // ‰Î“Ù”EÒ‚ÌÕ“Ë”»’è‚Ì•

	// “G‚ÌˆÊ’u
	HE::Math::Vector2 katonEnemyModelPosition_[8] = {
		HE::Math::Vector2(340.0f,175.0f - 155.0f),
		HE::Math::Vector2(740.0f,175.0f - 155.0f),
		HE::Math::Vector2(440.0f,350.0f - 155.0f),
		HE::Math::Vector2(940.0f,350.0f - 155.0f),
		HE::Math::Vector2(340.0f,525.0f - 155.0f),
		HE::Math::Vector2(640.0f,525.0f - 155.0f),
		HE::Math::Vector2(340.0f,700.0f - 155.0f),
		HE::Math::Vector2(940.0f,700.0f - 155.0f)
	};

	HE::Math::Vector2 katonEnemyViewPosition_[8] = {
		HE::Math::Vector2(340.0f+18,175.0f - 64.0f),
		HE::Math::Vector2(740.0f+18,175.0f - 64.0f),
		HE::Math::Vector2(440.0f+18,350.0f - 64.0f),
		HE::Math::Vector2(940.0f+18,350.0f - 64.0f),
		HE::Math::Vector2(340.0f+18,525.0f - 64.0f),
		HE::Math::Vector2(640.0f+18,525.0f - 64.0f),
		HE::Math::Vector2(340.0f+18,700.0f - 64.0f),
		HE::Math::Vector2(940.0f+18,700.0f - 64.0f)
	};

	//ˆÈ‰º‚Ì”z—ñ‚ÍŠÔ‚Æ•R‚Ã‚¯‚Äg—p‚·‚é
	int katonAttackTimes_ = 4; // ‰Î“Ù”EÒ‚ÌUŒ‚‚Ì‰ñ”
	float katonEnemyApeearTime_[4] = { 20.0f - 3,35.0f - 3,45.0f - 3,50.0f - 3 }; // “G‚ª•\¦‚³‚ê‚éŠÔ
	float katonEnemyAttackTime_[4] = { 3.0f,3.0f,3.0f,3.0f }; // “G‚ÌUŒ‚‚Ü‚Å‚ÌŠÔ
	float katonEnemyAttackDuration_[4] = { 4.5f,4.5f,4.5f,4.5f }; // “G‚ÌUŒ‚‚Ì‘±ŠÔ
	float katonEnemyAttackAfterTime_[4] = { 0.3f,0.3f,0.3f,0.3f, }; // “G‚ÌUŒ‚Œã‚Ì‘Ò‹@ŠÔ
	int attackKatonEnemyAmount_[4] = { 1,1,2,2 }; // “G‚ÌUŒ‚‚Ì”

	
};