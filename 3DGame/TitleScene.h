#pragma once
#include "Scene.h"
#include <DxLib.h>

class TitleScene :  public Scene
{
public:
    TitleScene(SceneManager& mgr);
    ~TitleScene();

    void Init();
    void Update(Input& input);
    void Draw();

private:
    //背景のハンドル
    int m_bgHandle;
    //タイトルの文字のハンドル
    int m_titleRogo;
    //表示座標
    VECTOR m_pos;
    //上下の切り替えフラグ
    bool m_moveFlag;
};