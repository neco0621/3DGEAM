#include "Rect.h"
#include <DxLib.h>
#include<cmath>
#include <cassert>

Rect::Rect() :
	m_left(0.0f),
	m_right(0.0f),
	m_top(0.0f),
	m_bottom(0.0f),
	m_back(0.0f),
	m_flont(0.0f),
	m_centerX(0.0f),
	m_centerY(0.0f),
	m_centerZ(0.0f),
	m_radius(0.0f),
	DivNum(16)
{
}

Rect::~Rect()
{
}

void Rect::Draw(unsigned int color, bool isFill)
{
	DrawBox(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_right), static_cast<int>(m_bottom), color, isFill);
}

void Rect::Draw3D(unsigned int color, unsigned int color2, bool isFill)
{
	DrawCube3D(VGet(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_back)), VGet(static_cast<int> (m_right), static_cast<int>(m_bottom), static_cast<int>(m_flont)), color, color2, isFill);
}

void Rect::DrawCircle2D(unsigned int color, bool isFill)
{
	DrawCircle(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int> (m_radius), color, isFill);
}

void Rect::DrawBall(unsigned int color, unsigned int color2, bool isFill)
{
	DrawSphere3D(VGet(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int>(m_centerZ)), static_cast<int> (m_radius),DivNum, color, color2, isFill);
}

void Rect::SetLT(float left, float top, float width, float height)
{
	m_left = left;			//左上のX座標
	m_top = top;			//左上のY座標
	m_right = left + width;	//右下のX座標
	m_bottom = top + height;//右下のY座標
}

void Rect::SetLT3D(float left, float top, float back, float width, float height, float flont)
{
	m_left = left;			//左上のX座標
	m_top = top;			//左上のY座標
	m_right = left + width;	//右下のX座標
	m_bottom = top + height;//右下のY座標
	m_flont = flont;		//手前のZ座標
	m_back = back;			//奥のZ座標
}

void Rect::SetCenter(float x, float y, float width, float height)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
}

void Rect::SetCenter3D(float x, float y, float width, float height, float z, float back)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_flont = z - back / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
	m_back = z + back / 2;
}


void Rect::SetRadius(float x, float y, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_radius = radius;
}

void Rect::SetRadius3D(float x, float y, float z, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_centerZ = z;
	m_radius = radius;
}

float Rect::GetWidth() const
{
	assert(m_right >= m_left);	//左右の座標の入れ替わりチェック

	return m_right - m_left;
}

float Rect::GetHeight() const
{
	assert(m_bottom >= m_top);	//上下の座標の入れ替わりチェック

	return m_bottom - m_top;
}

float Rect::GetBack() const
{
	assert(m_back >= m_flont);	//奥から手前の入れ替わりをチェック

	return m_back - m_flont;
}

Vec3 Rect::GetCenter() const
{
	//中心座標
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	x = (m_right + m_left) / 2;
	y = (m_top + m_bottom) / 2;
	z = (m_back + m_flont) / 2;

	return Vec3{ x,y,z };
}

float Rect::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool Rect::BoxCollision(const Rect& rect)
{
	//絶対に当たらないパターンをはじいていく
	if (m_left > rect.m_right)	return false;
	if (m_top > rect.m_bottom)	return false;
	if (m_right < rect.m_left)	return false;
	if (m_bottom < rect.m_top)	return false;

	//当たらないパターン以外は当たっている
	return true;
}

bool Rect::BoxCollision3D(const Rect& rect)
{
	//絶対に当たらないパターンをはじいていく
	if (m_left > rect.m_right)	return false;
	if (m_top > rect.m_bottom)	return false;
	if (m_right < rect.m_left)	return false;
	if (m_bottom < rect.m_top)	return false;
	if (m_flont > rect.m_back)  return false;
	if (m_back < rect.m_flont)	return false;
	//当たらないパターン以外は当たっている
	return true;
}

bool Rect::CirCleCollision(const Rect& rect)
{
	float dx = m_centerX - rect.m_centerX;
	float dy = m_centerY - rect.m_centerY;
	float dr = dx * dx + dy * dy;

	float ar = m_radius + rect.m_radius;
	float dl = ar * ar;
	if (dr <= dl)
	{
		return true;
	}
	return false;
}

bool Rect::SphereCollision(const Rect& rect)
{
	float dx = m_centerX - rect.m_centerX;
	float dy = m_centerY - rect.m_centerY;
	float dz = m_centerZ - rect.m_centerZ;
	float dr = dx * dx + dy * dy;
	float drXZ = dx * dx + dz * dz;
	float drYZ = dy * dy + dz * dz;

	float ar = m_radius + rect.m_radius;
	float dl = ar * ar;
	if (dr <= dl)
	{
		return true;
	}
	if (drXZ <= dl)
	{
		return true;
	}
	if (drYZ <= dl)
	{
		return true;
	}
	return false;
}


bool Rect::DistanceCollision(const Rect& rect)
{
	bool nResult = false;
	if ((m_centerX > rect.m_left - m_radius) &&
		(m_centerX < rect.m_right + m_radius) &&
		(m_centerY > rect.m_top - m_radius) &&
		(m_centerY < rect.m_bottom + m_radius))
	{
		nResult = true;
		float dl = m_radius * m_radius;
		// 左
		if (m_centerX < rect.m_left)
		{
			// 左上
			if ((m_centerY < rect.m_top))
			{
				if ((DistanceSqrf(rect.m_left, rect.m_top, m_centerX, m_centerY) >= dl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((m_centerY > rect.m_bottom))
				{
					if ((DistanceSqrf(rect.m_left, rect.m_bottom, m_centerX, m_centerY) >= dl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// 右
			if (m_centerX > rect.m_right)
			{
				// 右上
				if ((m_centerY < rect.m_top))
				{
					if ((DistanceSqrf(rect.m_right, rect.m_top, m_centerX, m_centerY) >= dl))
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
					if ((m_centerY > rect.m_bottom))
					{
						if ((DistanceSqrf(rect.m_right, rect.m_bottom, m_centerX, m_centerY) >= dl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}
