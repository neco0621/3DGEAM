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
class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	~SceneMain();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:

	Player* m_pPlayer;

	Camera* m_pCamera;

	SoccerBall* m_pBall;

	Timer* m_pTimer;

	Rect m_pRect;

	bool m_gameOverFlag;
};

