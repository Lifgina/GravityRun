//
// SuitonEnemyView.cpp
//

#include "SuitonEnemyView.h"

using namespace HE;

void SuitonEnemyView::Load()
{
	suitonEnemySprite_ = HE::Sprite("");
	suitonEnemyAttackSprite_ = HE::Sprite("suiton.png");
}

void SuitonEnemyView::Initialize(Math::Vector2 ninjaPos, Math::Vector2 attackPos)
{
	suitonEnemySprite_.params.pos = ninjaPos; // …“Ù‚Ìp‚Ì“G‚Ì‰ŠúˆÊ’u‚ğİ’è
	suitonEnemySprite_.params.siz = Math::Vector2(60.0f, 60.0f); // …“Ù‚Ìp‚Ì“G‚ÌƒTƒCƒY‚ğİ’è
	suitonEnemySprite_.params.color = HE::Color(255, 255, 255, 255); // …“Ù‚Ìp‚Ì“G‚ÌF‚ğİ’è
	suitonEnemyAttackSprite_.params.pos = attackPos; // …“Ù‚Ìp‚ÌUŒ‚‚Ì‰ŠúˆÊ’u‚ğİ’è
	suitonEnemyAttackSprite_.params.siz = Math::Vector2(1280.0f, 132.0f); // …“Ù‚Ìp‚ÌUŒ‚‚ÌƒTƒCƒY‚ğİ’è
	suitonEnemyAttackSprite_.params.color = HE::Color(0, 0, 255, 200); // …“Ù‚Ìp‚ÌUŒ‚‚ÌF‚ğİ’è
	RenderingPath->AddSprite(&suitonEnemySprite_, 0); // …“Ù‚Ìp‚Ì“G‚ÌƒXƒvƒ‰ƒCƒg‚ğƒŒƒ“ƒ_ƒŠƒ“ƒOƒpƒX‚É’Ç‰Á
	RenderingPath->AddSprite(&suitonEnemyAttackSprite_, 0); // …“Ù‚Ìp‚ÌUŒ‚‚ÌƒXƒvƒ‰ƒCƒg‚ğƒŒƒ“ƒ_ƒŠƒ“ƒOƒpƒX‚É’Ç‰Á
}

void SuitonEnemyView::Update(bool isActive, int suitonEnemyState)
{
	if (!isActive) {
		suitonEnemySprite_.SetHidden(true);
		suitonEnemyAttackSprite_.SetHidden(true);
	}
	else {
		switch (suitonEnemyState)
		{
		case 0: // ‘Ò‹@ó‘Ô
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		case 1: // UŒ‚ó‘Ô
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(false);
			break;
		case 2: // UŒ‚Œãó‘Ô
			suitonEnemySprite_.SetHidden(false);
			suitonEnemyAttackSprite_.SetHidden(true);
			break;
		}
	
	}
}