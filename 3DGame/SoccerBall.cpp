#include "SoccerBall.h"
#include "Game.h"

namespace
{
	constexpr float kRadius				= 100.0f;
	constexpr float kScale				= 100.0f;
	constexpr float kCourveAdjustment	= 150.0f;
	constexpr float kMaxTimer			= 1800.0f;
	constexpr float kMaxCourvePower		= 10.0f;
	constexpr float kPosX				= 540.0f;
	constexpr float kPosZ				= 1500.0f;
	constexpr float kMaxRotation		= 360.0f;
	constexpr float kMinPosZ			= 30.0f;
}

SoccerBall::SoccerBall() :
	//初期化
	m_modelHandle(-1),
	m_curvePower(0),
	m_pos(VGet(kPosX, 0.0f, kPosZ)),
	m_radius(kRadius),
	m_speed(15.0f),
	m_timer(1800.0f),
	m_maxTimer(kMaxTimer),
	m_maxCourvePower(10.0f),
	m_scale(kScale),
	m_rotation(VGet(0,0,0)),
	m_rotatePower(0.0f),
	m_courveAdjustment(kCourveAdjustment),
	m_maxRotation(kMaxRotation)
{
}

SoccerBall::~SoccerBall()
{
}

void SoccerBall::Init()
{
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

void SoccerBall::Update()
{
	m_timer--;
	//残り時間によって速さを変える
	if (m_timer < (m_maxTimer / 3) * 2)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 1.5f));
		m_rotation = VAdd(m_rotation, VGet(0.15f, m_curvePower / m_courveAdjustment, 0));
	}
	else if (m_timer < m_maxTimer / 3)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 2.0f));
		m_rotation = VAdd(m_rotation, VGet(0.2f, m_curvePower / m_courveAdjustment, 0));
	}
	else
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed));
		m_rotation = VAdd(m_rotation, VGet(0.1f, m_curvePower / m_courveAdjustment, 0));
	}

	//画面外に行ったら初期位置(X座標はランダム)に戻す
	if (m_pos.z < -kMinPosZ)
	{
		m_pos = VGet(GetRand(720), 0.0f, 2000.0f);

		//ランダムに敵を選択
		switch (GetRand(2))		//0 or 1 or 2
		{
		case 0:		
			m_curvePower = GetRand(-m_maxCourvePower);
			break;
		case 1:		
			m_curvePower = GetRand(m_maxCourvePower);
			break;
		}
	}

	//回転角度が360になったら0度に戻す
	if (m_rotation.x > m_maxRotation)
	{
		m_rotation.x = 0;
	}
	if (m_rotation.y > m_maxRotation)
	{
		m_rotation.y = 0;
	}

	//跳ね返ったときに力を反転させる
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
	//モデルの角度調整
	MV1SetRotationXYZ(m_modelHandle, m_rotation);
	//当たり判定の更新
	m_col.SetRadius3D(m_pos.x, m_pos.y, m_pos.z, m_radius);
}

void SoccerBall::Draw()
{
	//モデルの描画
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 120, 0xffffff, "ボールの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_col.DrawBall(0xff0000, 0xff0000, false);
#endif
}
