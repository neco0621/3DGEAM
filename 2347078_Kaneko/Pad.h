#pragma once

//�p�b�h�̏�Ԃ��擾����
namespace Pad
{
	//�p�b�h�̍X�V�����@1�t���[���ɂP��s��
	void Update();

	//������Ă��邩����
	bool IsPress(int key);
	//�����ꂽ�u�Ԃ��擾
	bool IsTrigger(int key);
	//�������u�Ԃ̏���
	bool IsRelase(int key);
}

