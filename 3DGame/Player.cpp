//ヘッダーファイルのインクルード
#include "Player.h"
#include "Game.h"

namespace
{
	//スピード
	constexpr float kSpeed	= 7.0f;
	//半径
	constexpr float kRadius = 70.0f;
	//モデルのサイズ
	constexpr float kScale	= 0.5f;
	//描画ずれの修正
	constexpr float kDefference = 50;
	//描画位置
	constexpr float kDrawPos = 80;
}

Player::Player() :
	//初期化
	m_modelHandle(-1),
	m_radius(kRadius),
	m_pos(VGet(540,0,360)),
	m_speed(kSpeed),
	m_scale(kScale),
	m_playTime(0.0f)
{
	m_attachIndex = MV1AttachAnim(m_modelHandle, 11, -1);
	m_tottalTime = MV1GetAttachAnimTotalTime(m_modelHandle,m_attachIndex);
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
	//SetData(m_data[m_usedataName]);
}

Player::~Player()
{
}

void Player::Init()
{
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

void Player::Update()
{
	m_playTime += 100.0f;
	//プレイヤーの移動
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, m_speed));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, m_speed));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(m_speed, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(m_speed, 0, 0));
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

	// アニメーション再生時間がアニメーションの総時間を越えていたらループさせる
	if (m_playTime >= m_tottalTime)
	{
		// 新しいアニメーション再生時間は、アニメーション再生時間からアニメーション総時間を引いたもの
		m_playTime -= m_tottalTime;
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
	//当たり判定の円を作成
	m_col.SetRadius3D(m_pos.x, m_pos.y + kDefference, m_pos.z, m_radius);
	
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
}

void Player::Draw()
{
	//モデルの描画
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(kDrawPos, kDrawPos, 0xffffff, "プレイヤーの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_col.DrawBall(0xff0000, 0xff0000, false);
#endif
}

void Player::SetData(DataLoader::Data inputData)
{
	m_pos.x = inputData.startPos.x;
	m_pos.z = inputData.startPos.z;
	m_speed = inputData.speed;
}
