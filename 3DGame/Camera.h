#pragma once
#include "DxLib.h"

class Player;
class Camera
{
public:
	Camera();
	~Camera();
	void Init();

	void Update(const Player& player);

	void Draw();

	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR pos;
};

