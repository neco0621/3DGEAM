#pragma once
#include "Scene.h"
#include <DxLib.h>

class GameOverScene :   public Scene
{
public:
    GameOverScene(SceneManager& mgr);
    virtual ~GameOverScene();

    void Init();
    void Update(Input& input);
    void Draw();

private:
    //背景ハンドル
    int m_handle;
    //ゲームオーバーのロゴのハンドル
    int m_rogoHandle;
};