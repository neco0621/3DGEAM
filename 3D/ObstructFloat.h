//-----------------------------------------------------------------------------
// @brief  ��Q���F���V����.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _OBSTRUCT_FLOAT_H_
#define _OBSTRUCT_FLOAT_H_

#include "DxLib.h"
#include "ObstructBase.h"

class ObstructFloat : public ObstructBase
{
public:
	ObstructFloat();				// �R���X�g���N�^.
	virtual ~ObstructFloat() {};		// �f�X�g���N�^.

	void Update();					// �X�V.

private:
	float rad;
};

#endif // _OBSTRUCT_FLOAT_H_

