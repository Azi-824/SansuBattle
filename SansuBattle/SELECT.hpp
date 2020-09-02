//Select.hpp
//�I����ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Button.hpp"
#include "Group.hpp"

//############# �}�N����` ##############
#define ARROW_RIGHT_DRAW_X		620		//���i�E�j�̕`��X�ʒu
#define ARROW_LEFT_DRAW_X		50		//���i���j�̕`��X�ʒu

#define START_DRAW_X			70		//�X�^�[�g�̕`��X�ʒu
#define START_DRAW_Y			400		//�X�^�[�g�̕`��Y�ʒu

//############# �N���X��` ##############
class Select : public Scene	//Scene���p��
{
private:

	vector<Button*> mode;		//�Q�[�����[�h
	vector<Image*> mode_img;	//�Q�[�����[�h�摜
	vector<Button*> level;		//�Q�[�����x��
	vector<Image*> level_img;	//�Q�[�����x���摜

	Group* mode_group;			//�Q�[�����[�h�̃O���[�v
	Group* level_group;			//�Q�[�����x���̃O���[�v

public:

	Select();			//�R���X�g���N�^
	~Select();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;		//�I����ʂ̏���

};
