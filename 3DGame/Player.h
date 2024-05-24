#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "ReadCsv.h"
#include <memory>
#include "CharacterBase.h"

class SceneManager;
class ReadCsv;
class Player : public CharacterBase
{
public:
	Player();
	~Player();

	void Init(SceneManager& mgr);
	void Update();
	void Draw();
private:

	std::map<std::string, ReadCsv::Data> m_data;	//データ

	std::string m_useDataName;			//使用するデータ名
};

