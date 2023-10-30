#include "ClearScene.h"
#include <Novice.h>
void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (InputManager::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(620, 360, "CLEAR");
}
