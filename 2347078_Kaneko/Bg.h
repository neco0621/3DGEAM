#pragma once
#include "DxLib.h"
class Bg
{
public:
	Bg();
	virtual ~Bg();

	void Init();
	void Update();
	void Draw();

	struct Size
	{
		int width;
		int height;
	};


private:

	VECTOR m_pos1;
	VECTOR m_pos2;
	VECTOR m_pos3;



	//”wŒi‚Ìƒnƒ“ƒhƒ‹
	int m_bgHandle1;
	int m_bgHandle2;
	int m_bgHandle3;
	int m_bgHandle4;
	int m_bgHandle5;
	int m_bgHandle6;
	int m_bgHandle7;
	int m_bgHandle8;
	int m_bgHandle9;
	int m_bgHandle10;
	
};

