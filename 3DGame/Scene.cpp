#include "Scene.h"

//ここにmanager_(manager)を書くことで再代入とみなされない
//ローカル変数と混ざらないように最後に_をつける(おすすめ)
Scene::Scene(SceneManager& manager) : m_manager(manager)
{

}
