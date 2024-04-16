#include "Bee.h"
#include "DxLib.h"

namespace
{
	constexpr int kRectPosY = 100;
}

Bee::Bee(int m_handle, VECTOR pos):EnemyBase(m_handle, pos),
m_handle(-1)
{
}

Bee::~Bee()
{

}
void Bee::Update()
{
	// ３Dモデルのポジション設定
	MV1SetPosition(m_handle, m_pos);

	//当たり判定の更新
	m_colRecto.SetCenter(m_pos.x, m_pos.y+ kRectPosY, m_pos.z, 40, 60);
}
