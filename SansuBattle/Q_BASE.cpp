//Q_BASE.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Q_BASE.hpp"

//############### �N���X��` ####################

//�R���X�g���N�^
Q_BASE::Q_BASE()
{
	//�����o�[�ϐ�������
	this->Anser = -1;		//����������
	this->Q_Text = "";		//��蕶������
	this->InputNum = 0;		//���͂��ꂽ����������

	return;
}

//�f�X�g���N�^
Q_BASE::~Q_BASE()
{
	return;
}

//����`�悷��
void Q_BASE::DrawQuestion()
{

	DrawFormatString(Q_DRAW_X, Q_DRAW_Y, COLOR_WHITE, "%s", this->Q_Text.c_str());			//��蕶��`��

	DrawFormatString(GAME_WIDTH / 2, GAME_HEIGHT / 2, COLOR_WHITE, "%d", this->InputNum);	//���͒��̐�����`��

	return;
}

//���������肷��
/*
�����Fint�F�v���C���[�̓���
�߂�l�Fbool�Ftrue �����Ffalse �s����
*/
bool Q_BASE::JudgAnser()
{
	if (this->Anser == this->InputNum)	//�v���C���[�̉񓚂��A�����ƈꏏ��������
		return true;					//����
	else								//�ꏏ����Ȃ�������
		return false;					//�s����
}

//�L�[���͒����m�F
//�߂�l�Fbool�Ftrue ���͏I���Ffalse ���͒�
bool Q_BASE::CheckInputKey(KEYDOWN* keydown)
{
	static int InputNumBuf = 0;						//���͂��ꂽ����
	static int Weight = 10;							//���̏d��
	int NewInputNum = this->GetInputNum(keydown);	//�V���ɓ��͂��ꂽ����

	if (!(NewInputNum == INPUT_ENTER || NewInputNum == INPUT_NOT_NUM))	//���l����͂�����
	{
		if ((unsigned int)((InputNumBuf * Weight) + NewInputNum) < INT_MAX)		//int�^�̍ő�l�𒴂��Ȃ����
		{
			InputNumBuf = (InputNumBuf * Weight) + NewInputNum;	//���͒l�Ɍ��̏d�݂�t���Čv�Z
		}

	}
	else	//���l�ȊO����͂�����
	{
		if (NewInputNum == INPUT_ENTER)	//���肳�ꂽ�ꍇ
		{
			InputNumBuf = 0;	//������
			return true;		//���͏I��
		}
	}

	this->InputNum = InputNumBuf;	//���͂��ꂽ������ݒ�

	return false;
}

//���͂��ꂽ�������擾
int Q_BASE::GetInputNum(KEYDOWN* keydown)
{
	switch (keydown->GetInputKeyCode())		//���͂��ꂽ�L�[�R�[�h���Ƃɏ����𕪊�
	{

	case KEY_INPUT_0:		//0����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD0:	//�e���L�[��0����͂��ꂽ�ꍇ

		return INPUT_NUM_0;	//���͒l0

		break;

	case KEY_INPUT_1:		//1����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD1:	//�e���L�[��1����͂��ꂽ�ꍇ

		return INPUT_NUM_1;	//���͒l1

		break;

	case KEY_INPUT_2:		//2����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD2:	//�e���L�[��2����͂��ꂽ�ꍇ

		return INPUT_NUM_2;	//���͒l2

		break;

	case KEY_INPUT_3:		//3����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD3:	//�e���L�[��3����͂��ꂽ�ꍇ

		return INPUT_NUM_3;	//���͒l3

		break;

	case KEY_INPUT_4:		//4����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD4:	//�e���L�[��4����͂��ꂽ�ꍇ

		return INPUT_NUM_4;	//���͒l4

		break;

	case KEY_INPUT_5:		//5����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD5:	//�e���L�[��5����͂��ꂽ�ꍇ

		return INPUT_NUM_5;	//���͒l5

		break;

	case KEY_INPUT_6:		//6����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD6:	//�e���L�[��6����͂��ꂽ�ꍇ

		return INPUT_NUM_6;	//���͒l6

		break;

	case KEY_INPUT_7:		//7����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD7:	//�e���L�[��7����͂��ꂽ�ꍇ

		return INPUT_NUM_7;	//���͒l7

		break;

	case KEY_INPUT_8:		//8����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD8:	//�e���L�[��8����͂��ꂽ�ꍇ

		return INPUT_NUM_8;	//���͒l8

		break;

	case KEY_INPUT_9:		//9����͂��ꂽ�ꍇ
	case KEY_INPUT_NUMPAD9:	//�e���L�[��9����͂��ꂽ�ꍇ

		return INPUT_NUM_9;	//���͒l9

		break;

	case KEY_INPUT_RETURN:		//�G���^�[�L�[�i���肳�ꂽ�j�ꍇ
	case KEY_INPUT_NUMPADENTER:	//�e���L�[�ŃG���^�[�L�[�i���肳�ꂽ�j�ꍇ

		return INPUT_ENTER;		//����

		break;

	default:					//����ȊO�̏ꍇ�i�����ȊO�̓��͂̏ꍇ�j

		return INPUT_NOT_NUM;	//�����ȊO�̓���
		break;
	}
}