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

private:    // 定数
    // 視野角
    static constexpr float kFov = (DX_PI_F / 180.0f) * 60.0f;
    // 手前クリップ距離
    static constexpr float kNear = 0.1f;
    // 奥クリップ距離
    static constexpr float kFar = 1000.0f;
    // カメラの初期注視点
    static constexpr float kTargetX = 10.0f;        // X軸
    static constexpr float kTargetY = 150.0f;    // Y軸
    static constexpr float kTargetZ = -400.0f;    // Z軸
    // カメラの中心座標
    static constexpr float kScreenCenterX = 50.0f;    // X座標
    static constexpr float kScreenCenterY = 500.0f;    // Y座標
};

