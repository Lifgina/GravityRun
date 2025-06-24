//
// GameManager.cpp
//

#include "GameManager.h"
#include <array>

using namespace HE;

void GameManager::Load()
{
	playerModel_.Load();
	timerModel_.Load();
	
}

void GameManager::Initialize()
{
	playerModel_.Initialize(initialPlayerPosition_, leftEdge, rightEdge); 
	timerModel_.Initialize(timeLimit_);
}
void GameManager::FloorSetup(int floorID, HE::Math::Vector2 floorPos, float floorHeight, float floorWidth)
{ 
	floorModel_[floorID].Initialize(floorPos, floorWidth, floorHeight);
}

void GameManager::Update()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < std::size(floorModel_); i++)
	{
		Math::Rectangle floor_collision = floorModel_[i].GetCollision();
		if (player_collision.Intersects(floor_collision))
		{ 
			playerModel_.OnCollisionGround(floorModel_[i].GetFloorPosition(), floorModel_[i].GetFloorHeight(),floorModel_[i].GetFloorWidth());
		}
	}
	playerModel_.Update();
	timerModel_.Update();

}