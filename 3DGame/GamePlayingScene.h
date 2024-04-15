#pragma once
#include "Scene.h"

/// <summary>
/// タイトルシーンクラス
/// </summary>
class Player;
class GamePlayingScene : public Scene
{

public:
	GamePlayingScene(SceneManager& manager);
	~GamePlayingScene();
	void Init();
	void Update(Input& input);
	void Draw();

private:

	//グラフィックハンドル
	int m_bgHandle;			//背景のハンドル
	int frame_;				//フェイドに関するフレーム
	int m_bgPosX;			//背景の描画位置

	Player* m_pPlayer;

};