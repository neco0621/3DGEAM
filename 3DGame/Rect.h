#pragma once
#include "Vec3.h"
#include <DxLib.h>
//��`�̍��W���Ǘ�����N���X
class Rect
{
public:
	Rect();
	virtual ~Rect();

	//�`��
	void Draw(unsigned int Color, bool isFill);
	void Draw3D(unsigned int Color,unsigned int Color2, bool isFill);
	void DrawCircle2D(unsigned int Color, bool isFill);
	void DrawBall(unsigned int color, unsigned int color2, bool isFill);

	//������W�ƕ��������w��
	void SetLT(float left, float top, float width, float height);
	//������W�ƕ��ƍ����Ɖ��s���w��
	void SetLT3D(float left, float top, float back, float width, float height, float flont);
	//���S���W�ƕ��������w��
	void SetCenter(float x, float y, float width, float height);
	//���S���W�ƕ��ƍ����Ɖ��s�����w��
	void SetCenter3D(float x, float y, float width, float height, float z, float back);
	//���S���W�Ɣ��a���w��
	void SetRadius(float x, float y, float radius);
	//���S���W�Ɣ��a�Ɖ��s���w��
	void SetRadius3D(float x, float y, float z, float radius);

	//�Q�[���ɂ���Ă͒��S���W�Ŏw�肵���葫���̍��W�Ŏw�肷��
	//set�֐����������ق����֗���������Ȃ�

	//�K�v�ȏ����擾����
	float GetWidth() const;		//��
	float GetHeight() const;	//����
	float GetBack() const;		//���s
	Vec3 GetCenter() const;		//���S���W
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

	//��`���m�̓����蔻��
	bool BoxCollision(const Rect& rect);
	bool BoxCollision3D(const Rect& rect);
	bool CirCleCollision(const Rect& rect);
	bool SphereCollision(const Rect& rect);
	bool DistanceCollision(const Rect& rect);

	float m_left;	//�����X���W
	float m_right;	//�E���X���W
	float m_top;	//�����Y���W
	float m_bottom;	//�E���Y���W
	float m_back;	//����Z���W
	float m_flont;	//��O��Z���W

	float m_centerX;	//���S��X���W
	float m_centerY;	//���S��Y���W
	float m_centerZ;	//���S��Z���W
	float m_radius;		//���a

	int DivNum;	//�|���S����
};