#include "Camera.h"
#include "Player.h"
#include "Bg.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);

	//(0,10,-20)の視点から(0,10,0)のターゲットを見る角度にカメラを設置
	m_pos = VGet(0, 10, -20);
	SetCameraPositionAndTarget_UpVecY(m_pos, VGet(0.0f, 10.0f, 0.0f));
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Camera::Update(const Player& player)
{
    // カメラ位置の調整
    VECTOR aimPos = VGet(player.GetPos().x, kTargetY, kTargetZ);
    VECTOR posToAim = VSub(aimPos, m_pos);
    m_pos = VAdd(m_pos, posToAim);

    // カメラ位置を反映
    SetCameraScreenCenter(kScreenCenterX, kScreenCenterY);
    SetCameraPositionAndTarget_UpVecY(m_pos, VGet(player.GetPos().x, kTargetY, 0.0f));
}