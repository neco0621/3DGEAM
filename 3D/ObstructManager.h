#pragma once

#include "DxLib.h"
#include "ObstructBase.h"

class ObstructFloat;
class ObstructStatic;

class ObstructManager : public ObstructBase
{
public:
	ObstructManager();
	virtual ~ObstructManager();

	void CreateObstruct();
	void DeleteObstruct();

	void Update();
	void Draw();

	int floatModelHandle;
	int staticModelHandle;
};

