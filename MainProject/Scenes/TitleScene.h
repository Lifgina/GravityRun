#pragma once

#include "../HuEngine.h"
#include "../Class/View/TitleBG.h"
#include "../Class/View/MarkerView.h"

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
	void SelectMenu() ;
	void MarkerUpdate();

private:

	TitleBG bg_;
	MarkerView markerView_; // メニュー選択用のマーカー	
	int selectedMenu_ ; // 0: Start, 1: Tutorial
	int menuCount_ = 2; // メニューの数
};
