#pragma once
class Timer
{
public:
	Timer();
	~Timer();

	void Init();
	void Update();
	void Draw();
	void End();

	float GetTimer() const { return timer; }

private:

	//�t�H���g�̃n���h��
	int FontHandle;

	//30�b��������
	bool isTimeUp;

	//�^�C�}�[
	float timer;
};

