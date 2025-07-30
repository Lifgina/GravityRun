//
// TitleScene.cpp
//

#include "TitleScene.h"

using namespace HE;

// initialize member variables.
TitleScene::TitleScene()
{

}

// rearrange UI to fit the size.
void TitleScene::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void TitleScene::Load()
{
    bg_.Load();
	markerView_.Load();
	tutorialView_.Load(); // �`���[�g���A���r���[�̃��[�h
	bgmManager_.Load();
	seManager_.Load();

    Scene::Load();
}

// initialize a variables.
void TitleScene::Initialize()
{
    bg_.Initialize();
	tutorialView_.Initialize(); // �`���[�g���A���r���[�̏�����
	selectedMenu_ = 0; // �����I�����j���[�́uStart�v
	prevSelectedMenu_ = selectedMenu_; // �O��I�����ꂽ���j���[��������
	isSceMovingToMain_ = false; // ���C���V�[���Ɉړ����ł͂Ȃ�
	bgmManager_.PlayBGMFromTop(1); // �^�C�g����ʂ�BGM���Đ�

}

// releasing resources required for termination.
void TitleScene::Terminate()
{

}

// updates the scene.
void TitleScene::Update(float deltaTime)
{
	switch (titleState_)
	{
	case 0: // ���j���[�I�����
		SelectMenu();
		MarkerUpdate(); // �}�[�J�[�̍X�V
		break;
	case 1: // �`���[�g���A���\�����
		tutorialView_.Update(true); // �`���[�g���A���r���[��\��
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			seManager_.PlaySE(0); 
			tutorialView_.Update(false); // �`���[�g���A���r���[���\��
			titleState_ = 0; // Enter�L�[�������ꂽ�烁�j���[�I����Ԃɖ߂�
		}
	}
	if (prevSelectedMenu_ != selectedMenu_) {
		seManager_.PlaySE(1); // ���j���[���ύX���ꂽ��SE���Đ�
		prevSelectedMenu_ = selectedMenu_; // �O��I�����ꂽ���j���[���X�V
	}

    Scene::Update(deltaTime);
}

void TitleScene::SelectMenu()
{
	if (isSceMovingToMain_) return; // ���C���V�[���Ɉړ����̏ꍇ�̓��j���[�I���𖳌���	
    if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
		selectedMenu_--; // ��L�[�Ń��j���[����Ɉړ�
		
    }
    if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
        selectedMenu_++; // ���L�[�Ń��j���[�����Ɉړ�
    }
	if (selectedMenu_ <= 0)
	{
		selectedMenu_ = 0; // �����0�ɐ���
	}
	if (selectedMenu_ >= menuCount_)
	{
		selectedMenu_ = menuCount_ -1; // ���������j���[��-1�ɐ���
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
		if (selectedMenu_ == 0) {
			seManager_.PlaySE(2); 
			isSceMovingToMain_ = true; // ���C���V�[���Ɉړ����ł��邱�Ƃ�����
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		else if (selectedMenu_ == 1) {
			seManager_.PlaySE(0); // �`���[�g���A���I������SE���Đ�
			titleState_ = 1; // �`���[�g���A���\����ԂɕύX
		}
		else if (selectedMenu_ == 2) {
			// Exit logic can be added here, such as closing the application
			seManager_.PlaySE(0); 
			wi::jobsystem::ShutDown();
			PostQuitMessage(0);
		}
	}

}

void TitleScene::MarkerUpdate()
{
	switch (selectedMenu_)
	{
	case 0:
		markerView_.UpdateMarker(Math::Vector2(257.0-135.0f, 438.5+42.0-23.0f)); // Start menu position
		break;
	case 1:
		markerView_.UpdateMarker(Math::Vector2(285.5-135.0f,531.5+35.0-23.0f)); // Tutorial menu position
		break;
	case 2:
		markerView_.UpdateMarker(Math::Vector2(285.5-135.0f, 614.5+35.0-23.0f)); // Exit menu position
		break;
	}
}
