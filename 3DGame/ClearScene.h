#pragma once
#include "Scene.h"
#include <DxLib.h>

class ClearScene :  public Scene
{
public:
    ClearScene(SceneManager& mgr);
    ~ClearScene();

    void Init();
    void Update(Input& input);
    void Draw();

private:

    float m_frame;
    //背景のハンドル
    int m_bgHandle;
    //クリア文字のハンドル
    int m_rogoHandle;
};