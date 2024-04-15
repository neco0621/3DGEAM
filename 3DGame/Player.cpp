#include "Player.h"

Player::Player()
{
	// �R�c���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/model/player/hackadoll.pmx");

	pos = VGet(0, 0, 0);
}

Player::~Player()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}

void Player::Update()
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & KEY_INPUT_SPACE)
	{

	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

void Player::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
}