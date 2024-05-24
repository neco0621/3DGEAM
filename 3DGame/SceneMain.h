#pragma once
#include "Scene.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class Timer;
class SoccerBall;
class Bg;
class ReadCsv;
class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	~SceneMain();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:

	//�X�V�����o�֐��|�C���^
	void (SceneMain::* updateFunc_)(Input& input);
	//�`�惁���o�֐��|�C���^
	using DrawFunc_t = void(SceneMain::*) ();
	DrawFunc_t drawFunc_;
	//�X�V�֐�
	void FadeInUpdate(Input& input);
	void NormalUpdate(Input& input);
	void FadeOutUpdate(Input& input);

	//�`��֐�
	void FadeDraw();    //�t�F�[�h���`��
	void NormalDraw();  //��t�F�[�h�`��
	float m_frame;

	//�v���C���[
	Player* m_pPlayer;
	//�J����
	Camera* m_pCamera;
	//�{�[��
	SoccerBall* m_pBall;
	//�^�C�}�[
	Timer* m_pTimer;
	//�����蔻��
	Rect m_pRect;
	//�w�i
	Bg* m_pBg;

	bool m_gameOverFlag;

	int m_handle;

	float m_timer;
};

