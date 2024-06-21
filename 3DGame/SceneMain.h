#pragma once
#include "Scene.h"
#include "Collision.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class SoccerBall;
class DataLoader;
class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	virtual ~SceneMain();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:
	//�v���C���[
	std::shared_ptr<Player> m_pPlayer;
	//�J����
	std::shared_ptr<Camera> m_pCamera;
	//�{�[��
	std::shared_ptr<SoccerBall> m_pBall;
	//�����蔻��
	std::shared_ptr<Collision> m_pCol;

	std::shared_ptr<DataLoader> m_pDataLoader;
	//�Q�[���I�[�o�[�̃t���O
	bool m_gameOverFlag;
	//�Q�[���N���A�̃t���O
	bool m_gameClearFlag;
	//�w�i�̃n���h��
	int m_handle;
	//�v���C���[�̃��f��
	int m_playerHandle;
	//�T�b�J�[�{�[���̃��f��
	int m_ballHandle;
	//�n�ʂ̃��f��
	int m_groundModel;
	//�o�ߎ���
	float m_timer;
};

