//
// TimerModel.cpp
//

#include "TimerModel.h"

using namespace HE;


void TimerModel::Initialize(float timeLimit)
{
	timer_ = 0.0f; // タイマーの初期化
	timeLimit_ = timeLimit; // タイムリミットの設定
}

void TimerModel::Update()
{
	timer_ += Time.deltaTime; // タイマーを更新
}
