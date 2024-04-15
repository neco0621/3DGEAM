#include "Camera.h"
#include "Player.h"

#define USE_LERP_CAMERA 0

Camera::Camera() :
	pos(VGet(0,0,0))
{
	SetCameraNearFar(0.1f, 1000.0f);
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
#if !USE_LERP_CAMERA
	// z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
	pos = VGet(0, player.GetPos().y + 20.0f, player.GetPos().z - 30.0f);
#else
	// lerp���g�p���Ď���.
	// lerp(VECTOR a, VECTOR b, float t)��
	// answer = a + ((b-a) * t)
	VECTOR aimPos = VGet(0, player.GetPos().y + 20.0f, player.GetPos().z - 30.0f);
	VECTOR posToAim = VSub(aimPos, pos);
	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
	pos = VAdd(pos, scaledPosToAim);
#endif
	// �J�����Ɉʒu�𔽉f.
	SetCameraPositionAndTarget_UpVecY(pos, player.GetPos());
}