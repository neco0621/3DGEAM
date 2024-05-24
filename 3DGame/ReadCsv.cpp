#include "ReadCsv.h"
#include <fstream>
#include <cassert>

void ReadCsv::DataLoad()
{
	//一時保存用string
	std::string strBuf;
	//カンマわ分け一時保存用string
	std::vector<std::string> strConmaBuf;

	//ファイル読込み
	std::ifstream ifs("data/data.csv");
	if (!ifs)
	{
		assert(false);
		return;
	}

	//最初は対応情報が入っているだけなので無視する
	std::getline(ifs, strBuf);
	//情報を読み切るまでループ
	while (std::getline(ifs, strBuf))
	{
		//取得した文字列をカンマ区切りの配列(情報群)にする
		strConmaBuf = Split(strBuf,',');

		//配列からデータ名を取得する
		auto& name = strConmaBuf[eDataOder::Name];

		//初期位置を取得する
		m_data[name].startPos.x = stof(strConmaBuf[eDataOder::StartPosX]);
		m_data[name].startPos.z = stof(strConmaBuf[eDataOder::StartPosZ]);
		
		//当たり半径の半径を取得する
		m_data[name].rectRadius = stof(strConmaBuf[eDataOder::Radius]);

		//移動速度を取得する
		m_data[name].moveSpeed = stof(strConmaBuf[eDataOder::Speed]);
	}

	//ステージの名前を別で保管しておく
	for (auto& name : m_data)
	{
		m_DataName.push_back(name.first);
	}
}

std::vector<std::string> ReadCsv::Split(std::string& str, char del)
{
	//区切り開始位置
	int first = 0;
	//区切り最終位置
	int last = static_cast<int>(str.find_first_of(del));

	//結果を入れておく配列
	std::vector<std::string> result;

	while (first < str.size())
	{
		//区切ったものを結果に入れておく
		std::string subStr(str, first, last - first);

		result.push_back(subStr);

		//位置更新
		first = last + 1;
		last = static_cast<int>(str.find_first_of(del, first));
		if (last == std::string::npos)
		{
			last = static_cast<int>(str.size());
		}

	}
	return result;
}

