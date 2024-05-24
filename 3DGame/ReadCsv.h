#pragma once
#include <vector>
#include <DxLib.h>
#include <string>
#include <map>

class ReadCsv
{
public:
	struct Data
	{
		std::vector<int> Data;								//�f�[�^�̔z��
		VECTOR startPos = VGet(0.0f, 0.0f, 0.0f);			//�X�^�[�g���W
		float rectRadius = 0.0f;							//�����蔻��̔��a
		float moveSpeed = 0.0f;								//�ړ����x
	};

	enum eDataOder : int
	{
		Name,				//�f�[�^��
		StartPosX,			//�X�^�[�g����X���W
		StartPosZ,			//�X�^�[�g����Z���W
		Radius,				//�����蔻��̉~�̔��a
		Speed				//�ړ����x
	};

	/// <summary>
	/// �f�[�^�̃��[�h
	/// </summary>
	void DataLoad();
	const std::map<std::string, Data> GetData()const { return m_data; }

	const std::vector<std::string> GetDataName()const { return m_DataName; };
private:

	/// <summary>
	/// �ЂƂɂ܂Ƃ߂�ꂽ�ǂݍ��񂾏����J���}��؂�ɂ킯��
	/// </summary>
	/// <param name="str">�ЂƂɂ܂Ƃ߂�ꂽ�ǂݍ��񂾏��</param>
	/// <param name="del">��؂�n�_�ƂȂ镶��</param>
	/// <returns></returns>
	std::vector<std::string> Split(std::string& str, char del);
	
	std::map<std::string, Data> m_data;
	std::vector<std::string> m_DataName;	//�f�[�^���ꗗ
};

