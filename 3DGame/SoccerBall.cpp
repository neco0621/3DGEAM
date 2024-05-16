#include "SoccerBall.h"

SoccerBall::SoccerBall() :
	m_modelHandle(-1),
	m_isExist(false),
	m_pos(VGet(540.0f, 0.0f, 1500.0f)),
	m_radius(150.0f)
{
	
}

SoccerBall::~SoccerBall()
{
}

void SoccerBall::Init()
{
	m_modelHandle = MV1LoadModel("data/SoccerBall.mv1");
	MV1SetScale(m_modelHandle, VGet(150.0f, 150.0f, 150.0f));
}

void SoccerBall::Update()
{
	m_pos = VSub(m_pos, VGet(0, 0, 15));

	if (m_pos.z < 0)
	{
		m_pos = VGet(GetRand(720), 0.0f, 1500.0f);
	}
	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
}

void SoccerBall::Draw()
{
	MV1DrawModel(m_modelHandle);
	DrawFormatString(80, 120, GetColor(255, 255, 255), "ボールの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
}
