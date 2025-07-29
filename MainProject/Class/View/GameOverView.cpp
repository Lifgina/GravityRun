//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
	genin_resultSprite_ = HE::Sprite("genin_result.png");
	tyunin_resultSprite_ = HE::Sprite("tyunin_result.png");
	jonin_resultSprite_ = HE::Sprite("jonin_result.png");
	sakanin_resultSprite_ = HE::Sprite("sakanin_result.png");
	gameOverTime_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // �Q�[���I�[�o�[�̃t�H���g�X�^�C����ݒ�
	RenderingPath->AddSprite(&genin_resultSprite_, 1000); // �Q�[���I�[�o�[��ʂ̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&tyunin_resultSprite_, 1000); // �Q�[���I�[�o�[��ʂ̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&jonin_resultSprite_, 1000); // �Q�[���I�[�o�[��ʂ̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddSprite(&sakanin_resultSprite_, 1000); // �Q�[���I�[�o�[��ʂ̃X�v���C�g�������_�����O�p�X�ɒǉ�
	RenderingPath->AddFont(&gameOverTime_, 1000); // �Q�[���I�[�o�[�̃t�H���g�������_�����O�p�X�ɒǉ�

}

void GameOverView::Initialize()
{
	genin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // �Q�[���I�[�o�[��ʂ̃T�C�Y��ݒ�
	tyunin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // �Q�[���I�[�o�[��ʂ̃T�C�Y��ݒ�
	jonin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // �Q�[���I�[�o�[��ʂ̃T�C�Y��ݒ�
	sakanin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // �Q�[���I�[�o�[��ʂ̃T�C�Y��ݒ�
	gameOverTime_.params.size = 144; // �Q�[���I�[�o�[�̃t�H���g�̃T�C�Y��ݒ�
	gameOverTime_.params.posX = 540.0f; // �Q�[���I�[�o�[�̃t�H���g�̈ʒu��ݒ�
	gameOverTime_.params.posY = 250.0f; // �Q�[���I�[�o�[�̃t�H���g�̈ʒu��ݒ�

    HideGameOver(); // �Q�[���I�[�o�[��ʂ��\���ɂ���
}

void GameOverView::ShowGameOver(int gameState, float aliveTime)
{
	int aliveTimeInt = static_cast<int>(aliveTime); // aliveTime��int�ɕϊ�
	switch (gameState)
	{
	case 0:
		break;
	case 1: // �Q�[���I�[�o�[���1
		
		if (aliveTime < 20.0f) {
			if (aliveTime < 10.0f) {
				gameOverTime_.params.posX = 580.0f;
			}
			genin_resultSprite_.SetHidden(false); // �Q�[���I�[�o�[��ʂ�\��
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // �Q�[���I�[�o�[�̃t�H���g��\��
			break;
		}
		else if (aliveTime < 40.0f) {
			tyunin_resultSprite_.SetHidden(false); // �Q�[���I�[�o�[��ʂ�\��
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // �Q�[���I�[�o�[�̃t�H���g��\��
			break;
		}
		else if (aliveTime < 60.0f) {
			jonin_resultSprite_.SetHidden(false); // �Q�[���I�[�o�[��ʂ�\��
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // �Q�[���I�[�o�[�̃t�H���g��\��
			break;
		}
	
	case 2:
		sakanin_resultSprite_.SetHidden(false);
		gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
		gameOverTime_.SetHidden(false); // �Q�[���I�[�o�[�̃t�H���g��\��
		break;
	case 3:
		break;
	}

}

void GameOverView::HideGameOver()
{
	genin_resultSprite_.SetHidden(true); 
	tyunin_resultSprite_.SetHidden(true); 
	jonin_resultSprite_.SetHidden(true); 
	sakanin_resultSprite_.SetHidden(true); 
	gameOverTime_.SetHidden(true); // �Q�[���I�[�o�[�̃t�H���g���\���ɂ���
}
