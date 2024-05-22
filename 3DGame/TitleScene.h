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
    //�X�V�����o�֐��|�C���^
    void (TitleScene::* updateFunc_)(Input& input);
    //�`�惁���o�֐��|�C���^
    using DrawFunc_t = void(TitleScene::*) ();
    DrawFunc_t drawFunc_;
    //�X�V�֐�
    void FadeInUpdate(Input& input);
    void NormalUpdate(Input& input);
    void FadeOutUpdate(Input& input);

    //�`��֐�
    void FadeDraw();    //�t�F�[�h���`��
    void NormalDraw();  //��t�F�[�h�`��

    float m_frame;

    int m_handle;
};

