#include "DataLoader.h"
#include <fstream>
#include <cassert>

void DataLoader::DataLoad()
{
	// 一時保存用string
	std::string strBuf;
	// カンマ分け一時保存用string
	std::vector<std::string> strConmaBuf;

	// ファイル読み込み
	std::ifstream ifs("data/csv/Data.csv");
	if (!ifs)
	{
		assert(false);
		return;
	}

	//最初は対応表情報が入っているだけなので無視する
	std::getline(ifs, strBuf);
	//情報を読み切るまでループ
	while (std::getline(ifs, strBuf))
	{
		//取得した文字列をカンマ区切りの配列(情報群)にする
		strConmaBuf = Split(strBuf, ',');
		//配列からステージ名を取得する
		auto& name = strConmaBuf[m_dataOrder::DataName];

		//プレイヤーの開始座標を取得する
		m_data[name].startPos.x = stof(strConmaBuf[m_dataOrder::startPosX]);
		m_data[name].startPos.y = 0.0f;
		m_data[name].startPos.z = stof(strConmaBuf[m_dataOrder::startPosZ]);

		//スピード取得する
		m_data[name].speed = stof(strConmaBuf[m_dataOrder::speed]);
	}

	//ステージの名前を別で保管しておく
	for (auto& name : m_data)
	{
		m_dataName.push_back(name.first);
	}
}

std::vector<std::string> DataLoader::Split(std::string& str, char del)
{
	// 区切り開始位置
	int first = 0;
	// 区切り最終位置
	int last = str.find_first_of(del);

	//結果を入れておく配列
	std::vector<std::string> result;

	while (first < str.size())
	{
		// 区切ったものを結果に入れていく
		std::string subStr(str, first, last - first);

		result.push_back(subStr);

		// 位置更新
		first = last + 1;
		last = str.find_first_of(del, first);
		if (last == std::string::npos)
		{
			last = str.size();
		}
	}

	return result;
}