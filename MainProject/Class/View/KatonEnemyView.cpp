//
// KatonEnemyView.cpp
//

#include "KatonEnemyView.h"

using namespace HE;

void KatonEnemyView::Load()
{
	katonEnemySprite_ = HE::Sprite("");
	katonEnemyAttackSprite_ = HE::Sprite("");
}

void KatonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	katonEnemySprite_.params.pos = ninjaPos; // …“Ù‚Ìp‚Ì“G‚Ì‰ŠúˆÊ’u‚ğİ’è
	katonEnemySprite_.params.siz = Math::Vector2(100.0f, 155.0f); // …“Ù‚Ìp‚Ì“G‚ÌƒTƒCƒY‚ğİ’è
	katonEnemySprite_.params.color = HE::Color(255, 255, 255, 255); // …“Ù‚Ìp‚Ì“G‚ÌF‚ğİ’è
	katonEnemyAttackSprite_.params.pos = attackPos; // …“Ù‚Ìp‚ÌUŒ‚‚Ì‰ŠúˆÊ’u‚ğİ’è
	katonEnemyAttackSprite_.params.siz = Math::Vector2(100.0f, 155.0f); // …“Ù‚Ìp‚ÌUŒ‚‚ÌƒTƒCƒY‚ğİ’è
	katonEnemyAttackSprite_.params.color = HE::Color(255, 0, 0, 200); // …“Ù‚Ìp‚ÌUŒ‚‚ÌF‚ğİ’è
	RenderingPath->AddSprite(&katonEnemySprite_, 0); // …“Ù‚Ìp‚Ì“G‚ÌƒXƒvƒ‰ƒCƒg‚ğƒŒƒ“ƒ_ƒŠƒ“ƒOƒpƒX‚É’Ç‰Á
	RenderingPath->AddSprite(&katonEnemyAttackSprite_, 0); // …“Ù‚Ìp‚ÌUŒ‚‚ÌƒXƒvƒ‰ƒCƒg‚ğƒŒƒ“ƒ_ƒŠƒ“ƒOƒpƒX‚É’Ç‰Á
}

void KatonEnemyView::Update(bool isActive, int katonEnemyState)
{
	if (!isActive) {
		katonEnemySprite_.SetHidden(true);
		katonEnemyAttackSprite_.SetHidden(true);
	}
	else {
		switch (katonEnemyState)
		{
		case 0: // ‘Ò‹@ó‘Ô
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			break;
		case 1: // UŒ‚ó‘Ô
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(false);
			break;
		case 2: // UŒ‚Œãó‘Ô
			katonEnemySprite_.SetHidden(false);
			katonEnemyAttackSprite_.SetHidden(true);
			break;
		}
	
	}
}