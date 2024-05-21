#pragma once
#include "Scene.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class Timer;
class SoccerBall;
class Bg;
class ReadCsv;

class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	~SceneMain();
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
	//�^�C�}�[
	Timer* m_pTimer;
	//�����蔻��
	Rect m_pRect;
	//�w�i
	Bg* m_pBg;
	//CSV�t�@�C��
	ReadCsv* m_pRead;

	bool m_gameOverFlag;
};

