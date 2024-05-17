#include "Camera.h"
#include "Player.h"
#include "Game.h"

Camera::Camera()
{
	//カメラの位置を設定
	pos = VGet(Game::kScreenWidth / 2, 540, -500);
}

Camera::~Camera()
{

}

void Camera::Init()
{
}

void Camera::Update()
{
	//設定した位置を反映
	SetCameraPositionAndTarget_UpVecY(pos, VGet(Game::kScreenWidth / 2, 0, 540));
}

void Camera::Draw()
{
#ifdef _DEBUG
	//カメラの座標を表示
	DrawFormatString(80, 100, GetColor(255, 255, 255), "%.2f,%.2f,%.2f", pos.x, pos.y, pos.z);
#endif
}