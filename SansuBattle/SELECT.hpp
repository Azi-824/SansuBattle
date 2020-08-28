//Select.hpp
//�I����ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Button.hpp"

//############# �}�N����` ##############
#define SELECT_GAMEMODE_DRAW_X		40	//�Q�[�����[�h�̑I�����̕`��J�nX�ʒu
#define SELECT_GAMEMODE_DRAW_Y		40	//�Q�[�����[�h�̑I�����̕`��J�nY�ʒu
#define SELECT_LEVEL_DRAW_X		0		//���x���̑I�����̕`��J�nX�ʒu
#define SELECT_LEVEL_DRAW_Y		250		//���x���̑I�����̕`��J�nY�ʒu

#define ARROW_RIGHT_DRAW_X		620		//���i�E�j�̕`��X�ʒu
#define ARROW_LEFT_DRAW_X		50		//���i���j�̕`��X�ʒu

#define START_DRAW_X			70		//�X�^�[�g�̕`��X�ʒu
#define START_DRAW_Y			400		//�X�^�[�g�̕`��Y�ʒu

#define SELECT_GAMEMODE_INTERVAL_SIDE		30		//�Q�[�����[�h�I�����̊Ԋu(��)
#define SELECT_GAMEMODE_INTERVAL_VERTICAL	100		//�Q�[�����[�h�I�����̊Ԋu(�c)
#define SELECT_LEVEL_INTERVAL_SIDE			10		//���x���I�����̊Ԋu(�c)
#define SELECT_START_INTERVAL_SIDE			80		//�X�^�[�g�̑I�����̊Ԋu�i���j

#define RECT_EXPANSION_VALUE	20	//�̈�̊g���
#define RECT_TOUKA_VALUE		0.4	//�̈�̓��ߗ�

#define CHOISE_NONE	-1				//�I�����Ă��Ȃ����

#define PAGE_START	1				//�擪�̃y�[�W

//############# �N���X��` ##############
class Select : public Scene	//Scene���p��
{
private:

	vector<Button*> mode;		//�Q�[�����[�h
	vector<Image*> mode_img;	//�Q�[�����[�h�摜
	vector<Button*> level;		//�Q�[�����x��
	vector<Image*> level_img;	//�Q�[�����x���摜

public:

	Select();			//�R���X�g���N�^
	~Select();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;		//�I����ʂ̏���

};
