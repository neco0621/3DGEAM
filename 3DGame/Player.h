#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class Input;
class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update(Input& input);			// 更新.
	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	bool JumpFlag;
	int JumpPower;
	int m_tq;
	int m_handle;
	int		modelHandle;	// モデルハンドル.
	VECTOR	pos;			// ポジション.

};

#endif // _PLAYER_H_