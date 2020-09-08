//Enemy.hpp
//�G���Ǘ�����N���X

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ####################
#include "Charactor.hpp"
#include "Effect.hpp"

//############### �}�N����` ####################
#define IMG_DIR_ENEMY	R"(.\Image\Enemy)"			//�G�̉摜�̃f�B���N�g��

#define IMG_NAME_ENEMY01	R"(\enemy.png)"		//�G(1�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY02	R"(\enemy2.png)"	//�G(2�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY03	R"(\enemy3.png)"	//�G(3�̖�)�̉摜�̖��O
#define IMG_NAME_ENEMY_HP	R"(\enemy_hp.png)"	//�G��HP�̉摜�̖��O

#define ENEMY_MAX		3			//�G�̍ő吔

//############### �N���X��` ####################
class Enemy :public Charactor		//CHARACTOR�N���X���p��
{
private:

	Image* img;				//�摜
	Effect* damege;			//�_���[�W�G�t�F�N�g
	RECT rect;				//�`��͈�
	bool dmgFlg;			//�_���[�W�t���O

	static bool AllKill;	//�S�Ă̓G��|������
	static int NowEnemyNum;	//���݉��̖ڂ̓G��

public:

	Enemy(const char* ,const char*);	//�R���X�g���N�^
	~Enemy();							//�f�X�g���N�^

	bool SetInit() override;			//�����ݒ�
	void Init() override;				//������

	static void NextEnemy();			//���̓G��
	static int GetNowEnemyNum();		//���݉��̖ڂ̓G���擾

	void Draw() override;				//�G�L�����`��
	bool GetFadeEnd();					//�t�F�[�h�A�E�g�I��������
	void SetDamegeFlg(bool);			//�_���[�W�t���O�ݒ�
	bool GetIsEffectEnd();				//�G�t�F�N�g�I��������
	static bool GetAllEnemyKilled();	//���ׂĂ̓G��|������

};
