#pragma once
#include "DxLib.h"
#include "Rect.h"

class CharacterBase
{
public:
	CharacterBase();
	~CharacterBase();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	/// <summary>
	/// ���W�̎擾
	/// </summary>
	/// <returns>���݈ʒu</returns>
	VECTOR GetPos() const { return m_pos; }

	/// <summary>
	/// �����蔻��̎擾
	/// </summary>
	/// <returns>���݂̓����蔻��</returns>
	Rect GetColRect()const { return m_colRect; }

	/// <summary>
	/// �����蔻��̔��a�̎擾
	/// </summary>
	/// <returns>���݂̔��a</returns>
	float GetRadius()const { return m_radius; }


protected:
	//���S�ʒu
	float m_centerX;
	float m_centerY;

	//���a
	float m_radius;

	//�\���ʒu
	VECTOR m_pos;
	//�O���t�B�b�N�̃n���h��
	int m_handle;

	//�����蔻��
	Rect m_colRect;

	//�ړ���
	VECTOR m_vec;
};

