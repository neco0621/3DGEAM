#pragma once
#include "Scene.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class SoccerBall;
class Bg;
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
	std::shared_ptr<Rect> m_pRect;
	//�w�i
	std::shared_ptr<Bg> m_pBg;

	std::shared_ptr<DataLoader> m_pDataLoader;
	//�Q�[���I�[�o�[�̃t���O
	bool m_gameOverFlag;

	bool m_gameClearFlag;
	//�w�i�̃n���h��
	int m_handle;

	int m_groundModel;
	//�o�ߎ���
	float m_timer;
};

