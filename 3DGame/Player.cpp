//ヘッダーファイルのインクルード
#include "Player.h"
#include "Pad.h"
#include "Game.h"

Player::Player() :
	//初期化
	m_pos(VGet(Game::kScreenWidth / 2, 0.0f, Game::kScreenHeight / 2)),
	m_modelHandle(-1),
	m_radius(70)
{
	//モデルをロード
	m_modelHandle = MV1LoadModel("data/model/Character.mv1");
}

Player::~Player()
{
}

void Player::Init()
{
	//モデルのサイズを調整
	MV1SetScale(m_modelHandle, VGet(0.5f, 0.5f, 0.5f));
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

void Player::Update()
{

	//プレイヤーの移動
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, 7));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, 7));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(7, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(7, 0, 0));
	}


	//プレイヤーが画面外に行かないように座標を設定
	if (m_pos.x > Game::kScreenWidth - m_radius)
	{
		m_pos = VGet(Game::kScreenWidth - m_radius, m_pos.y, m_pos.z);
	}
	if (m_pos.x < 0 + m_radius)
	{
		m_pos = VGet(0 + m_radius, m_pos.y, m_pos.z);
	}
	if (m_pos.z > Game::kScreenHeight - m_radius)
	{
		m_pos = VGet(m_pos.x, m_pos.y, Game::kScreenHeight - m_radius);
	}
	if (m_pos.z < 0 + m_radius)
	{
		m_pos = VGet(m_pos.x, m_pos.y, 0 + m_radius);
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
	//当たり判定の円を作成
	m_colRect.SetRadius3D(m_pos.x,m_pos.y + 50,m_pos.z,m_radius);
}

void Player::Draw()
{
	//モデルの描画
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 80, GetColor(255, 255, 255), "プレイヤーの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_colRect.DrawBall(GetColor(255, 0, 0), GetColor(255, 0, 0), false);
#endif
}
