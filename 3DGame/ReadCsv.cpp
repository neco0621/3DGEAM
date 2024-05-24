#include "ReadCsv.h"
#include <fstream>
#include <cassert>

void ReadCsv::DataLoad()
{
	//�ꎞ�ۑ��pstring
	std::string strBuf;
	//�J���}�핪���ꎞ�ۑ��pstring
	std::vector<std::string> strConmaBuf;

	//�t�@�C���Ǎ���
	std::ifstream ifs("data/data.csv");
	if (!ifs)
	{
		assert(false);
		return;
	}

	//�ŏ��͑Ή���񂪓����Ă��邾���Ȃ̂Ŗ�������
	std::getline(ifs, strBuf);
	//����ǂݐ؂�܂Ń��[�v
	while (std::getline(ifs, strBuf))
	{
		//�擾������������J���}��؂�̔z��(���Q)�ɂ���
		strConmaBuf = Split(strBuf,',');

		//�z�񂩂�f�[�^�����擾����
		auto& name = strConmaBuf[eDataOder::Name];

		//�����ʒu���擾����
		m_data[name].startPos.x = stof(strConmaBuf[eDataOder::StartPosX]);
		m_data[name].startPos.z = stof(strConmaBuf[eDataOder::StartPosZ]);
		
		//�����蔼�a�̔��a���擾����
		m_data[name].rectRadius = stof(strConmaBuf[eDataOder::Radius]);

		//�ړ����x���擾����
		m_data[name].moveSpeed = stof(strConmaBuf[eDataOder::Speed]);
	}

	//�X�e�[�W�̖��O��ʂŕۊǂ��Ă���
	for (auto& name : m_data)
	{
		m_DataName.push_back(name.first);
	}
}

std::vector<std::string> ReadCsv::Split(std::string& str, char del)
{
	//��؂�J�n�ʒu
	int first = 0;
	//��؂�ŏI�ʒu
	int last = static_cast<int>(str.find_first_of(del));

	//���ʂ����Ă����z��
	std::vector<std::string> result;

	while (first < str.size())
	{
		//��؂������̂����ʂɓ���Ă���
		std::string subStr(str, first, last - first);

		result.push_back(subStr);

		//�ʒu�X�V
		first = last + 1;
		last = static_cast<int>(str.find_first_of(del, first));
		if (last == std::string::npos)
		{
			last = static_cast<int>(str.size());
		}

	}
	return result;
}

