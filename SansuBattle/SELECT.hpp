//SELECT.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "DxLib.h"
#include "IMAGE.hpp"
#include <vector>

//##################### �}�N����` ######################
#define SELECT_IMG_DIR			R"(.\MY_IMG\Select)"		//�I�����̉摜�f�B���N�g��

#define IMG_NAME_SELECT_DAMMY1	R"(\dammy01.png)"			//�I�����̃_�~�[�摜1
#define IMG_NAME_SELECT_DAMMY2	R"(\dammy02.png)"			//�I�����̃_�~�[�摜2
#define IMG_NAME_SELECT_DAMMY3	R"(\dammy03.png)"			//�I�����̃_�~�[�摜3
#define IMG_NAME_SELECT_DAMMY4	R"(\dammy04.png)"			//�I�����̃_�~�[�摜4
#define IMG_NAME_SELECT_DAMMY5	R"(\dammy05.png)"			//�I�����̃_�~�[�摜5
#define IMG_NAME_SELECT_DAMMY6	R"(\dammy06.png)"			//�I�����̃_�~�[�摜6

#define SELECT_LEVEL_DRAW_X		20	//��Փx�̑I�����̕`��J�nX�ʒu
#define SELECT_LEVEL_DRAW_Y		20	//��Փx�̑I�����̕`��J�nY�ʒu

#define SELECT_INTERVAL		20		//�I�����̊Ԋu

//##################### �N���X��` ######################
class SELECT
{

private:

	IMAGE* SelectImage;							//�I�����̉摜

	std::vector<int> SelectCode;				//�I�����̃R�[�h�ԍ�

	int Choise_SelectCode;						//�I�񂾑I�����̃R�[�h�ԍ�

	bool IsCreateSelect;						//�I��������ꂽ��
	bool IsChoise;								//�I��������

public:

	SELECT(const char *,const char *);			//�R���X�g���N�^
	~SELECT();									//�f�X�g���N�^

	bool GetIsCreateSelect();					//�I��������ꂽ���擾

	void SetInit();								//�����ݒ�

	bool Add(const char*, const char*);			//�I������ǉ�

	void Draw(int,int,int);						//�I������`��

};
