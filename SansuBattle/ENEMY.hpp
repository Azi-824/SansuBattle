//ENEMY.hpp
//�G���Ǘ�����N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ####################
#include "CHARACTOR.hpp"

//############### �}�N����` ####################
#define IMG_DIR_ENEMY	R"(.\MY_IMG\Enemy)"			//�G�̉摜�̃f�B���N�g��

#define IMG_NAME_ENEMY	R"(\enemy.png)"				//�G�̉摜�̖��O

#define ENEMY_DRAW_X	300			//�G�`��X�ʒu
#define ENEMY_DRAW_Y	300			//�G�`��Y�ʒu

//############### �N���X��` ####################
class ENEMY :public CHARACTOR		//CHARACTOR�N���X���p��
{
private:

public:

	ENEMY(const char* ,const char*);	//�R���X�g���N�^
	~ENEMY();							//�f�X�g���N�^

	void DrawImage();					//�摜�`��

};
