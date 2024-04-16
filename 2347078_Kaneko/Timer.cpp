#include "Timer.h"
#include "DxLib.h"

namespace
{
	//�^�C�}�[�̏�������
	constexpr float kTimer = 1800.0f;

	//�t�H���g�̃T�C�Y
	constexpr int kFontSize = 32;

	//�b���Ō����邽��60�Ŋ���
	constexpr int kDiv = 60;

	//�t�H���g�̏����ʒu
	constexpr int kPosX = 470;
	constexpr int kPosY = 100;
}

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Init()
{
	ChangeFont("���낭�܃t�H���g");
	timer = kTimer;

	SetFontSize(kFontSize);

	isTimeUp = false;
}

void Timer::Update()
{
	timer--;

	if (timer <= 0)
	{
		timer = 0.0f;
		isTimeUp = true;
	}
}

void Timer::Draw()
{
	DrawFormatString(kPosX, kPosY,GetColor(255, 255, 255),"�c�莞��:(%.2f)", timer/ kDiv);
}

void Timer::End()
{
}
