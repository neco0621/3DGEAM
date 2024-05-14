#pragma once
#include "DxLib.h"

class SoccerBall
{
public:
	SoccerBall();
	~SoccerBall();

	void Init();
	void Update();
	void Draw();

private:
	int m_modelHandle;

	VECTOR m_pos;

	bool m_isExist;

};

