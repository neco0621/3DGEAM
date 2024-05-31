#pragma once
#include "DxLib.h"

class Player;
class Camera
{
public:
	Camera();
	~Camera();

	void Init();
	void Update();
	void Draw();

	//À•W‚Ìæ“¾
	const VECTOR& GetPos() const { return pos; }

private:
	//À•W
	VECTOR pos;
};

