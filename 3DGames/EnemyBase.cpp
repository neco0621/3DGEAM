#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase(int ModelHandle, VECTOR pos):m_pos(pos)
{
	m_handle = MV1DuplicateModel(ModelHandle);	
}

EnemyBase::~EnemyBase()
{
	// モデルのアンロード.
	MV1DeleteModel(m_handle);
}

void EnemyBase::Init()
{
	MV1SetScale(m_handle, VGet(0.5f, 0.5f, 0.5f));

	ChangeLightTypeDir(VGet(-2.0f, 0.0f, -1.0f));

	MV1SetRotationXYZ(m_handle, VGet(0.0f, 250.0f * DX_PI_F / 180.0f, 0.0f));
}

void EnemyBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(m_handle);
#ifdef _DEBUG
	//　当たり判定の表示
	m_colRecto.Draw(GetColor(0, 0, 255), false);
#endif
}
