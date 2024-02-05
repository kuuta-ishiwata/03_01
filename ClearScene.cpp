#include "ClearScene.h"
#include "Novice.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{
		sceneNo = Title;
	}

	Novice::ScreenPrintf(640, 360, "GameClear");
}

void ClearScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
}
