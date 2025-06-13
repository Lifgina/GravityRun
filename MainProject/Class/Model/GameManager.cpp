//
// GameManager.cpp
//

#include "GameManager.h"

using namespace HE;

void GameManager::Load()
{
	playerModel_.Load();
	floorData_.Load();
}

void GameManager::Initialize()
{
	playerModel_.Initialize(initialPlayerPosition_);
}

void GameManager::Update()
{
	playerModel_.Update();
}