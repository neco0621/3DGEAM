#include "Player.h"
#include "Game.h"
#include "input.h"

Player::Player() :
	JumpPower(10),
	m_tq(Game::kScreenHeight * 0.75f)
{
	m_handle = LoadGraph("data/Player.png");

	JumpFlag = false;
}

Player::~Player()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}

void Player::Update(Input& input)
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	pos.y -= JumpPower;

	if (input.IsTriggered("space"))
	{
		pos.y = m_tq;
		JumpPower = 20;
	}

	if (pos.y <= Game::kScreenWidth * 0.75f)
	{
		pos.y = m_tq;
	}
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

void Player::Draw()
{
	// �R�c���f���̕`��
	//MV1DrawModel(modelHandle);
	//DrawGraph(pos.x, pos.y, m_handle, true);
	DrawCircle(Game::kScreenWidth * 0.5, Game::kScreenHeight * 0.75, 20, GetColor(255,0,0),true);
}