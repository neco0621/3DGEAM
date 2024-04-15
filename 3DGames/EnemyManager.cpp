#include "EnemyManager.h"
#include "EnemyBase.h"
#include "Bee.h"
#include "Slime.h"
#include "DxLib.h"
#include "Player.h"

namespace
{
	//“G‚ÌXÀ•W‚Ìİ’è
	static constexpr int kPosX = 300;

	//“G‚ÌYÀ•W‚Ìİ’è
	static constexpr int kPosY = 75;
}

EnemyManager::EnemyManager():
	m_GameOver(false),
	m_pos(VGet(500,0,0))
{
	m_beeHandle = MV1LoadModel("data/Enemy/Bee.mv1");

	m_slimeHandle = MV1LoadModel("data/Enemy/Slime.mv1");
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::CreateEnemy()
{
	for (int i = 0; i < m_enemyMax; i++)
	{
		m_pos = VGet(kPosX * i, kPosY, 0);
		if (i % 2 != 0)
		{
			m_pEnemyBase[i] = new Slime(m_slimeHandle, m_pos);
			m_pEnemyBase[i]->Init();
		}
		else
		{
			m_pEnemyBase[i] = new Bee(m_beeHandle, m_pos);
			m_pEnemyBase[i]->Init();
		}
	}	
}

void EnemyManager::DestroyEnemy()
{
	for (int i = 0; i < m_enemyMax; ++i)
	{
		delete(m_pEnemyBase[i]);
		m_pEnemyBase[i] = nullptr;
	}

	MV1DeleteModel(m_beeHandle);
	MV1DeleteModel(m_slimeHandle);
}

void EnemyManager::Update()
{
	for (int i = 0; i < m_enemyMax; i++)
	{
		if (m_pEnemyBase[i])
		{
			m_pEnemyBase[i]->Update();
		}
	}
}

void EnemyManager::Draw()
{
	for (int i = 0; i < m_enemyMax; i++)
	{
		if (m_pEnemyBase[i])
		{
			m_pos = VGet(kPosX * i, kPosY, 0);
			m_pEnemyBase[i]->SetPos(VGet(m_pos.x, m_pos.y, m_pos.z));

			m_pEnemyBase[i]->Draw();
		}
	}
}

void EnemyManager::OnDamege(Player* mPlayer)
{
	Rect PlayerRecto = mPlayer->GetColRect();

	for (int i = 0; i < m_enemyMax; i++)
	{
		if (m_pEnemyBase[i])
		{
			Rect EnemyRecto = m_pEnemyBase[i]->GetColRect();
			if (PlayerRecto.IsCollsion(EnemyRecto))
			{
				m_GameOver = true;
			}

		}
	}
}	