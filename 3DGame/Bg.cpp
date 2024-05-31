#include "Bg.h"

Bg::Bg() :
	//初期化
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
	//背景のロード
	m_handle = LoadGraph("data/image/Sunny.png");
}

void Bg::Update()
{
}

void Bg::Draw()
{
	//描画
	DrawGraph(0,0,m_handle,true);
}
