#include "DxLib.h"
#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Input.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//��ʃ��[�h�̃Z�b�g
	ChangeWindowMode(TRUE);
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	SetDrawScreen(DX_SCREEN_BACK);	// ����ʂ�`��Ώۂɂ���
	SetUseZBufferFlag(TRUE);		// �y�o�b�t�@���g�p����
	SetWriteZBufferFlag(TRUE);		// �y�o�b�t�@�ւ̏������݂��s��
	SetUseBackCulling(TRUE);		// �o�b�N�J�����O���s��

	SceneManager manager;
	manager.ChangeScene(std::make_shared<TitleScene>(manager));
	Input input;

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();
		
		input.Update();
		manager.Update(input);
		manager.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�Œ�ɂ���
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}