#pragma once
#include "Scene.h"
#include <DxLib.h>

class ClearScene :
    public Scene
{
public:
    ClearScene(SceneManager& mgr);
    ~ClearScene();

    void Init();
    void Update(Input& input);
    void Draw();

private:

    float m_frame;

    int m_handle;
};