//GameMode.hpp
//�e�Q�[�����[�h�̊�ɂȂ�N���X

#pragma once

//############## �w�b�_�t�@�C���ǂݍ��� #############
#include "Global.hpp"
#include <string>
#include "KeyDown.hpp"
#include "Image.hpp"

//############## �}�N����` ###############
//���֌W
#define Q_IMG_DRAW_Y 490	//���̉摜�i���j�`��Y�ʒu
#define Q_DRAW_Y 500		//���̕`��Y�ʒu

#define Q_EASY_VALUE_MAX 9	//�ȒP���[�h�̖��̍ő�l

#define Q_IMAGE_DIR		R"(.\MY_IMG\Question)"		//���֌W�̉摜�̃f�B���N�g��

#define	Q_IMAGE_KOKUBAN_NAME	R"(\kokuban.png)"	//���̉摜�̖��O

//�X�R�A�֌W
#define TIME_BONUS_EXCELLENT	2		//�񓚎��Ԃ��G�N�Z�����g�̎��̃{�[�i�X�{��
#define TIME_BONUS_GREAT		1.5		//�񓚎��Ԃ��O���[�g�̎��̃{�[�i�X�{��
#define LEVEL_BONUS_EASY		1		//�ȒP���x���̃{�[�i�X�{��
#define LEVEL_BONUS_NORMAL		2		//���ʃ��x���̃{�[�i�X�{��
#define LEVEL_BONUS_HARD		3		//������x���̃{�[�i�X�{��

//################# �񋓌^ ###################
enum INPUT_NUM
{
	INPUT_NUM_0,		//���͒l0
	INPUT_NUM_1,		//���͒l1
	INPUT_NUM_2,		//���͒l2
	INPUT_NUM_3,		//���͒l3
	INPUT_NUM_4,		//���͒l4
	INPUT_NUM_5,		//���͒l5
	INPUT_NUM_6,		//���͒l6
	INPUT_NUM_7,		//���͒l7
	INPUT_NUM_8,		//���͒l8
	INPUT_NUM_9,		//���͒l9
	INPUT_ENTER = 100,	//����L�[
	INPUT_NOT_NUM = -1	//���l�ȊO
};		//���͒l�̒l

using std::string;

//############### �N���X��` #################
class GameMode
{
protected:

	//���֌W
	static Image* img_kokuban;		//���̉摜
	string Q_Text;					//��蕶
	int Anser;						//����
	int InputNum;					//���͂��ꂽ����
	bool IsCreate;					//�����쐬������

	//�X�R�A�֌W
	int Score;						//���_

private:

	int GetInputNum(KeyDown*);		//���͂��ꂽ�������擾

public:

	GameMode();						//�R���X�g���N�^
	~GameMode();					//�f�X�g���N�^

	//���֌W
	virtual void CreateQuestion(int) = 0;	//���쐬

	void DrawQuestion();			//����`�悷��
	void DrawInputNum();			//���͒��̐�����`�悷��

	bool JudgAnser();				//���������肷��

	bool CheckInputKey(KeyDown*);	//�L�[���͒����擾

	bool GetIsCreate();				//�����쐬�������擾

	void Reset();					//�������Z�b�g

	//�X�R�A�֌W
	virtual void CalcScore(int, int) = 0;	//�X�R�A�v�Z����
	void DrawNowScore();					//���݂̃X�R�A�\��
	void ResetScore();						//�X�R�A���Z�b�g

	int GetScore();							//�X�R�A�擾


};
