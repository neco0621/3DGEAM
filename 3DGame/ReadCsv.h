#pragma once
#include<iostream>
#include<fstream>
#include <DxLib.h>

class ReadCsv
{
public:
	ReadCsv();
	~ReadCsv();

	void Init();
	void Update();
	void Draw();
	int FileRead(int test[], std::string m_fName);

private:
	int m_fileValue;
	const int m_flieNum = 200;
	int m_array[200];
	int m_flen;
	std::string m_fName;
};

