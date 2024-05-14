#include "Player.h"
#include "Pad.h"

Player::Player() :
	m_pos(VGet(540.0f, 0.0f, 360.0f)),
	m_modelHandle(-1)
{
	m_modelHandle = MV1LoadModel("data/Character.mv1");
}

Player::~Player()
{
}

void Player::Init()
{
	ChangeLightTypeDir(VGet(-2.0f, 0.0f, -1.0f));
}

void Player::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, 4));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, 4));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(4, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(4, 0, 0));
	}


	if (m_pos.x > 1080)
	{
		m_pos = VGet(1080, m_pos.y, m_pos.z);
	}
	
	if (m_pos.x < 0)
	{
		m_pos = VGet(0, m_pos.y, m_pos.z);
	}

	if (m_pos.z > 720)
	{
		m_pos = VGet(m_pos.x, m_pos.y, 720);
	}

	if (m_pos.z < 0)
	{
		m_pos = VGet(m_pos.x, m_pos.y, 0);
	}
	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
}

void Player::Draw()
{
	MV1DrawModel(m_modelHandle);

	DrawFormatString(80, 80, GetColor(255, 255, 255), "プレイヤーの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
}
