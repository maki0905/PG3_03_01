#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2A19_マキ_ユキノリ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

 	InputManager* input = nullptr;
	input = InputManager::GetInstance();
	input->Initialize();

	std::unique_ptr<GameManager> gameManager;
	gameManager = std::make_unique<GameManager>();
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
