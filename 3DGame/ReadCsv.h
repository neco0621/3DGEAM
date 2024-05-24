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
		std::vector<int> Data;								//データの配列
		VECTOR startPos = VGet(0.0f, 0.0f, 0.0f);			//スタート座標
		float rectRadius = 0.0f;							//当たり判定の半径
		float moveSpeed = 0.0f;								//移動速度
	};

	enum eDataOder : int
	{
		Name,				//データ名
		StartPosX,			//スタート時のX座標
		StartPosZ,			//スタート時のZ座標
		Radius,				//当たり判定の円の半径
		Speed				//移動速度
	};

	/// <summary>
	/// データのロード
	/// </summary>
	void DataLoad();
	const std::map<std::string, Data> GetData()const { return m_data; }

	const std::vector<std::string> GetDataName()const { return m_DataName; };
private:

	/// <summary>
	/// ひとつにまとめられた読み込んだ情報をカンマ区切りにわける
	/// </summary>
	/// <param name="str">ひとつにまとめられた読み込んだ情報</param>
	/// <param name="del">区切る地点となる文字</param>
	/// <returns></returns>
	std::vector<std::string> Split(std::string& str, char del);
	
	std::map<std::string, Data> m_data;
	std::vector<std::string> m_DataName;	//データ名一覧
};

