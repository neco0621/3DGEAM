//-----------------------------------------------------------------------------
// @brief  ��Q���F�����Ȃ�.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _OBSTRUCT_STATIC_H_
#define _OBSTRUCT_STATIC_H_

#include "DxLib.h"
#include "ObstructBase.h"

class ObstructStatic : public ObstructBase
{
public:
	ObstructStatic();				// �R���X�g���N�^.
	virtual ~ObstructStatic() {};		// �f�X�g���N�^.

	void Update();					// �X�V.

};

#endif // _OBSTACLE_BASE_H_

