#pragma once
#include <memory>
#include "DxLib.h"
#include "Collision.h"
#include "DataLoader.h"

class DataLoader;
class Player
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	//�����o�[�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_modelHandle = handle; }

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }

	//���a�̎擾
	float GetRadius() const { return m_radius; }

	//�����蔻��̎擾
	Collision GetCol() const { return m_col; }

	void SetData(DataLoader::Data inputData);

private:
	//Player�̍��W
	VECTOR m_pos;

	//�����蔻��p�̋�`
	Collision m_col;

	//3D���f���̃n���h��
	int m_modelHandle;

	//3D���f���̃A�j���[�V�����C���f�b�N�X
	int m_attachIndex;
	
	//�A�j���[�V�����̍Đ�����
	float m_tottalTime;

	//�A�j���[�V�����̌��ݎ���
	float m_playTime;

	//�����蔻��̉~�̔��a
	float m_radius;

	//�ړ����x
	float m_speed;

	//�傫��
	float m_scale;

	std::map <std::string, DataLoader::Data> m_data;	//�X�e�[�W�f�[�^
	std::string m_usedataName;			//�g�p����X�e�[�W��

	std::shared_ptr<DataLoader> m_pDataLoader;

};

