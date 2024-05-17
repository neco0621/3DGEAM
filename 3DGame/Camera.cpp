#include "Camera.h"
#include "Player.h"
#include "Game.h"

Camera::Camera()
{
	//�J�����̈ʒu��ݒ�
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
	//�ݒ肵���ʒu�𔽉f
	SetCameraPositionAndTarget_UpVecY(pos, VGet(Game::kScreenWidth / 2, 0, 540));
}

void Camera::Draw()
{
#ifdef _DEBUG
	//�J�����̍��W��\��
	DrawFormatString(80, 100, GetColor(255, 255, 255), "%.2f,%.2f,%.2f", pos.x, pos.y, pos.z);
#endif
}