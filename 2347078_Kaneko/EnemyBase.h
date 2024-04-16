#pragma once
#include "DxLib.h"
#include "Rect.h"
class EnemyBase
{
public:
	EnemyBase(int ModelHandle, VECTOR pos);
	virtual ~EnemyBase();

	void Init();
	virtual void Update() abstract;
	void Draw();

	//���W�̐ݒ�
	void SetPos(VECTOR mpos) { m_pos = mpos; }
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() const { return m_colRecto; }

protected:

	//���f���̃n���h��
	int m_handle;

	//���W
	VECTOR	 m_pos;

	//�����蔻��
	Rect m_colRecto;
};


