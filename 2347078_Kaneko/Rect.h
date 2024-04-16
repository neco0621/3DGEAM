#pragma once
#include "DxLib.h"
// ��`�̍��W���Ǘ����邽�߂̃N���X
class Rect
{
public:
	Rect();
	virtual ~Rect();

	//�l�p�̕`��
	void Draw(unsigned int Color, bool isFill);

	//���S���W�ƕ��������w��
	void SetCenter(float x, float y, float z,float width, float height);

	//�K�v�ȏ����擾����
	float GetWindth()const;		//��`�̕�
	float GetHeight() const;		//��`�̍���
	VECTOR GetCenter() const;	//��`�̒��S���W

	//��`�̓��m�̓����蔻��
	bool IsCollsion(const Rect& rect);

private:
	float m_left;  //�����X���W
	float m_top;   //�����Y���W
	float m_right; //�E����X���W
	float m_bottom;//�E����Y���W
};
