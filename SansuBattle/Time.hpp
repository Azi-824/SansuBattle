//Time.hpp
//���Ԃ��Ǘ�����N���X

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Global.hpp"

//################## �}�N����` ###################
#define GAME_LIMITTIME_DRAW_X	740		//�Q�[���̐������ԕ`��X�ʒu
#define GAME_LIMITTIME_DRAW_Y	0		//�Q�[���̐������ԕ`��Y�ʒu

#define GAME_LIMIT_TIME		30			//�Q�[���̐�������
#define MISS_MINUS_TIME		5			//�ԈႦ���Ƃ��̌��鎞��

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
