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

	//座標の取得
	const VECTOR& GetPos() const { return pos; }

private:
	//座標
	VECTOR pos;
};

