//Question.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Question.hpp"

//############### �N���X��` ####################

//�C���X�^���X�𐶐�
Image* Question::img_kokuban;					//���̉摜
vector<vector<int>> Question::ValueNum_Table;	//�l�̐�
vector<vector<int>> Question::CalcType_Table;	//�e�Q�[�����[�h�̌v�Z�̎�ނ̃e�[�u��

//�R���X�g���N�^
Question::Question()
{
	//�����o�[������
	Anser = 0;				//����������
	InputNum = 0;			//���͂��ꂽ����������
	InputNumBuf = 0;		//���߂Ă��鐔����������
	Q_Text = "";			//��蕶������
	IsCreate = false;		//�����쐬������������

	if (ValueNum_Table.empty())	//�����쐬���Ă��Ȃ����
	{
		//�e�[�u���쐬
		CreateTable();		//�e�[�u���쐬

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
	int min = 3, max = 0;				//���̍ŏ��l�A�ő�l

	vector<int> value, type;	//�l�A�v�Z�̎��

	SetCalcType(gamemode, gamelevel, &type);	//�v�Z�̎�ނ�ݒ�

	for (int i = 0; i < ValueNum_Table.at(gamemode).at(gamelevel); ++i)
	{
		max = GetMax(gamelevel, value);				//�ő�l�ݒ�
		int rand = GetRand(max - min) + min;		//�l�������_���Ő���

		value.push_back(rand);	//�l��ǉ�
	}


	vector<int> order;		//�v�Z�̏���
	SetOrder(type, &order);	//�v�Z�̏��Ԃ�ݒ�

	CreateQuestion(value, type, order);	//���𐶐�

	IsCreate = true;	//�����쐬����

	//vector�̉��
	vector<int> v;
	value.swap(v);
	vector<int> v2;
	type.swap(v2);
	vector<int> v3;
	order.swap(v3);

}

//�v�Z�̎�ނ�ݒ�
void Question::SetCalcType(int gamemode, int gamelevel, vector<int>* calc_type)
{

	for (int i = 0; i < ValueNum_Table.at(gamemode).at(gamelevel) - 1; ++i)
	{
		int rand = GetRand(CalcType_Table.at(gamemode).size() - 1);		//��������
		calc_type->push_back(CalcType_Table.at(gamemode).at(rand));		//�v�Z�̎�ނ�ݒ�
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

//�ő�l�擾
int Question::GetMax(int gamelevel, vector<int> value)
{

	//���x�����̍ő�l
	const int value_max[GAME_LEVEL_MAX] = { EASY_VALUE_MAX ,NORMAL_VALUE_MAX ,HARD_VALUE_MAX };

	if (value.empty())	//�ŏ��̎擾�Ȃ�
	{
		//�萔��Ԃ�
		return value_max[gamelevel];	//�Q�[�����x�����̍ő�l��Ԃ�

	}
	else	//�ŏ�����Ȃ����
	{
		return GetRand(value.back());	//�Ō�̒l���ő�l�Ƃ���������Ԃ�
	}
}

//���ꂼ��̖����쐬
void Question::CreateQuestion(vector<int>calc_value, vector<int>calc_type, vector<int> order)
{

	auto type_cp = calc_type;	//��ނ̃R�s�[
	auto value_cp = calc_value;	//�l�̃R�s�[
	auto order_cp = order;		//���Ԃ̃R�s�[

	for (int i = 0; i < order.size(); ++i)
	{
		switch (calc_type.at(order.at(i)))	//�v�Z�̎�ނ��Ƃɕ���
		{

		case CALC_SUM:	//�����Z

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) + calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�����Z

		case CALC_DIFFERENCE:	//�����Z

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) - calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�����Z

		case CALC_PRODUCT:	//�|���Z

			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) * calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //�|���Z

		case CALC_DEALER:	//����Z

			//�l�̒���
			while (calc_value.at(order.at(i)) % calc_value.at(order.at(i) + 1) != 0)	//����؂�Ȃ���
			{
				//����؂��l�ɂȂ�܂ŁA�l�����炷
				--calc_value.at(order.at(i) + 1);
			}
			value_cp.at(order.at(i) + 1) = calc_value.at(order.at(i) + 1);	//�l��ω����������߁A�R�s�[�̕����X�V����
			calc_value.at(order.at(i) + 1) = calc_value.at(order.at(i)) / calc_value.at(order.at(i) + 1);	//�w�肳�ꂽ�l�ƁA���̎��̒l�Ōv�Z

			break; //����Z


		default:
			break;
		}

		//�v�Z�ς݂̗v�f���폜
		calc_value.erase(calc_value.begin() + order.at(i));		//�v�Z�ς݂̒l���폜
		calc_type.erase(calc_type.begin() + order.at(i));		//�v�Z�ς݂̌v�Z��ނ��폜

		//�v�Z�ς݂̗v�f���폜�������߁A�v�Z���Ԃ�����O�ɌJ��グ��
		for (auto itr = order.begin(); itr != order.end(); ++itr)
		{
			if (*itr != 0)	//�擪����Ȃ����
				--* itr;
		}

	}

	SetText(value_cp, type_cp, order_cp);	//��蕶�̃e�L�X�g��ݒ�

	Anser = calc_value.front();	//�擪�ɑS�Ă̌v�Z���ʂ��i�[����Ă��邽�߁A����𓚂��ɐݒ�

}

//�e�Q�[�����[�h�̌v�Z�̎�ނ̃e�[�u��
void Question::CreateTable()
{

	vector<int> work;	//��Ɨp

	//**************************** �e�Q�[�����[�h�̒l�̐��̃e�[�u�� **************************
	//�����Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//�����Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//�����Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//�����Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//�|���Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//�|���Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//����Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//����Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//�����Z�A�����Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//�����Z�A�����Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//�|���Z�A����Z���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//�|���Z�A����Z���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//+*���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//+*���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//+/���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//+/���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//-*���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//-*���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//+-*���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//+-*���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//+-/���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//+-/���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A

	//all���[�h
	work.push_back(2);		//�ȒP
	work.push_back(3);		//����
	work.push_back(4);		//���
	ValueNum_Table.push_back(work);	//all���[�h�̒l�̐���ǉ�
	work.clear();					//���g���N���A


	//**************************** �e�Q�[�����[�h�̌v�Z�̎�ނ̃e�[�u�� **************************
	//�����Z���[�h
	work.push_back(CALC_SUM);		//�����Z
	CalcType_Table.push_back(work);	//�����Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//�����Z���[�h
	work.push_back(CALC_DIFFERENCE);//�����Z
	CalcType_Table.push_back(work);	//�����Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//�|���Z���[�h
	work.push_back(CALC_PRODUCT);	//�|���Z
	CalcType_Table.push_back(work);	//�|���Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//����Z���[�h
	work.push_back(CALC_DEALER);	//����Z
	CalcType_Table.push_back(work);	//����Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//�����Z�A�����Z���[�h
	work.push_back(CALC_SUM);		//�����Z
	work.push_back(CALC_DIFFERENCE);//�����Z
	CalcType_Table.push_back(work);	//�����Z�A�����Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//�|���Z�A����Z���[�h
	work.push_back(CALC_PRODUCT);	//�|���Z
	work.push_back(CALC_DEALER);	//����Z
	CalcType_Table.push_back(work);	//�|���Z�A����Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//�����Z�A�|���Z���[�h
	work.push_back(CALC_SUM);		//�����Z
	work.push_back(CALC_PRODUCT);	//�|���Z
	CalcType_Table.push_back(work);	//�����Z�A�|���Z���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//+/���[�h
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DEALER);	// /
	CalcType_Table.push_back(work);	//+/���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//-*���[�h
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	CalcType_Table.push_back(work);	//-*���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//+-*���[�h
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	CalcType_Table.push_back(work);	//+-*���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//+-/���[�h
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_DEALER);	///
	CalcType_Table.push_back(work);	//+-/���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//all���[�h
	work.push_back(CALC_SUM);		//+
	work.push_back(CALC_DIFFERENCE);//-
	work.push_back(CALC_PRODUCT);	//*
	work.push_back(CALC_DEALER);	///
	CalcType_Table.push_back(work);	//all���[�h�̌v�Z�̎�ނ̑I������ǉ�
	work.clear();					//���g���N���A

	//vector�̉��
	vector<int> v;
	work.swap(v);


}

//��蕶�̃e�L�X�g��ݒ�
void Question::SetText(vector<int> value, vector<int> type, vector<int> order)
{

	//�L���̃e�[�u���쐬
	static vector<string> SymbolTable = { "�{","�|","�~","��" };

	Q_Text = std::to_string(value.front());	//�擪�̒l���蕶�ɐݒ�

	for (int i = 0; i < type.size(); ++i)
	{
		Q_Text += SymbolTable.at(type.at(i));		//�L�����蕶�ɒǉ�
		Q_Text += std::to_string(value.at(i + 1));	//�l���蕶�ɒǉ�(�ŏ��̒l�͊��ɒǉ�����Ă��邽�߁A+1�����v�f�̒l��ݒ�)
	}

	Q_Text += "���H";			//��蕶�ǉ�

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
	int NewInputKey = GetInputKey(keydown);	//�V���ɓ��͂��ꂽ�L�[

	if (INPUT_NUM_0 <= NewInputKey && NewInputKey <= INPUT_NUM_9)	//���l����͂�����
	{
		if ((unsigned int)((InputNumBuf * Weight) + NewInputKey) < INT_MAX)		//int�^�̍ő�l�𒴂��Ȃ����
		{
			InputNumBuf = (InputNumBuf * Weight) + NewInputKey;	//���͒l�Ɍ��̏d�݂�t���Čv�Z
		}

	}
	else	//���l�ȊO����͂�����
	{
		if (NewInputKey == INPUT_ENTER)	//���肳�ꂽ�ꍇ
		{
			InputNumBuf = 0;	//������
			return true;		//���͏I��
		}

		if (NewInputKey == INPUT_BACK)	//�o�b�N�X�y�[�X�������ꂽ��
		{
			InputNumBuf /= Weight;		//�ꕶ��������
		}
	}

	InputNum = InputNumBuf;	//���͂��ꂽ������ݒ�

	return false;
}

//���͂��ꂽ�L�[���擾
int Question::GetInputKey(KeyDown* keydown)
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

	case KEY_INPUT_MINUS:		//�}�C�i�X�L�[
	case KEY_INPUT_SUBTRACT:	//�e���L�[�̃}�C�i�X�L�[

		return INPUT_MINUS;		//�}�C�i�X

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