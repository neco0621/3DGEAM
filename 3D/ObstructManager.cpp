#include "ObstructManager.h"


ObstructManager::ObstructManager() :
	ObstructBase()
{
	staticModelHandle = MV1LoadModel("data/model/obstructStatic/obstructStatic.pmd");
	floatModelHandle = MV1LoadModel("data/model/obstructStatic/obstructFloat.pmd");
}

ObstructManager::~ObstructManager()
{
	MV1DeleteModel(modelHandle);
}

void ObstructManager::CreateObstruct()
{
}

void ObstructManager::DeleteObstruct()
{
}

void ObstructManager::Update()
{
	MV1SetPosition(modelHandle, pos);
}

void ObstructManager::Draw()
{
	MV1DrawModel();
}
