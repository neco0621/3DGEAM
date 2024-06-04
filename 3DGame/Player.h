#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "DataLoader.h"

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
	Rect GetColRect() const { return m_colRect; }

	void SetData(DataLoader::Data inputData);

private:
	//3D���f���̃n���h��
	int m_modelHandle;

	//Player�̍��W
	VECTOR m_pos;

	//�����蔻��p�̋�`
	Rect m_colRect;

	//�����蔻��̉~�̔��a
	float m_radius;

	float m_speed;

	std::map <std::string, DataLoader::Data> m_data;	//�X�e�[�W�f�[�^
	std::string m_usedataName;			//�g�p����X�e�[�W��

};

