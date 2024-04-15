#pragma once
#pragma once
#include "SceneBase.h"
class ClearScene :public SceneBase
{
public:
	ClearScene();
	~ClearScene();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();

private:
	int m_frameCount;
	int m_ClearHandle;
};