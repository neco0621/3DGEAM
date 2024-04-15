#pragma once
#include "DxLib.h"

/// <summary>
/// ��Q���̊��N���X
/// </summary>
class ObstructBase abstract
{
public:
	ObstructBase(int sorceModelHandle);
	~ObstructBase();

	virtual void Update() abstract;
	virtual void Draw();

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

protected:
	int		modelHandle;	// ���f���n���h��.
	VECTOR	pos;			// �|�W�V����.
};

