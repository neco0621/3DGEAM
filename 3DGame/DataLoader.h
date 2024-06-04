#pragma once
#include "DxLib.h"
#include <string>
#include <map>
#include <vector>
#include <array>

class DataLoader
{
public:
	struct Data
	{
		std::vector<int> Data;
		VECTOR startPos = VGet(0.0f, 0.0f, 0.0f);
		float speed = 0.0f;
	};

	enum m_dataOrder
	{
		DataName,
		startPosX,
		startPosZ,
		speed,
	};

	void DataLoad();

	const std::map <std::string, Data> GetData()const { return m_data; };

	const std::vector<std::string> GetStageName()const { return m_dataName; };

private:
	std::vector<std::string> Split(std::string& str, char del);

private:
	std::map<std::string, Data> m_data;
	std::vector<std::string> m_dataName;
};

