//Question.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Question.hpp"

//############### �N���X��` ####################

//�C���X�^���X�𐶐�
Image* Question::img_kokuban;			//���̉摜
vector<CalcInfo*> Question::calc_info;	//�v�Z�Ɏg�p������
vector<vector<int>> Question::value_num;	//�l�̐�

//�R���X�g���N�^
Question::Question()
{
	//�����o�[������
	Anser = 0;				//����������
	InputNum = 0;			//���͂��ꂽ����������
	InputNumBuf = 0;		//���߂Ă��鐔����������
	Q_Text = "";			//��蕶������
	IsCreate = false;		//�����쐬������������

	if (calc_info.empty())	//�����쐬���Ă��Ȃ����
	{
		for (int i = CALC_SUM; i < CALC_MAX; ++i)	//�v�Z��ޕ�
		{
			CreateInfo(i);	//�����쐬
		}

		value_num.resize(GAMEMODE_MAX);	//�T�C�Y�ύX
		for (int i = GAMEMODE_SUM; i < GAMEMODE_MAX; ++i)	//�Q�[�����[�h�̎�ޕ�
		{
			CreateValueNum(i);	//�l�̐��̏����쐬
		}

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
	int min = 0, max = 0;				//���̍ŏ��l�A�ő�l
	vector<int> calc_value, calc_type;	//�l�A�v�Z�̎��

	SetCalcType(gamemode, gamelevel, &calc_type);	//�v�Z�̎�ނ�ݒ�

	for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)		//�v�Z�񐔕����[�v
	{
		min = calc_info.at(calc_type.at(i))->GetMin(gamelevel);	//�ŏ��l�擾
		max = calc_info.at(calc_type.at(i))->GetMax(gamelevel);	//�ŏ��l�擾

		calc_value.push_back(GetRand(max - min) + min);			//�l�𐶐�

	}

	vector<int> order;				//�v�Z�̏���
	SetOrder(calc_type, &order);	//�v�Z�̏��Ԃ�ݒ�

	CreateQuestion(calc_value, calc_type,order);	//���𐶐�

	IsCreate = true;	//�����쐬����

	//vector�̉��
	vector<int> v;
	calc_value.swap(v);
	vector<int> v2;
	calc_type.swap(v2);
	vector<int> v3;
	order.swap(v3);

}

//�v�Z�̎�ނ�ݒ�
void Question::SetCalcType(int gamemode, int gamelevel, vector<int>* calc_type)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case GAMEMODE_SUM:	//�����Z�̎�

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_SUM);	//�����Z
		}

		break;			//�����Z�̎������܂�

	case GAMEMODE_DIFFERENCE:	//�����Z�̎�

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_DIFFERENCE);	//�����Z
		}

		break;			//�����Z�̎������܂�

	case GAMEMODE_PRODUCT:	//�|���Z�̎�

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_PRODUCT);	//�|���Z
		}

		break;			//�|���Z�̎������܂�

	case GAMEMODE_DEALER:		//����Z�̎�

		for (int i = 0; i < value_num.at(gamemode).at(gamelevel); ++i)
		{
			calc_type->push_back(CALC_DEALER);	//����Z
		}

		break;		//����Z�̎������܂�

	default:
		break;
	}

}

//�v�Z�̏��Ԃ�ݒ�
void Question::SetOrder(vector<int> calc_type, vector<int>* order)
{
	vector<bool> set_flg;	//�ݒ�ς݂�

	for (int i = 0; i < calc_type.size(); ++i)
		set_flg.push_back(false);	//������

	for (int i = 0; i < calc_type.size(); ++i)
	{
		if (calc_type.at(i) == CALC_PRODUCT || calc_type.at(i) == CALC_DEALER)	//�|���Z���A����Z��������
		{
			order->push_back(i);	//�v�Z�̏��Ԃ�ݒ�
			set_flg.at(i) = true;	//�ݒ�ς�
		}

	}

	for (int i = 0; i < calc_type.size(); ++i)
	{
		if (!set_flg.at(i))	//�ݒ�ς݂���Ȃ����
		{
			order->push_back(i);	//�v�Z�̏��Ԃ�ݒ�
			set_flg.at(i) = true;	//�ݒ�ς�
		}
	}

	//vector�̉��
	vector<bool> v;
	set_flg.swap(v);

}

//���ꂼ��̖����쐬
void Question::CreateQuestion(vector<int>calc_value, vector<int>calc_type, vector<int> order)
{
	Q_Text = std::to_string(calc_value.at(order.front()));	//��ԍŏ��Ɍv�Z�����l���蕶�ɐݒ�

	for (int i = 0; i < order.size() - 1; ++i)
	{
		switch (calc_type.at(order.at(i)))	//�v�Z�̎�ނ��Ƃɕ���
		{

		case CALC_SUM:	//�����Z

			Q_Text += "�{";																				//���Z�L�����蕶�ɒǉ�
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) + calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�����Z

		case CALC_DIFFERENCE:	//�����Z

			Q_Text += "�|";																				//���Z�L�����蕶�ɒǉ�
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) - calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�����Z

		case CALC_PRODUCT:	//�|���Z

			Q_Text += "�~";																				//���Z�L�����蕶�ɒǉ�
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) * calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�|���Z

		case CALC_DEALER:	//����Z

			Q_Text += "��";																				//���Z�L�����蕶�ɒǉ�
			calc_value.at(order.at(i)) = calc_value.at(order.at(i)) / calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //����Z


		default:
			break;
		}

		Q_Text += std::to_string(calc_value.at(order.at(i) + 1));	//��蕶�ǉ�

		//�v�Z�ς݂̗v�f���폜
		calc_value.erase(calc_value.begin() + order.at(i) + 1);	//�v�Z�ς݂̒l���폜
		calc_type.erase(calc_type.begin() + order.at(i) + 1);	//�v�Z�ς݂̌v�Z��ނ��폜

		//�v�Z�ς݂̗v�f���폜�������߁A�v�Z���Ԃ�����O�ɌJ��グ��
		for (auto itr = order.begin(); itr != order.end(); ++itr)
		{
			if (*itr != 0)	//�擪����Ȃ����
				--* itr;
		}

	}

	Anser = calc_value.front();	//�擪�ɑS�Ă̌v�Z���ʂ��i�[����Ă��邽�߁A����𓚂��ɐݒ�
	Q_Text += "���H";			//��蕶�ǉ�

}

//�v�Z�Ɏg�p��������쐬
void Question::CreateInfo(int calctype)
{
	vector<int> min, max, value_num;	//�ŏ��l�A�ő�l�A��
	switch (calctype)	//�v�Z�̎��
	{

	case CALC_SUM:	//�����Z

		min.push_back(1);	//�ȒP�̍ŏ��l
		min.push_back(10);	//���ʂ̍ŏ��l
		min.push_back(20);	//����̍ŏ��l

		max.push_back(9);	//�ȒP�̍ő�l
		max.push_back(20);	//���ʂ̍ő�l
		max.push_back(30);	//����̍ő�l

		value_num.push_back(1);	//�ȒP�̌v�Z��
		value_num.push_back(1);	//���ʂ̌v�Z��
		value_num.push_back(1);	//����̌v�Z��

		break; //�����Z

	case CALC_DIFFERENCE:	//�����Z

		min.push_back(1);	//�ȒP�̍ŏ��l
		min.push_back(5);	//���ʂ̍ŏ��l
		min.push_back(10);	//����̍ŏ��l

		max.push_back(9);	//�ȒP�̍ő�l
		max.push_back(20);	//���ʂ̍ő�l
		max.push_back(30);	//����̍ő�l

		value_num.push_back(1);	//�ȒP�̌v�Z��
		value_num.push_back(1);	//���ʂ̌v�Z��
		value_num.push_back(1);	//����̌v�Z��

		break; //�����Z

	case CALC_PRODUCT:	//�|���Z

		min.push_back(1);	//�ȒP�̍ŏ��l
		min.push_back(5);	//���ʂ̍ŏ��l
		min.push_back(10);	//����̍ŏ��l

		max.push_back(9);	//�ȒP�̍ő�l
		max.push_back(20);	//���ʂ̍ő�l
		max.push_back(30);	//����̍ő�l

		value_num.push_back(1);	//�ȒP�̌v�Z��
		value_num.push_back(1);	//���ʂ̌v�Z��
		value_num.push_back(1);	//����̌v�Z��

		break; //�|���Z

	case CALC_DEALER:	//����Z

		min.push_back(1);	//�ȒP�̍ŏ��l
		min.push_back(5);	//���ʂ̍ŏ��l
		min.push_back(10);	//����̍ŏ��l

		max.push_back(9);	//�ȒP�̍ő�l
		max.push_back(20);	//���ʂ̍ő�l
		max.push_back(30);	//����̍ő�l

		value_num.push_back(1);	//�ȒP�̌v�Z��
		value_num.push_back(1);	//���ʂ̌v�Z��
		value_num.push_back(1);	//����̌v�Z��

		break; //����Z

	default:
		break;
	}

	calc_info.push_back(new CalcInfo(min, max, value_num));	//����ǉ�

}

//�Q�[�����[�h���̒l�̐��̏����쐬
void Question::CreateValueNum(int gamemode)
{
	switch (gamemode)	//�Q�[�����[�h��
	{

	case GAMEMODE_SUM:	//�����Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

		break;			//�����Z�̎������܂�

	case GAMEMODE_DIFFERENCE:	//�����Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

		break;			//�����Z�̎������܂�

	case GAMEMODE_PRODUCT:	//�|���Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

		break;			//�|���Z�̎������܂�

	case GAMEMODE_DEALER:		//����Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

		break;			//����Z�̎������܂�

	case GAMEMODE_SUM_DIFFERENCE:		//�����Z�A�����Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

		break;			//����Z�̎������܂�

	case GAMEMODE_PRODUCT_DEALER:		//�|���Z�A����Z�̎�

		value_num.at(gamemode).push_back(2);	//�ȒP�̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//���ʂ̎��̒l�̐�
		value_num.at(gamemode).push_back(2);	//����̎��̒l�̐�

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

	if (!(NewInputNum == INPUT_ENTER || NewInputNum == INPUT_NOT_NUM || NewInputNum == INPUT_BACK))	//���l����͂�����
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

		if (NewInputNum == INPUT_BACK)	//�o�b�N�X�y�[�X�������ꂽ��
		{
			InputNumBuf /= Weight;		//�ꕶ��������
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

	case KEY_INPUT_BACK:		//�o�b�N�X�y�[�X�L�[�������ꂽ�ꍇ

		return INPUT_BACK;		//�o�b�N

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
	Anser = 0;			//�������Z�b�g
	InputNum = 0;		//�L�[���͓��e���Z�b�g
	InputNumBuf = 0;	//���߂Ă��鐔����������
	Q_Text = "";		//��蕶���Z�b�g
	IsCreate = false;	//�����쐬���������Z�b�g
}