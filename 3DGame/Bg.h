#pragma once
#include "DxLib.h"

class Bg
{
public:
	Bg();
	virtual ~Bg();

	void Init();
	void Update();
	void Draw();
private:
	//�w�i�̃n���h��
	int m_handle;
};

