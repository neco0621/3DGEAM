#pragma once
#include <memory>

class SceneBase : public std::enable_shared_from_this<SceneBase>
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Init() = 0;	//�V�[���ɓ���Ƃ��̏���������

	//virtual SceneBase* Update() = 0;	//�V�[����ύX����ꍇ�͑J�ڐ�̃V�[���̃|�C���^
										//�V�[���ύX���Ȃ��ꍇ�͎��g�̃|�C���^

	virtual std::shared_ptr<SceneBase>Update() = 0;	//�V�[����ύX����ꍇ�͑J�ڐ�̃V�[���̃|�C���^
	//�V�[���ύX���Ȃ��ꍇ�͎��g�̃|�C���^

	virtual void Draw() = 0;	//���t���[���s���`�揈��

};

