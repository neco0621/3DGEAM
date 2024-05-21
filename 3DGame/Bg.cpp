#include "Bg.h"

Bg::Bg() :
	m_handle(-1)
{
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

Bg::~Bg()
{
}

void Bg::Init()
{
	m_handle = LoadGraph("data/Sunny.png");
}

void Bg::Update()
{
}

void Bg::Draw()
{
	DrawGraph(0,0,m_handle,true);
}
