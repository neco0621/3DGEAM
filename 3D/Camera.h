//-----------------------------------------------------------------------------
// @brief  �J�����N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update(const Player& player);	// �X�V.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// �|�W�V����.

};

#endif // _CAMERA_H_