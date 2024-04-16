#pragma once
#include <vector>
#include <memory>
#include "SceneBase.h"
#include "DxLib.h"

class EnemyBase;
class EnemyManager;
class Bg;
class Player;
class Camera;
class SceneGame :public SceneBase
{
public:
	SceneGame();
	~SceneGame();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();

private:

	void HitPlayer();

	Player* m_pPlayer;

	Bg* m_pBg;

	EnemyManager* m_pEnemyManager;

	Camera* m_pCamera;

	//�J�E���g
	int m_frameCount;

	//�I�̃��f��
	int m_beeHandle;

	//�X���C���̃��f��
	int m_slimeHandle;

	//���W�̐ݒ�p
	VECTOR m_pos;

	//�Q�[���I�[�o�[�Ȃ̂��̃t���O
	bool m_isSceneEnd;
};

