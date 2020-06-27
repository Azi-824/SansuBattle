//Question.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Question.hpp"

//############### �N���X��` ####################

//�C���X�^���X�𐶐�
Image* Question::img_kokuban;			//���̉摜
vector<vector<int>> Question::min_list;	//�ŏ��l�̃��X�g
vector<vector<int>> Question::max_list;	//�ő�l�̃��X�g

//�R���X�g���N�^
Question::Question()
{
	//�����o�[������
	Anser = -1;				//����������
	InputNum = 0;			//���͂��ꂽ����������
	InputNumBuf = 0;		//���߂Ă��鐔����������
	Q_Text = "";			//��蕶������
	IsCreate = false;		//�����쐬������������

	if (min_list.empty() || max_list.empty())	//���X�g���쐬����Ă��Ȃ����
	{
		Create_Min_Max_List();	//���̍ŏ��l�ƍő�l�̃��X�g���쐬
	}

	if (img_kokuban == NULL)	//���̉摜�𐶐����Ă��Ȃ����
	{
		img_kokuban = new Image(Q_IMAGE_DIR, Q_IMAGE_KOKUBAN_NAME);	//���̉摜�𐶐�
	}
	
}

//�f�X�g���N�^
Question::~Question(){}

//���쐬
void Question::Create(int gamemode, int gamelevel)
{
	int min = 0, max = 0;	//���̍ŏ��l�A�ő�l
	//SetMinMax(gamemode, gamelevel, &min, &max);	//���̍ŏ��l�A�ő�l�ݒ�
	int calc_type = SetCalcType(gamemode);		//�v�Z�̎�ސݒ�
	min = min_list.at(calc_type).at(gamelevel);	//�ŏ��l�ݒ�
	max = max_list.at(calc_type).at(gamelevel);	//�ő�l�ݒ�

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

	case GAMEMODE_SUM:	//�����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case GAME_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case GAME_LEVEL_NORMAL:	//���ʂ̎�

			*min = 10;	//�ŏ��l10
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case GAME_LEVEL_HARD:	//����̎�

			*min = 20;	//�ŏ��l20
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�����Z�̎������܂�

	case GAMEMODE_DIFFERENCE:	//�����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case GAME_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case GAME_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case GAME_LEVEL_HARD:	//����̎�

			*min = 10;	//�ŏ��l10
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�����Z�̎������܂�

	case GAMEMODE_PRODUCT:	//�|���Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case GAME_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case GAME_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case GAME_LEVEL_HARD:	//����̎�

			*min = 10;	//�ŏ��l10
			*max = 30;	//�ő�l30

			break;	//����̎�

		default:
			break;
		}

		break;			//�|���Z�̎������܂�

	case GAMEMODE_DEALER:		//����Z�̎�

		switch (gamelevel)	//�Q�[�����x����
		{

		case GAME_LEVEL_EASY:	//�ȒP�̎�

			*min = 1;					//�ŏ��l1
			*max = Q_EASY_VALUE_MAX;	//�ő�l9

			break;	//�ȒP�̎�

		case GAME_LEVEL_NORMAL:	//���ʂ̎�

			*min = 5;	//�ŏ��l5
			*max = 20;	//�ő�l20

			break;	//���ʂ̎�

		case GAME_LEVEL_HARD:	//����̎�

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

//�v�Z�̎�ނ�ݒ�
int Question::SetCalcType(int gamemode)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case GAMEMODE_SUM:	//�����Z�̎�

		return CALC_SUM;

		break;			//�����Z�̎������܂�

	case GAMEMODE_DIFFERENCE:	//�����Z�̎�

		return CALC_DIFFERENCE;

		break;			//�����Z�̎������܂�

	case GAMEMODE_PRODUCT:	//�|���Z�̎�

		return CALC_PRODUCT;

		break;			//�|���Z�̎������܂�

	case GAMEMODE_DEALER:		//����Z�̎�

		return CALC_DEALER;

		break;		//����Z�̎������܂�

	default:
		break;
	}

}

//�ŏ��l�A�ő�l�̃��X�g���쐬
void Question::Create_Min_Max_List()
{
	//�ŏ��l
	min_list.resize(CALC_MAX);	//�v�Z�̎�ނŃT�C�Y�ύX
	for (int i = 0; i < min_list.size(); ++i)
	{
		min_list.at(i).resize(GAME_LEVEL_MAX);	//�Q�[�����x���̎�ނŃT�C�Y�ύX
	}
	//�����Z
	min_list.at(CALC_SUM).at(GAME_LEVEL_EASY) = 1;			//�����Z�i�ȒP�j�̍ŏ��l
	min_list.at(CALC_SUM).at(GAME_LEVEL_NORMAL) = 10;		//�����Z�i���ʁj�̍ŏ��l
	min_list.at(CALC_SUM).at(GAME_LEVEL_HARD) = 20;			//�����Z�i����j�̍ŏ��l
	//�����Z
	min_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_EASY) = 1;	//�����Z�i�ȒP�j�̍ŏ��l
	min_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_NORMAL) = 5;	//�����Z�i���ʁj�̍ŏ��l
	min_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_HARD) = 10;	//�����Z�i����j�̍ŏ��l
	//�|���Z
	min_list.at(CALC_PRODUCT).at(GAME_LEVEL_EASY) = 1;		//�|���Z�i�ȒP�j�̍ŏ��l
	min_list.at(CALC_PRODUCT).at(GAME_LEVEL_NORMAL) = 5;	//�|���Z�i���ʁj�̍ŏ��l
	min_list.at(CALC_PRODUCT).at(GAME_LEVEL_HARD) = 10;		//�|���Z�i����j�̍ŏ��l
	//����Z
	min_list.at(CALC_DEALER).at(GAME_LEVEL_EASY) = 1;		//����Z�i�ȒP�j�̍ŏ��l
	min_list.at(CALC_DEALER).at(GAME_LEVEL_NORMAL) = 5;		//����Z�i���ʁj�̍ŏ��l
	min_list.at(CALC_DEALER).at(GAME_LEVEL_HARD) = 10;		//����Z�i����j�̍ŏ��l

	//�ő�l
	max_list.resize(CALC_MAX);	//�v�Z�̎�ނŃT�C�Y�ύX
	for (int i = 0; i < max_list.size(); ++i)
	{
		max_list.at(i).resize(GAME_LEVEL_MAX);	//�Q�[�����x���̎�ނŃT�C�Y�ύX
	}
	//�����Z
	max_list.at(CALC_SUM).at(GAME_LEVEL_EASY) = 9;			//�����Z�i�ȒP�j�̍ő�l
	max_list.at(CALC_SUM).at(GAME_LEVEL_NORMAL) = 20;		//�����Z�i���ʁj�̍ő�l
	max_list.at(CALC_SUM).at(GAME_LEVEL_HARD) = 30;			//�����Z�i����j�̍ő�l
	//�����Z
	max_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_EASY) = 9;	//�����Z�i�ȒP�j�̍ő�l
	max_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_NORMAL) = 20;//�����Z�i���ʁj�̍ő�l
	max_list.at(CALC_DIFFERENCE).at(GAME_LEVEL_HARD) = 30;	//�����Z�i����j�̍ő�l
	//�|���Z
	max_list.at(CALC_PRODUCT).at(GAME_LEVEL_EASY) = 9;		//�|���Z�i�ȒP�j�̍ő�l
	max_list.at(CALC_PRODUCT).at(GAME_LEVEL_NORMAL) = 20;	//�|���Z�i���ʁj�̍ő�l
	max_list.at(CALC_PRODUCT).at(GAME_LEVEL_HARD) = 30;		//�|���Z�i����j�̍ő�l
	//����Z
	max_list.at(CALC_DEALER).at(GAME_LEVEL_EASY) = 9;		//����Z�i�ȒP�j�̍ő�l
	max_list.at(CALC_DEALER).at(GAME_LEVEL_NORMAL) = 20;	//����Z�i���ʁj�̍ő�l
	max_list.at(CALC_DEALER).at(GAME_LEVEL_HARD) = 30;		//����Z�i����j�̍ő�l

}

//�Q�[�����[�h���̖����쐬
void Question::CreateQuestion(int gamemode,int num1, int num2)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case GAMEMODE_SUM:	//�����Z�̎�

		Anser = num1 + num2;	//�����Z�̓�����ݒ�
		Q_Text = (std::to_string(num1) + "�{" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//�����Z�̎������܂�

	case GAMEMODE_DIFFERENCE:	//�����Z�̎�

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

	case GAMEMODE_PRODUCT:	//�|���Z�̎�

		Anser = num1 * num2;	//���̌v�Z���ʂ𓚂��Ɋi�[
		Q_Text = (std::to_string(num1) + "�~" + (std::to_string(num2) + "���H"));		//��蕶��ݒ�

		break;			//�|���Z�̎������܂�

	case GAMEMODE_DEALER:		//����Z�̎�

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