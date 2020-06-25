//Question.hpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include <string>
#include "KeyDown.hpp"
#include "Image.hpp"

//################# �}�N����` #################
#define Q_IMG_DRAW_Y 490	//���̉摜�i���j�`��Y�ʒu
#define Q_DRAW_Y 500		//���̕`��Y�ʒu

#define Q_EASY_VALUE_MAX 9	//�ȒP���[�h�̖��̍ő�l

#define Q_IMAGE_DIR		R"(.\MY_IMG\Question)"		//���֌W�̉摜�̃f�B���N�g��

#define	Q_IMAGE_KOKUBAN_NAME	R"(\kokuban.png)"	//���̉摜�̖��O

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


//################# �N���X��` #################
class Question
{
protected:

	static Image* img_kokuban;			//���̉摜

	std::string Q_Text;			//��蕶
	int Anser;					//����
	int InputNum;				//���͂��ꂽ����
	int InputNumBuf;			//���͂��ꂽ�����𒙂߂Ă���
	bool IsCreate;				//�����쐬������

private:

	int GetInputNum(KeyDown*);	//���͂��ꂽ�������擾
	void SetMinMax(int, int, int*, int*);	//�w�肳�ꂽ�Q�[�����[�h�A�Q�[�����x���̖��̍ő�l�ŏ��l��ݒ�
	void CreateQuestion(int, int, int);		//�Q�[�����[�h�A�Q�[�����x�����̖����쐬

public:

	Question();							//�R���X�g���N�^
	~Question();						//�f�X�g���N�^

	void Create(int, int);			//���쐬

	void DrawQuestion();			//����`�悷��
	void DrawInputNum();			//���͒��̐�����`�悷��

	bool JudgAnser();			//���������肷��

	bool CheckInputKey(KeyDown*);//�L�[���͒����擾

	bool GetIsCreate();			//�����쐬�������擾

	void Reset();				//�������Z�b�g


};
