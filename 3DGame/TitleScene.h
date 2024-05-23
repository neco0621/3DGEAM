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
    //更新メンバ関数ポインタ
    void (TitleScene::* updateFunc_)(Input& input);
    //描画メンバ関数ポインタ
    using DrawFunc_t = void(TitleScene::*) ();
    DrawFunc_t drawFunc_;
    //更新関数
    void FadeInUpdate(Input& input);
    void NormalUpdate(Input& input);
    void FadeOutUpdate(Input& input);

    //描画関数
    void FadeDraw();    //フェード中描画
    void NormalDraw();  //非フェード描画

    float m_frame;

    int m_handle;
};

