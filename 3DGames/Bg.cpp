#include "Bg.h"
#include "DxLib.h"

namespace
{
	//背景と地面のサイズ
	constexpr float kBgScale = 1.5f;
}

Bg::Bg()
{
	m_pos1 = (VGet(0, 330, 0));
	m_pos2 = (VGet(0, 495, 0));
	m_pos3 = (VGet(0, 595, 0));
}

Bg::~Bg()
{
}

void Bg::Init()
{
	m_bgHandle1 = LoadGraph("data/Bg/Bg1.png");
	m_bgHandle2 = LoadGraph("data/Bg/Bg2.png");
	m_bgHandle3 = LoadGraph("data/Bg/Bg3.png");
	m_bgHandle4 = LoadGraph("data/Bg/Bg4.png");
	m_bgHandle5 = LoadGraph("data/Bg/Bg5.png");
	m_bgHandle6 = LoadGraph("data/Bg/Bg6.png");
	m_bgHandle7 = LoadGraph("data/Bg/Bg7.png");
	m_bgHandle8 = LoadGraph("data/Bg/Bg8.png");
	m_bgHandle9 = LoadGraph("data/Bg/Bg9.png");
	m_bgHandle10 = LoadGraph("data/Bg/Bg10.png");
}

void Bg::Update()
{
}

void Bg::Draw()
{
	//画像サイズを取得
	
	//背景の画像のサイズ
	Size bgSize;
	//地面の画像のサイズ
	Size graundSize;

	GetGraphSize(m_bgHandle1, &bgSize.width, &bgSize.height);
	GetGraphSize(m_bgHandle9, &graundSize.width, &graundSize.height);

	//スクロール量を計算
	int scrollBg = static_cast<int>(m_pos1.x)%static_cast<int>(bgSize.width* kBgScale);
	int scrollGraund = static_cast<int>(m_pos2.x) % static_cast<int>(graundSize.width * kBgScale);

	for (int i = 0; i < 10; i++)
	{
		DrawRotaGraph3D(scrollBg+i*bgSize.width *kBgScale,
			m_pos1.y,
			m_pos1.z,
			kBgScale,0.0f,
			m_bgHandle1,true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle2, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle3, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle4, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle5, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle6, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle7, true);
		DrawRotaGraph3D(scrollBg + i * bgSize.width * kBgScale,
			m_pos2.y,
			m_pos2.z,
			kBgScale, 0.0f,
			m_bgHandle8, true);
	}

	for (int i = 0; i < 10; i++)
	{
		DrawRotaGraph3D(scrollBg + i * graundSize.width * kBgScale,
			m_pos3.y,
			m_pos3.z,
			kBgScale, 0.0f,
			m_bgHandle9, true);
		DrawRotaGraph3D(scrollBg + i * graundSize.width * kBgScale,
			m_pos3.y,
			m_pos3.z,
			kBgScale, 0.0f,
			m_bgHandle10, true);
	}


}
