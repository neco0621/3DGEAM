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

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }

	//���a�̎擾
	float GetRadius() const { return m_radius; }

	//�����蔻��̎擾
	Collision GetCol() const { return m_col; }

	void SetData(DataLoader::Data inputData);

private:
	//3D���f���̃n���h��
	int m_modelHandle;

	//Player�̍��W
	VECTOR m_pos;

	//�����蔻��p�̋�`
	Collision m_col;

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

