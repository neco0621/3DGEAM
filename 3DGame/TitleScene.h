#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
public:
    TitleScene(SceneManager& mgr);
    ~TitleScene();

    void Init();
    void Update(Input& input);
    void Draw();

private:

    float m_frame;

    int m_handle;
};

