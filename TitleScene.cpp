#include "TitleScene.h"
#include <Novice.h>
void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (InputManager::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo_ = GAME_STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(620, 360, "TITLE");
}
