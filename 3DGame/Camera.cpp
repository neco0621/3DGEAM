#include "Camera.h"
#include "Player.h"
#include "Game.h"

Camera::Camera()
{
	pos = VGet(Game::kScreenWidth / 2, 540, Game::kScreenHeight / 2);
	
}

Camera::~Camera()
{

}

void Camera::Init()
{
}

void Camera::Update()
{
	
}

void Camera::Draw()
{
	DrawFormatString(80, 100, GetColor(255, 255, 255), "%.2f,%.2f,%.2f", pos.x, pos.y, pos.z);
}