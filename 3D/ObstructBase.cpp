#include "ObstructBase.h"

ObstructBase::ObstructBase(int sorceModelHandle) :
	modelHandle(-1),
	pos(VGet(0, 0, 0))
{
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:�f�[�^�ǂݍ��݂Ɏ��s");
	}
}

ObstructBase::~ObstructBase()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  3D���f���̕`��.
//-----------------------------------------------------------------------------
void ObstructBase::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
}