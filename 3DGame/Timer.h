#pragma once
class Timer
{
public:
	Timer();
	~Timer();

	void Init();
	void Update();
	void Draw();

	float GetTimer() const { return timer; }

private:

	//30秒立ったか
	bool isTimeUp;

	//タイマー
	float timer;
};