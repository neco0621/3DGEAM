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
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//�����蔻��̍X�V
	m_colRecto.SetCenter(m_pos.x, m_pos.y+ kRectPosY, m_pos.z, 40, 60);
}
