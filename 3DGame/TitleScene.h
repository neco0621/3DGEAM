#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
public:
    TitleScene(SceneManager& mgr);
    ~TitleScene();

    void Init();
    void Update();
    void Draw();

private:


};

