#include "DxLib.h"
#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Input.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//画面モードのセット
	ChangeWindowMode(TRUE);
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 一部の関数はDxLib_Init()の前に実行する必要がある
	SetDrawScreen(DX_SCREEN_BACK);	// 裏画面を描画対象にする
	SetUseZBufferFlag(TRUE);		// Ｚバッファを使用する
	SetWriteZBufferFlag(TRUE);		// Ｚバッファへの書き込みを行う
	SetUseBackCulling(TRUE);		// バックカリングを行う

	SceneManager manager;
	manager.ChangeScene(std::make_shared<TitleScene>(manager));
	Input input;

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();
		
		input.Update();
		manager.Update(input);
		manager.Draw();

		// 画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60固定にする
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}