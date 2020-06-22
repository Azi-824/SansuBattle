//Q_Base.hpp
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
class Q_Base
{
protected:

	static Image* img_kokuban;			//���̉摜

	static std::string Q_Text;			//��蕶
	static int Anser;					//����
	static int InputNum;				//���͂��ꂽ����
	static bool IsCreate;				//�����쐬������

private:

	static int GetInputNum(KeyDown*);	//���͂��ꂽ�������擾

public:

	Q_Base();							//�R���X�g���N�^
	~Q_Base();							//�f�X�g���N�^

	virtual void CreateQuestion(int) = 0;	//���쐬

	static void DrawQuestion();			//����`�悷��
	static void DrawInputNum();			//���͒��̐�����`�悷��

	static bool JudgAnser();			//���������肷��

	static bool CheckInputKey(KeyDown*);//�L�[���͒����擾

	static bool GetIsCreate();			//�����쐬�������擾

	static void Reset();				//�������Z�b�g


};
