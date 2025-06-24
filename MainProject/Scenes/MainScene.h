#pragma once

#include "../HuEngine.h"
#include "../Class/Model/GameManager.h"
#include "../Class/Model/FloarData.h"

class MainScene : public HE::Scene
{
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:

	GameManager gameManager_; // �Q�[���}�l�[�W���[�̃C���X�^���X
	FloorData floorData_; // ���f�[�^�̃C���X�^���X

};
