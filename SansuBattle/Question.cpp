//Question.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Question.hpp"

//############### �N���X��` ####################

//�C���X�^���X�𐶐�
Image* Question::img_kokuban;			//���̉摜

//�R���X�g���N�^
Question::Question()
{
	//�����o�[������
	Anser = -1;				//����������
	InputNum = 0;			//���͂��ꂽ����������
	InputNumBuf = 0;		//���߂Ă��鐔����������
	Q_Text = "";			//��蕶������
	IsCreate = false;		//�����쐬������������

	if (img_kokuban == NULL)	//���̉摜�𐶐����Ă��Ȃ����
	{
		img_kokuban = new Image(Q_IMAGE_DIR, Q_IMAGE_KOKUBAN_NAME);	//���̉摜�𐶐�
	}
	return;
}

//�f�X�g���N�^
Question::~Question()
{
	return;
}

//���쐬
void Question::Create(int gamemode, int gamelevel)
{
	int min = 0, max = 0;	//���̍ŏ��l�A�ő�l
	SetMinMax(gamemode, gamelevel, &min, &max);	//���̍ŏ��l�A�ő�l�ݒ�

	int num1 = 0, num2 = 0;		//��������ϐ�

	num1 = GetRand(max - min) + min;			//���𐶐�
	num2 = GetRand(max - min) + min;			//���𐶐�

	CreateQuestion(gamemode, num1, num2);		//�Q�[�����[�h���̖����쐬�B
	IsCreate = true;	//�����쐬����

}

//�w�肳�ꂽ�Q�[�����[�h�A�Q�[�����x���̖��̍ő�l�ŏ��l��ݒ�
void Question::SetMinMax(int gamemode, int gamelevel, int* min, int* max)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case Q_MODE_SUM:	//�����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case STAGE_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case STAGE_LEVEL_NORMAL:	//���ʂ̎�

			*min = 10;	//�ŏ��l10
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case STAGE_LEVEL_HARD:	//����̎�

			*min = 20;	//�ŏ��l20
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�����Z�̎������܂�

	case Q_MODE_DIFFERENCE:	//�����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case STAGE_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case STAGE_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case STAGE_LEVEL_HARD:	//����̎�

			*min = 10;	//�ŏ��l10
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�����Z�̎������܂�

	case Q_MODE_PRODUCT:	//�|���Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case STAGE_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case STAGE_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case STAGE_LEVEL_HARD:	//����̎�

			*min = 10;	//�ŏ��l10
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�|���Z�̎������܂�

	case Q_MODE_DEALER:		//����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case STAGE_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case STAGE_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case STAGE_LEVEL_HARD:	//����̎�

			*min = 10;	//�ŏ��l10
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;		//����Z�̎������܂�

	default:
		break;
	}

}

//�Q�[�����[�h���̖����쐬
void Question::CreateQuestion(int gamemode,int num1, int num2)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case Q_MODE_SUM:	//�����Z�̎�

		Anser = num1 + num2;	//�����Z�̓�����ݒ�
		Q_Text = (std::to_string(num1) + "�{" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//�����Z�̎������܂�

	case Q_MODE_DIFFERENCE:	//�����Z�̎�

		if (num1 < num2)		//num1�̒l��num2��菬�����Ƃ�
		{
			//�l�̌���
			int w = num2;
			num2 = num1;
			num1 = w;
		}
		Anser = num1 - num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
		Q_Text = (std::to_string(num1) + "�|" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//�����Z�̎������܂�

	case Q_MODE_PRODUCT:	//�|���Z�̎�

		Anser = num1 * num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
		Q_Text = (std::to_string(num1) + "�~" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//�|���Z�̎������܂�

	case Q_MODE_DEALER:		//����Z�̎�

		if (num1 % num2 != 0)	//����؂�Ȃ���
		{
			num1 -= num1 % num2;	//����؂��悤�ɒ���
		}
		Anser = num1 / num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
		Q_Text = (std::to_string(num1) + "��" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//����Z�̎������܂�

	default:
		break;
	}
}

//����`�悷��
void Question::DrawQuestion()
{

	img_kokuban->Draw(GAME_LEFT, Q_IMG_DRAW_Y);		//���̉摜��`��

	int Strlen = strlen(Q_Text.c_str());					//�����񒷂����擾
	int Width = GetDrawStringWidthToHandle(Q_Text.c_str(), Strlen, NowFontHandle);	//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), Q_DRAW_Y, COLOR_WHITE, NowFontHandle, "%s", Q_Text.c_str());	//��蕶��`��

	return;
}

//���͒��̐�����`�悷��
void Question::DrawInputNum()
{
	int Strlen = strlen(std::to_string(InputNum).c_str());						//������̒������擾
	int Width = GetDrawStringWidthToHandle(std::to_string(InputNum).c_str(), Strlen, NowFontHandle);	//�����擾
	int Height = GetFontSizeToHandle(NowFontHandle);							//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), COLOR_WHITE, NowFontHandle, "%d", InputNum);	//���͒��̐�����`��

}

//���������肷��
/*
�����Fint�F�v���C���[�̓���
�߂�l�Fbool�Ftrue �����Ffalse �s����
*/
bool Question::JudgAnser()
{
	if (Anser == InputNum)				//�v���C���[�̉񓚂��A�����ƈꏏ��������
	{
		Question::IsCreate = false;		//�����쐬�������A���Z�b�g
		return true;					//����
	}
	else								//�ꏏ����Ȃ�������
		return false;					//�s����
}

//�L�[���͒����m�F
//�߂�l�Fbool�Ftrue ���͏I���Ffalse ���͒�
bool Question::CheckInputKey(KeyDown* keydown)
{
	static int Weight = 10;					//���̏d��
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
int Question::GetInputNum(KeyDown* keydown)
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
bool Question::GetIsCreate()
{
	return IsCreate;
}

//�������Z�b�g
void Question::Reset()
{
	Anser = -1;			//�������Z�b�g
	InputNum = 0;		//�L�[���͓��e���Z�b�g
	InputNumBuf = 0;	//���߂Ă��鐔����������
	Q_Text = "";		//��蕶���Z�b�g
	IsCreate = false;	//�����쐬���������Z�b�g
}