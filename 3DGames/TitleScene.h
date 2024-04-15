#pragma once
#include "SceneBase.h"
class TitleScene : public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();

	int m_TitleHandle;
private:
};

