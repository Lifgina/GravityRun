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
	MarkerView markerView_; // メニュー選択用のマーカー	
	TutorialView tutorialView_; // チュートリアル表示用のビュー
	SEmanager seManager_; // SE管理
	BGMmanager bgmManager_; // BGM管理
	int selectedMenu_; // 0: Start, 1: Tutorial, 2: Exit
	int menuCount_ = 3; // メニューの数
	int titleState_ = 0; // タイトル画面の状態（0: メニュー選択, 1: チュートリアル表示)
	bool isSceMovingToMain_ ; // メインシーンに移動中かどうか
	int prevSelectedMenu_ ; // 前回選択されたメニューを記録する変数

	
};
