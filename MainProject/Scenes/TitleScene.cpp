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

    Scene::Load();
}

// initialize a variables.
void TitleScene::Initialize()
{
    bg_.Initialize();
	selectedMenu_ = 0; // �����I�����j���[�́uStart�v
}

// releasing resources required for termination.
void TitleScene::Terminate()
{

}

// updates the scene.
void TitleScene::Update(float deltaTime)
{
	SelectMenu();
	MarkerUpdate(); // �}�[�J�[�̍X�V

    Scene::Update(deltaTime);
}

void TitleScene::SelectMenu()
{
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
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		else if (selectedMenu_ == 1) {
			// Tutorial scene transition logic can be added here
		}
	}
}

void TitleScene::MarkerUpdate()
{
	switch (selectedMenu_)
	{
	case 0:
		markerView_.UpdateMarker(Math::Vector2(240.0f, 535.0f)); // Start menu position
		break;
	case 1:
		markerView_.UpdateMarker(Math::Vector2(240.0f,645.0f)); // Tutorial menu position
		break;
	}
}
