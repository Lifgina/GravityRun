//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
	draftFont_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf");
	RenderingPath->AddFont(&draftFont_, 1200);

	draftSprite_ = HE::Sprite("");
	RenderingPath->AddSprite(&draftSprite_, 1000);
}

void GameOverView::Initialize()
{
	draftSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	draftSprite_.params.color = HE::Color(255, 255, 255, 125); // �������̍��F
	draftFont_.params.size = 72;
	draftFont_.params.color = Color(0, 0, 0, 255); // �D�F�̃t�H���g
	draftFont_.SetText("Game Over");
	draftFont_.params.posX = RenderingPath->GetLogicalWidth() / 2,
	draftFont_.params.posY = RenderingPath->GetLogicalHeight() / 2;
	HideGameOver(); // �Q�[���I�[�o�[��ʂ��\���ɂ���
}

void GameOverView::ShowGameOver()
{
	draftFont_.SetHidden(false); // �t�H���g��\��
	draftSprite_.SetHidden(false); // �Q�[���I�[�o�[��ʂ̃X�v���C�g��\��
}

void GameOverView::HideGameOver()
{
	draftFont_.SetHidden(true); // �t�H���g���\��
	draftSprite_.SetHidden(true); // �Q�[���I�[�o�[��ʂ̃X�v���C�g���\��
}

