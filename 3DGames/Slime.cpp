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
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//�����蔻��̍X�V
	m_colRecto.SetCenter(m_pos.x, m_pos.y, m_pos.z, 40, 60);
}
