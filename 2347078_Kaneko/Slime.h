#pragma once
#include "EnemyBase.h"
#include "DxLib.h"
class Slime : public EnemyBase
{
public:
	Slime(int m_handle, VECTOR pos);
	virtual ~Slime();
	
	void Update()override;
private:
	int m_handle;
};

