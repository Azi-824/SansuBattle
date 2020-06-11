//ENEMY.hpp
//�G���Ǘ�����N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ####################
#include "CHARACTOR.hpp"

//############### �}�N����` ####################
#define IMG_DIR_ENEMY	R"(.\MY_IMG\Enemy)"			//�G�̉摜�̃f�B���N�g��

#define IMG_NAME_ENEMY_FIRST	R"(\enemy.png)"		//�G(1�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY_SECOND	R"(\enemy2.png)"	//�G(2�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY_THIRD	R"(\enemy3.png)"	//�G(3�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY_HP		R"(\enemy_hp.png)"	//�G��HP�̉摜�̖��O

#define ENEMY_HP_DRAW_X		20	//HP�̕`��J�nX�ʒu
#define ENEMY_HP_DRAW_Y		150	//HP�̕`��J�nY�ʒu

#define ENEMY_MAX		3			//�G�̍ő吔

//############### �N���X��` ####################
class ENEMY :public CHARACTOR		//CHARACTOR�N���X���p��
{
private:

	static int NowEnemyNum;						//���݉��̖ڂ̓G��

public:

	ENEMY(const char* ,const char*);	//�R���X�g���N�^
	~ENEMY();							//�f�X�g���N�^

	void Init();						//������

	static void NextEnemy();			//���̓G��
	static int GetNowEnemyNum();		//���݉��̖ڂ̓G���擾

	void DrawHp() override;				//HP�`��

};
