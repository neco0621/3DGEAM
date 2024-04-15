#pragma once
#include "Scene.h"

/// <summary>
/// �^�C�g���V�[���N���X
/// </summary>
class GamePlayingScene : public Scene
{

public:
	GamePlayingScene(SceneManager& manager);
	~GamePlayingScene();
	void Init();
	void Update(Input& input);
	void Draw();

private:
	//�X�V�����o�֐��|�C���^
	void (GamePlayingScene::* updateFunc_)(Input& input);
	//�`�惁���o�֐��|�C���^
	using DrawFunc_t = void (GamePlayingScene::*) ();
	DrawFunc_t drawFunc_;
	//�X�V�֐�
	void FadeInUpdate(Input& input);	//�t�F�[�h�C�����
	void NormalUpdate(Input& input);	//�ʏ���
	void FadeOutUpdate(Input& input);	//�t�F�[�h�A�E�g���

	//�`��֐�
	void FadeDraw();	//�t�F�[�h���`��
	void NormalDraw();	//��t�F�[�h�`��

	//�O���t�B�b�N�n���h��
	int m_bgHandle;			//�w�i�̃n���h��
	int m_titleHandle;		//�^�C�g���̃A�C�R���̃n���h��
	int m_shakeHandle;		//��ʗh��̃n���h��
	int m_titleButton;		//START�{�^���̃n���h��
	int frame_;				//�t�F�C�h�Ɋւ���t���[��
	int m_bgPosX;			//�w�i�̕`��ʒu

	//�T�E���h
	int m_bgm;				//BGM
	int CheckSE;			//START�{�^�����������Ƃ��̃T�E���h

};

