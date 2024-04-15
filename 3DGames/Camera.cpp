#include "Camera.h"
#include "Player.h"
#include "Bg.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Camera::Camera()
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);

	//(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	m_pos = VGet(0, 10, -20);
	SetCameraPositionAndTarget_UpVecY(m_pos, VGet(0.0f, 10.0f, 0.0f));
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Camera::Update(const Player& player)
{
    // �J�����ʒu�̒���
    VECTOR aimPos = VGet(player.GetPos().x, kTargetY, kTargetZ);
    VECTOR posToAim = VSub(aimPos, m_pos);
    m_pos = VAdd(m_pos, posToAim);

    // �J�����ʒu�𔽉f
    SetCameraScreenCenter(kScreenCenterX, kScreenCenterY);
    SetCameraPositionAndTarget_UpVecY(m_pos, VGet(player.GetPos().x, kTargetY, 0.0f));
}