#include "ReadCsv.h"

ReadCsv::ReadCsv() :
	m_fileValue(0),
	m_flen(0),
	m_flieNum(0),
	m_array(),
	m_fName("data/data.csv")
{
}

ReadCsv::~ReadCsv()
{
}

void ReadCsv::Init()
{
	m_flen = FileRead(m_array, m_fName);
}

void ReadCsv::Update()
{
}

void ReadCsv::Draw()
{
	for (int i = 1; i < m_flen; i++)
	{
		DrawFormatString(20,20 + (i * 20), 0xffffff, "%d", m_array[i]);
	}
}


/// <summary>
/// �t�@�C���ǂݍ���
/// </summary>
/// <param name="test">�ǂݍ��񂾒l��������z��</param>
/// <param name="m_fName">�ǂݍ��ޔz��</param>
/// <returns></returns>
int ReadCsv::FileRead(int test[], std::string m_fName)
{
	std::ifstream fin(m_fName);
	// �t�@�C�������݂��Ă��邩�m�F
	if (!fin)
	{
		DrawFormatString(20, 24, 0xffffff, "�t�@�C�����I�[�v���ł��܂���ł���");
		return 11;
	}
	else
	{
		DrawFormatString(20, 28, 0xffffff, "�t�@�C�����I�[�v�����܂���");
	}

	// �t�@�C���̏I�[�܂ŌJ��Ԃ�
	int i = 1;
	while (1)
	{
		fin >> test[i];
		if (fin.eof())
		{
			break;
		}
		i++;
	}
	fin.close();
	std::cout << "�t�@�C�����N���[�Y���܂��� \n";
	return i;
}

