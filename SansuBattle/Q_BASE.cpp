//Q_BASE.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Q_BASE.hpp"

//############### �N���X��` ####################

//�C���X�^���X�𐶐�
int Q_BASE::Anser = -1;				//����������
int Q_BASE::InputNum = 0;			//���͂��ꂽ����������
std::string Q_BASE::Q_Text = "";	//��蕶������
bool Q_BASE::IsCreate = false;		//�����쐬������������
int Q_BASE::SelectLevel = -1;		//�I���������̃��x��
IMAGE* Q_BASE::img_kokuban;			//���̉摜

//�R���X�g���N�^
Q_BASE::Q_BASE()
{
	if (img_kokuban == NULL)	//���̉摜�𐶐����Ă��Ȃ����
	{
		img_kokuban = new IMAGE(Q_IMAGE_DIR, Q_IMAGE_KOKUBAN_NAME);	//���̉摜�𐶐�
	}
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

	img_kokuban->Draw(GAME_LEFT, Q_IMG_DRAW_Y);		//���̉摜��`��

	int Strlen = strlen(Q_Text.c_str());					//�����񒷂����擾
	int Width = GetDrawStringWidth(Q_Text.c_str(), Strlen);	//�����擾

	DrawFormatString((GAME_WIDTH / 2) - (Width / 2), Q_DRAW_Y, COLOR_WHITE, "%s", Q_Text.c_str());		//��蕶��`��

	return;
}

//���͒��̐�����`�悷��
void Q_BASE::DrawInputNum()
{
	int Strlen = strlen(std::to_string(InputNum).c_str());						//������̒������擾
	int Width = GetDrawStringWidth(std::to_string(InputNum).c_str(), Strlen);	//�����擾
	int Height = GetFontSize();													//�����擾

	DrawFormatString((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), COLOR_WHITE, "%d", InputNum);	//���͒��̐�����`��


}

//���������肷��
/*
�����Fint�F�v���C���[�̓���
�߂�l�Fbool�Ftrue �����Ffalse �s����
*/
bool Q_BASE::JudgAnser()
{
	if (Anser == InputNum)				//�v���C���[�̉񓚂��A�����ƈꏏ��������
	{
		Q_BASE::IsCreate = false;		//�����쐬�������A���Z�b�g
		return true;					//����
	}
	else								//�ꏏ����Ȃ�������
		return false;					//�s����
}

//�L�[���͒����m�F
//�߂�l�Fbool�Ftrue ���͏I���Ffalse ���͒�
bool Q_BASE::CheckInputKey(KEYDOWN* keydown)
{
	static int InputNumBuf = 0;						//���͂��ꂽ����
	static int Weight = 10;							//���̏d��
	int NewInputNum = GetInputNum(keydown);	//�V���ɓ��͂��ꂽ����

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

	InputNum = InputNumBuf;	//���͂��ꂽ������ݒ�

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

//�����쐬�������擾
bool Q_BASE::GetIsCreate()
{
	return IsCreate;
}
