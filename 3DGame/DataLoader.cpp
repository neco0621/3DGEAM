#include "DataLoader.h"
#include <fstream>
#include <cassert>

void DataLoader::DataLoad()
{
	// �ꎞ�ۑ��pstring
	std::string strBuf;
	// �J���}�����ꎞ�ۑ��pstring
	std::vector<std::string> strConmaBuf;

	// �t�@�C���ǂݍ���
	std::ifstream ifs("data/csv/Data.csv");
	if (!ifs)
	{
		assert(false);
		return;
	}

	//�ŏ��͑Ή��\��񂪓����Ă��邾���Ȃ̂Ŗ�������
	std::getline(ifs, strBuf);
	//����ǂݐ؂�܂Ń��[�v
	while (std::getline(ifs, strBuf))
	{
		//�擾������������J���}��؂�̔z��(���Q)�ɂ���
		strConmaBuf = Split(strBuf, ',');
		//�z�񂩂�X�e�[�W�����擾����
		auto& name = strConmaBuf[m_dataOrder::DataName];

		//�v���C���[�̊J�n���W���擾����
		m_data[name].startPos.x = stof(strConmaBuf[m_dataOrder::startPosX]);
		m_data[name].startPos.y = 0.0f;
		m_data[name].startPos.z = stof(strConmaBuf[m_dataOrder::startPosZ]);

		//�X�s�[�h�擾����
		m_data[name].speed = stof(strConmaBuf[m_dataOrder::speed]);
	}

	//�X�e�[�W�̖��O��ʂŕۊǂ��Ă���
	for (auto& name : m_data)
	{
		m_dataName.push_back(name.first);
	}
}

std::vector<std::string> DataLoader::Split(std::string& str, char del)
{
	// ��؂�J�n�ʒu
	int first = 0;
	// ��؂�ŏI�ʒu
	int last = str.find_first_of(del);

	//���ʂ����Ă����z��
	std::vector<std::string> result;

	while (first < str.size())
	{
		// ��؂������̂����ʂɓ���Ă���
		std::string subStr(str, first, last - first);

		result.push_back(subStr);

		// �ʒu�X�V
		first = last + 1;
		last = str.find_first_of(del, first);
		if (last == std::string::npos)
		{
			last = str.size();
		}
	}

	return result;
}