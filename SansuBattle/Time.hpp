//Time.hpp
//���Ԃ��Ǘ�����N���X

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ################
#include "Global.hpp"

//################## �}�N����` ###################
#define GAME_LIMITTIME_DRAW_X	740		//�Q�[���̐������ԕ`��X�ʒu
#define GAME_LIMITTIME_DRAW_Y	0		//�Q�[���̐������ԕ`��Y�ʒu

//################## �N���X��` ###################
class Time
{
private:

	int StartTime;					//�v���J�n����
	int ElapsedTime;				//�o�ߎ���

public:

	Time();							//�R���X�g���N�^
	~Time();						//�f�X�g���N�^

	void SetTime();					//�v���J�n
	void UpdateElpasedTime();		//�o�ߎ��ԍX�V
	void DrawElapsedTime(int, int);	//���ԕ`��

};
