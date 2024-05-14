#include "SoccerBall.h"

SoccerBall::SoccerBall() :
	m_modelHandle(-1),
	//m_isExist(false),
	m_pos(VGet(540.0f,0.0f,720.0f))
{
	m_isExist = true;
}

SoccerBall::~SoccerBall()
{
}

void SoccerBall::Init()
{
	//m_modelHandle = MV1LoadModel("SoccerBall.mv1");
	ChangeLightTypeDir(VGet(-2.0f, 0.0f, -1.0f));
}

void SoccerBall::Update()
{
	//m_pos = VSub(m_pos, VGet(0, 0, 3));

	if (m_pos.z < 0)
	{
		//m_isExist = false;
	}
}

void SoccerBall::Draw()
{
	//MV1DrawModel(m_modelHandle);
}
