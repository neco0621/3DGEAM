#include "Player.h"
#include "Pad.h"
#include "Game.h"

Player::Player() :
	m_pos(VGet(Game::kScreenWidth / 2, 0.0f, Game::kScreenHeight / 2)),
	m_modelHandle(-1)
{
	m_modelHandle = MV1LoadModel("data/Character.mv1");
}

Player::~Player()
{
}

void Player::Init()
{
	MV1SetScale(m_modelHandle, VGet(0.5f, 0.5f, 0.5f));
	SetUseLighting(FALSE);
}

void Player::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, 5));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, 5));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(5, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(5, 0, 0));
	}


	if (m_pos.x > Game::kScreenWidth)
	{
		m_pos = VGet(Game::kScreenWidth, m_pos.y, m_pos.z);
	}
	
	if (m_pos.x < 0)
	{
		m_pos = VGet(0, m_pos.y, m_pos.z);
	}

	if (m_pos.z > Game::kScreenHeight)
	{
		m_pos = VGet(m_pos.x, m_pos.y, Game::kScreenHeight);
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
