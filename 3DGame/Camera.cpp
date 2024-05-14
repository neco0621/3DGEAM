#include "Camera.h"
#include "Player.h"

Camera::Camera()
{
	SetCameraNearFar(0.1f, 1000.0f);

	pos = VGet(540, 720, 360);	
	SetCameraPositionAndTarget_UpVecY(pos, VGet(540.0f, 0.0f, 360.0f));
}

Camera::~Camera()
{

}

void Camera::Init()
{
}

void Camera::Update(const Player& player)
{
	
}

void Camera::Draw()
{
	DrawFormatString(80, 100, GetColor(255, 255, 255), "%.2f,%.2f,%.2f", pos.x, pos.y, pos.z);
}