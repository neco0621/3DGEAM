#include "Player.h"

Player::Player()
{
	// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/model/player/hackadoll.pmx");

	pos = VGet(0, 0, 0);
}

Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}

void Player::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & KEY_INPUT_SPACE)
	{

	}

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}