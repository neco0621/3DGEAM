#include "ObstructBase.h"

ObstructBase::ObstructBase(int sorceModelHandle) :
	modelHandle(-1),
	pos(VGet(0, 0, 0))
{
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:ƒf[ƒ^“Ç‚Ýž‚Ý‚ÉŽ¸”s");
	}
}

ObstructBase::~ObstructBase()
{
	// ƒ‚ƒfƒ‹‚ÌƒAƒ“ƒ[ƒh.
	MV1DeleteModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  3Dƒ‚ƒfƒ‹‚Ì•`‰æ.
//-----------------------------------------------------------------------------
void ObstructBase::Draw()
{
	// ‚R‚cƒ‚ƒfƒ‹‚Ì•`‰æ
	MV1DrawModel(modelHandle);
}