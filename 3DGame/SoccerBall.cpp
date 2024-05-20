#include "SoccerBall.h"
#include "Game.h"
#include "Timer.h"

SoccerBall::SoccerBall() :
	m_modelHandle(-1),
	m_curvePower(0),
	m_pos(VGet(540.0f, 0.0f, 1500.0f)),
	m_radius(100.0f),
	m_speed(15.0f),
	m_timer(1800.0f),
	m_maxCourvePower(10.0f),
	m_scale(100.0f)
{
}

SoccerBall::~SoccerBall()
{
}

void SoccerBall::Init()
{
	m_modelHandle = MV1LoadModel("data/SoccerBall.mv1");
	MV1SetScale(m_modelHandle, VGet(m_scale, m_scale, m_scale));
}

void SoccerBall::Update()
{
	m_timer--;
	if (m_timer > (m_timer / 3) * 2)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed));
	}
	else if (m_timer < m_timer / 3)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 2.0f));
	}
	else
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 1.5f));
	}

	if (m_pos.z < -300)
	{
		m_pos = VGet(GetRand(720), 0.0f, 2000.0f);

		//ランダムに敵を選択
		switch (GetRand(2))		//0 or 1 or 2
		{
		case 0:		//Left
			m_curvePower = GetRand(-m_maxCourvePower);
			break;
		case 1:		//Right
			m_curvePower = GetRand(m_maxCourvePower);
			break;
		}
	}

	if (m_pos.x < 0)
	{
		m_curvePower = -m_curvePower;
	}

	if (m_pos.x > Game::kScreenWidth - m_radius)
	{
		m_curvePower = -m_curvePower;
	}


	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
	m_colRect.SetRadius3D(m_pos.x, m_pos.y, m_pos.z, m_radius);
}

void SoccerBall::Draw()
{
	//モデルの描画
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 120, GetColor(255, 255, 255), "ボールの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_colRect.DrawBall(GetColor(255, 0, 0), GetColor(255, 0, 0), false);
#endif
}
