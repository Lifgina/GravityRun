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
	tutorialView_.Load(); // チュートリアルビューのロード

    Scene::Load();
}

// initialize a variables.
void TitleScene::Initialize()
{
    bg_.Initialize();
	tutorialView_.Initialize(); // チュートリアルビューの初期化
	selectedMenu_ = 0; // 初期選択メニューは「Start」
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
	case 0: // メニュー選択状態
		SelectMenu();
		MarkerUpdate(); // マーカーの更新
		break;
	case 1: // チュートリアル表示状態
		tutorialView_.Update(true); // チュートリアルビューを表示
		if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
			tutorialView_.Update(false); // チュートリアルビューを非表示
			titleState_ = 0; // Enterキーが押されたらメニュー選択状態に戻る
		}
	}


    Scene::Update(deltaTime);
}

void TitleScene::SelectMenu()
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
		selectedMenu_--; // 上キーでメニューを上に移動
    }
    if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
        selectedMenu_++; // 下キーでメニューを下に移動
    }
	if (selectedMenu_ <= 0)
	{
		selectedMenu_ = 0; // 上限を0に制限
	}
	if (selectedMenu_ >= menuCount_)
	{
		selectedMenu_ = menuCount_ -1; // 下限をメニュー数-1に制限
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
		if (selectedMenu_ == 0) {
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		else if (selectedMenu_ == 1) {
			titleState_ = 1; // チュートリアル表示状態に変更
		}
		else if (selectedMenu_ == 2) {
			// Exit logic can be added here, such as closing the application
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
