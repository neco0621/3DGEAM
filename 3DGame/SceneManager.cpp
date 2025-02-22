#include "SceneManager.h"
#include "Scene.h"

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	m_scenes.back()->Init();
}

void SceneManager::Update(Input& input)
{
	m_scenes.back()->Update(input);
}

void SceneManager::Draw()
{
	for (auto& scene : m_scenes) {
		scene->Draw();
	}
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> nextScene)
{
	if (m_scenes.empty()) {//リストが空っぽだったら入れ替えるのではなく
		m_scenes.push_back(nextScene);//末尾に追加する
	}
	else {
		m_scenes.back() = nextScene;//すでに1つ以上あったら末尾のものを入れ替える
	}

}

void SceneManager::PushScene(std::shared_ptr<Scene> scene)
{
	m_scenes.push_back(scene);
}

void SceneManager::PopScene()
{
	m_scenes.pop_back();
}
