#pragma once
#pragma once
#include "SceneBase.h"
class GameOverScene :public SceneBase
{
public:
	GameOverScene();
	~GameOverScene();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();

private:
	int m_frameCount;
	int m_GameOverHandle;
};