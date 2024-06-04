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
	Player* m_pPlayer;
	//�J����
	Camera* m_pCamera;
	//�{�[��
	SoccerBall* m_pBall;
	//�����蔻��
	Rect m_pRect;
	//�w�i
	Bg* m_pBg;

	DataLoader* m_pDataLoader;
	//�Q�[���I�[�o�[�̃t���O
	bool m_gameOverFlag;

	//�w�i�̃n���h��
	int m_handle;

	int m_groundModel;
	//�o�ߎ���
	float m_timer;
};

