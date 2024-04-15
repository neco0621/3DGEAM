#pragma once
#include "Scene.h"

/// <summary>
/// �^�C�g���V�[���N���X
/// </summary>
class Player;
class GamePlayingScene : public Scene
{

public:
	GamePlayingScene(SceneManager& manager);
	~GamePlayingScene();
	void Init();
	void Update(Input& input);
	void Draw();

private:

	//�O���t�B�b�N�n���h��
	int m_bgHandle;			//�w�i�̃n���h��
	int frame_;				//�t�F�C�h�Ɋւ���t���[��
	int m_bgPosX;			//�w�i�̕`��ʒu

	Player* m_pPlayer;

};