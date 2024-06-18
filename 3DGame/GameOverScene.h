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

    float m_frame;
    //
    int m_handle;
    //ゲームオーバーのロゴのハンドル
    int m_rogoHandle;
};