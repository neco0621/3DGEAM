#pragma once
#include "DxLib.h"
#include"Rect.h"

class Player;
class EnemyBase;
class EnemyManager
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	void CreateEnemy();			// �G�̐���
	void DestroyEnemy();		// �G�̍폜
	
	void Update();
	void Draw();

	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() const { return m_colRecto; }
	void OnDamege(Player* mPlayer);
	bool isGameOver() const { return m_GameOver; }
private:
	
	//�G�̍ő吔
	static constexpr int m_enemyMax = 60;

	EnemyBase* m_pEnemyBase[m_enemyMax];

	//���W�̐ݒ�
	VECTOR m_pos;

	Rect m_colRecto;
	//�I�̃��f��
	int m_beeHandle;

	bool m_GameOver;

	//�X���C���̃��f��
	int m_slimeHandle;
};

