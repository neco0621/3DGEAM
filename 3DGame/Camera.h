#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();
	~Camera();

	void Update(const Player& player);

	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR pos;
};

#endif // _CAMERA_H_