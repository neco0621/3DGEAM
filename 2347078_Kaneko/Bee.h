#pragma once
#include "EnemyBase.h"
#include "Rect.h"
class Bee : public EnemyBase
{
public:
	Bee(int m_handle, VECTOR pos);
	virtual ~Bee();

	void Update() override;

protected:
	int m_handle;
	Rect m_colRecto;
};

