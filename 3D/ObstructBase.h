#pragma once
#include "DxLib.h"

/// <summary>
/// 障害物の基底クラス
/// </summary>
class ObstructBase abstract
{
public:
	ObstructBase(int sorceModelHandle);
	~ObstructBase();

	virtual void Update() abstract;
	virtual void Draw();

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

protected:
	int		modelHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.
};

