#pragma once
#include "Scene.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
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
	int BallMax = 1;

	Player* m_pPlayer;

	Camera* m_pCamera;

	std::vector<SoccerBall*> m_pBall;
};

