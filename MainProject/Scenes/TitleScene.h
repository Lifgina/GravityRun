#pragma once

#include "../HuEngine.h"
#include "../Class/View/TitleBG.h"
#include "../Class/View/MarkerView.h"
#include "../Class/View/TutorialView.h"
#include "../Class/View/SEmanager.h"
#include "../Class/View/BGMmanager.h"

class TitleScene : public HE::Scene
{
public:
	TitleScene();
	virtual ~TitleScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;
	void SelectMenu();
	void MarkerUpdate();

private:

	TitleBG bg_;
	MarkerView markerView_; // ���j���[�I��p�̃}�[�J�[	
	TutorialView tutorialView_; // �`���[�g���A���\���p�̃r���[
	SEmanager seManager_; // SE�Ǘ�
	BGMmanager bgmManager_; // BGM�Ǘ�
	int selectedMenu_; // 0: Start, 1: Tutorial, 2: Exit
	int menuCount_ = 3; // ���j���[�̐�
	int titleState_ = 0; // �^�C�g����ʂ̏�ԁi0: ���j���[�I��, 1: �`���[�g���A���\��)
	bool isSceMovingToMain_ ; // ���C���V�[���Ɉړ������ǂ���
	int prevSelectedMenu_ ; // �O��I�����ꂽ���j���[���L�^����ϐ�

	
};
