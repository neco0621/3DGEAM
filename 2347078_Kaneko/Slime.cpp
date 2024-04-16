#include "Slime.h"

Slime::Slime(int m_handle, VECTOR pos):EnemyBase(m_handle, pos),
m_handle(-1)
{
	m_pos = pos;
}

Slime::~Slime()
{
}
void Slime::Update()
{
	// ３Dモデルのポジション設定
	MV1SetPosition(m_handle, m_pos);

	//当たり判定の更新
	m_colRecto.SetCenter(m_pos.x, m_pos.y, m_pos.z, 40, 60);
}
