//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
    for (int i = 0; i < 2; i++) {
        gameOverFont_[i].params.style = Font::AddFontStyle("Fonts/meiryob004.ttf");
        RenderingPath->AddFont(&gameOverFont_[i], 1200);
    }
    draftSprite_ = HE::Sprite("");
    RenderingPath->AddSprite(&draftSprite_, 1000);
}

void GameOverView::Initialize()
{
    draftSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
    draftSprite_.params.color = HE::Color(255, 255, 255, 125); // �������̍��F


        gameOverFont_[0].params.size = 128;
        gameOverFont_[0].params.posX = RenderingPath->GetLogicalWidth() / 2-320;
        gameOverFont_[0].params.posY = RenderingPath->GetLogicalHeight() / 2-200;
        gameOverFont_[1].params.size = 72;
        gameOverFont_[1].params.posX = RenderingPath->GetLogicalWidth() / 2-250;
        gameOverFont_[1].params.posY = RenderingPath->GetLogicalHeight() / 2 +64;
        
    
    HideGameOver(); // �Q�[���I�[�o�[��ʂ��\���ɂ���
}

void GameOverView::ShowGameOver(int gameState, float aliveTime)
{
    if (gameState == 0) {
        return; // �Q�[���I�[�o�[��ԂłȂ��ꍇ�͉������Ȃ�
    }
    else if (gameState == 1) {
        for (int i = 0; i < 2; i++) {
            gameOverFont_[i].params.color = Color(255, 0, 0, 255); // �Q�[���I�[�o�[�̃t�H���g�F��ԂɕύX
            gameOverFont_[i].SetHidden(false); // �t�H���g��\��
        }
        gameOverFont_[0].SetText(L"Game Over");
		gameOverFont_[1].SetText(std::to_wstring(static_cast<int>(aliveTime)) + L"�b�����c��܂����B"); // �������Ԃ�\��
    }
    else if (gameState == 2) {
        for (int i = 0; i < 2; i++) {
            gameOverFont_[i].params.color = Color(0, 255, 0, 255); // �Q�[���N���A�̃t�H���g�F��΂ɕύX
            gameOverFont_[i].SetHidden(false); // �t�H���g��\��
        }
        gameOverFont_[0].SetText(L"Game Clear");
    }
    draftSprite_.SetHidden(false); // �Q�[���I�[�o�[��ʂ̃X�v���C�g��\��
}

void GameOverView::HideGameOver()
{
    for (int i = 0; i < 2; i++) {
        gameOverFont_[i].SetHidden(true); // �t�H���g���\��
    }
    draftSprite_.SetHidden(true); // �Q�[���I�[�o�[��ʂ̃X�v���C�g���\��
}
