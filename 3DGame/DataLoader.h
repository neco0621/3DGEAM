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
		std::vector<int> objectID;
		VECTOR startPos;
		float speed;
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
	std::map<std::string, Data> m_data;
	std::vector<std::string> m_dataName;
};

