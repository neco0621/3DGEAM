#include "Bg.h"

Bg::Bg() :
	//������
	m_handle(-1)
{
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

Bg::~Bg()
{
}

void Bg::Init()
{
	//�w�i�̃��[�h
	m_handle = LoadGraph("data/image/Sunny.png");
}

void Bg::Update()
{
}

void Bg::Draw()
{
	//�`��
	DrawGraph(0,0,m_handle,true);
}
