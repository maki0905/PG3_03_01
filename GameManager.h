#pragma once

#include <memory>

#pragma region シーン
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#pragma endregion 

class GameManager
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameManager();

	int Run();

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[COUNT];

	// シーン管理用の変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン

};

