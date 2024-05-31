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
    //�w�i�̃n���h��
    int m_bgHandle;
    //�^�C�g���̕����̃n���h��
    int m_titleRogo;
    //�\�����W
    VECTOR m_pos;
    //�㉺�̐؂�ւ��t���O
    bool m_moveFlag;
};