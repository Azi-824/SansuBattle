//CHARACTOR.hpp
//�L�����N�^�[�N���X

#pragma once

//###################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"
#include "KEYDOWN.hpp"
#include "IMAGE.hpp"

//###################### �}�N����` #######################
#define IMG_DIR_CHARA			R"(.\MY_IMG\Charactor)"		//�L�����N�^�[�̉摜�̃f�B���N�g��

#define IMG_NAME_PLAYER_HP		R"(\player_hp.png)"			//�v���C���[HP�摜�̖��O
#define IMG_NAME_ENEMY_HP		R"(\enemy_hp.png)"			//�G��HP�̉摜�̖��O


#define HP_INIT_VALUE	5	//HP�̏����l

//###################### �񋓌^ #################
enum HP_IMG_KIND
{
	HP_PLAYER,		//�v���C���[��HP
	HP_ENEMY		//�G��HP
};

//###################### �N���X��` #######################
class CHARACTOR
{
protected:

	static IMAGE* image_hp;		//HP�摜

	int DrawX;					//�`��X�ʒu
	int DrawY;					//�`��Y�ʒu

	int HP;						//HP

	bool IsArive;				//�����Ă��邩
	bool IsKeyOperation;		//�L�[�{�[�h�ő���ł��邩
	bool IsLoad;				//�ǂݍ��߂���

public:

	CHARACTOR();				//�R���X�g���N�^
	~CHARACTOR();				//�f�X�g���N�^

	void SetIsArive(bool);		//�����Ă��邩��ݒ�
	void SetKeyOperation(bool); //�L�[�{�[�h�ő���ł��邩�ݒ�

	void SetImagePos(int, int);	//�ʒu��ݒ肷��

	bool GetIsArive();			//�����Ă��邩�擾
	bool GetKeyOperation();		//�L�[�{�[�h�ő���ł��邩�擾
	bool GetIsLoad();			//�ǂݍ��߂����擾

	void Operation(KEYDOWN *);	//����

	virtual void SetInit(int x = 0, int y = 0);		//�����ݒ�

	void SendDamege();			//�_���[�W��^����

	virtual void DrawHp() = 0;	//HP�`��

	int GetHp();				//HP�擾

};

