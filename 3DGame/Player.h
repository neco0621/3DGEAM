#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class Input;
class Player
{
public:
	Player();				// �R���X�g���N�^.
	~Player();				// �f�X�g���N�^.

	void Update(Input& input);			// �X�V.
	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

private:
	bool JumpFlag;
	int JumpPower;
	int m_tq;
	int m_handle;
	int		modelHandle;	// ���f���n���h��.
	VECTOR	pos;			// �|�W�V����.

};

#endif // _PLAYER_H_