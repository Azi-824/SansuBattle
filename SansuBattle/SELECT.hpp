//Select.hpp
//�I����ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Button.hpp"
#include "Group.hpp"

//############# �}�N����` ##############
#define BT_MODE_DRAW_X		40	//�Q�[�����[�h�̑I�����̕`��J�nX�ʒu
#define BT_MODE_DRAW_Y		40	//�Q�[�����[�h�̑I�����̕`��J�nY�ʒu
#define BT_LEVEL_DRAW_X		0	//���x���̑I�����̕`��J�nX�ʒu
#define BT_LEVEL_DRAW_Y		250	//���x���̑I�����̕`��J�nY�ʒu
#define BT_NEXT_DRAW_X		620	//���i�E�j�̕`��X�ʒu
#define BT_PREV_DRAW_X		50	//���i���j�̕`��X�ʒu

#define BT_MODE_INTERVAL_SIDE		30		//�Q�[�����[�h�I�����̊Ԋu(��)
#define BT_MODE_INTERVAL_VERTICAL	150		//�Q�[�����[�h�I�����̊Ԋu(�c)
#define BT_LEVEL_INTERVAL_SIDE		10		//���x���I�����̊Ԋu(�c)
#define BT_LEVEL_INTERVAL_VERTICAL	0		//���x���I�����̊Ԋu(��)
#define BT_START_INTERVAL_SIDE		80		//�X�^�[�g�̑I�����̊Ԋu�i���j

//############# �N���X��` ##############
class Select : public Scene	//Scene���p��
{
private:

	vector<Button*> mode;		//�Q�[�����[�h
	vector<Image*> mode_img;	//�Q�[�����[�h�摜
	vector<Button*> level;		//�Q�[�����x��
	vector<Image*> level_img;	//�Q�[�����x���摜
	Button* next;				//���̃y�[�W�ֈړ�����{�^��
	Button* prev;				//�O�̃y�[�W�ֈړ�����{�^��
	Button* cancel;				//���x���I������A���[�h�I���֖߂�{�^��

	Group* mode_group;			//�Q�[�����[�h�̃O���[�v
	Group* level_group;			//�Q�[�����x���̃O���[�v

	void Start() override;		//�V�[�����ς�邲�Ƃ�1�񂾂��s������

public:

	Select();			//�R���X�g���N�^
	~Select();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;		//�I����ʂ̏���

};
