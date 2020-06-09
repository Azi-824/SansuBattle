//Q_BASE.hpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include <string>
#include "KEYDOWN.hpp"

//################# �}�N����` #################
#define Q_DRAW_X 100		//���̕`��X�ʒu
#define Q_DRAW_Y 100		//���̕`��Y�ʒu

#define Q_EASY_VALUE_MAX 9	//�ȒP���[�h�̖��̍ő�l

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
class Q_BASE
{
protected:

	std::string Q_Text;			//��蕶
	int Anser;					//����
	int InputNum;				//���͂��ꂽ����

private:


	int GetInputNum(KEYDOWN*);			//���͂��ꂽ�������擾

public:

	Q_BASE();							//�R���X�g���N�^
	~Q_BASE();							//�f�X�g���N�^

	void DrawQuestion();				//����`�悷��

	bool JudgAnser();					//���������肷��

	bool CheckInputKey(KEYDOWN*);		//�L�[���͒����擾


};
