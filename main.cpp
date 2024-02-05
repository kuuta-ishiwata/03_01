#include <Novice.h>
#include "GameManager.h"
const char kWindowTitle[] = "LE2C_02_イシワタクウタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱

	GameManager* gameManager = new GameManager();

	gameManager->Loop();

	delete gameManager;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
