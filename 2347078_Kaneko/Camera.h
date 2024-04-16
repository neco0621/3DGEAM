#pragma once

#include "DxLib.h"

class Player;
class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Update(const Player& player);

private:
    VECTOR m_pos;

private:    // �萔
    // ����p
    static constexpr float kFov = (DX_PI_F / 180.0f) * 60.0f;
    // ��O�N���b�v����
    static constexpr float kNear = 0.1f;
    // ���N���b�v����
    static constexpr float kFar = 1000.0f;
    // �J�����̏��������_
    static constexpr float kTargetX = 10.0f;        // X��
    static constexpr float kTargetY = 150.0f;    // Y��
    static constexpr float kTargetZ = -400.0f;    // Z��
    // �J�����̒��S���W
    static constexpr float kScreenCenterX = 50.0f;    // X���W
    static constexpr float kScreenCenterY = 500.0f;    // Y���W
};

