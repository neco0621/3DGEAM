#pragma once
#include "DxLib.h"

class Player;
class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Init();
	void Update();
	void Draw();

	//���W�̎擾
	const VECTOR& GetPos() const { return pos; }

private:
	//���W
	VECTOR pos;
};

