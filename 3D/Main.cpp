//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "ObstructStatic.h"
#include "ObstructFloat.h"
#include "ObstructManager.h"

// ��Q���̐�.
#define OBSTRUCT_NUM 3

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(TRUE);

	// �J�����𐶐�.
	Camera* camera = new Camera();

	// �v���C���[�𐶐�.
	Player* player = new Player();

	// ��Q���𐶐�.
	ObstructBase* obstruct[4];
	obstruct[0] = new ObstructManager();
	obstruct[1] = new ObstructStatic();
	obstruct[2] = new ObstructFloat();
	obstruct[3] = new ObstructStatic();

	// ��Q���̈ʒu��������.
	float band = 10.0f;
	for (int i = 0; i < 3; i++)
	{
		obstruct[i]->SetPos(VGet(-band + (band * i), 0, -1.0f));
	}

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �v���C���[����.
		player->Update();

		// �J��������.
		camera->Update(*player);

		// ��Q������.
		for (int i = 0; i < 3; i++)
		{
			obstruct[i]->Update();
		}

		// ��ʂ�����������
		ClearDrawScreen();

		// �v���C���[�`��.
		player->Draw();

		// ��Q���`��.
		for (int i = 0; i < 3; i++)
		{
			obstruct[i]->Draw();
		}

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}

	// �v���C���[���폜.
	delete(player);

	// �J�������폜.
	delete(camera);

	// ��Q�����폜.
	for (int i = 0; i < 3; i++)
	{
		delete(obstruct[i]);
	}

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}