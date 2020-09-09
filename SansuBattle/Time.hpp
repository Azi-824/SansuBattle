//Time.hpp
//���Ԃ��Ǘ�����N���X

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Global.hpp"

//################## �}�N����` ###################
#define CHENGE_TIME 5	//�`��F��؂�ւ�������
//################## �N���X��` ###################
class Time
{
private:

	int StartTime;						//�v���J�n����
	int ElapsedTime;					//�o�ߎ���
	int LimitTime;						//��������
	int LimitInit;						//�������Ԃ̏����l
	int NowLimitTime;					//�c��̐�������

public:

	Time();								//�R���X�g���N�^
	Time(int);							//�R���X�g���N�^�i�������Ԃ̐ݒ�t���j
	~Time();							//�f�X�g���N�^

	void SetTime();						//�v���J�n
	void UpdateElpasedTime();			//�o�ߎ��ԍX�V
	void UpdateLimitTime();				//�������ԍX�V
	void DrawElapsedTime(int, int);		//�o�ߎ��ԕ`��
	void DrawLimitTime(int, int);		//�������ԕ`��

	int GetElapsedTime();				//�o�ߎ��Ԏ擾
	bool GetIsLimit();					//�������Ԃ��߂�����

	void MinusLimitTime(int);			//�c��̐������Ԃ��}�C�i�X����

};
