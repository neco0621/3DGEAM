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
/// ファイル読み込み
/// </summary>
/// <param name="test">読み込んだ値を代入する配列</param>
/// <param name="m_fName">読み込む配列名</param>
/// <returns></returns>
int ReadCsv::FileRead(int test[], std::string m_fName)
{
	std::ifstream fin(m_fName);
	// ファイルが存在しているか確認
	if (!fin)
	{
		DrawFormatString(20, 24, 0xffffff, "ファイルをオープンできませんでした");
		return 11;
	}
	else
	{
		DrawFormatString(20, 28, 0xffffff, "ファイルをオープンしました");
	}

	// ファイルの終端まで繰り返す
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
	std::cout << "ファイルをクローズしました \n";
	return i;
}

