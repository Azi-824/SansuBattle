//CHARACTOR.hpp
//�L�����N�^�[�N���X

#pragma once

//###################### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Global.hpp"
#include "KeyDown.hpp"
#include "Image.hpp"
#include <vector>

//###################### �}�N����` #######################
#define HP_INIT_VALUE	5	//HP�̏����l

using std::vector;

//###################### �N���X��` #######################
class Charactor
{
protected:

	Image* hp_img;				//HP�摜

	int HP_X;					//HP�@X�ʒu
	int HP_Y;					//HP  Y�ʒu

	int HP;						//HP
	bool reverse;				//���]�`�悷�邩

	bool IsArive;				//�����Ă��邩

public:

	Charactor();				//�R���X�g���N�^
	~Charactor();				//�f�X�g���N�^

	virtual void Init();		//������
	virtual bool SetInit();		//�����ݒ�

	bool GetIsArive();			//�����Ă��邩�擾

	void SendDamege();			//�_���[�W��^����
	void Kill();				//�L�������E��
	virtual void Draw();		//�`��
	int GetHp();				//HP�擾

};

