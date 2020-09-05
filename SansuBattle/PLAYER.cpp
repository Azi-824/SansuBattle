//Player.cpp
//�v���C���[���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Player.hpp"

//################### �N���X��` ##################

//�R���X�g���N�^
Player::Player()
{
	hp_img->Load(IMG_DIR_PLAYER, IMG_NAME_HP);	//HP�摜����
	HP_X = 0;		//HP�`��X�ʒu
	HP_Y = 0;		//HP�`��Y�ʒu
	InputNum = 0;	//���͂��ꂽ�l
	keydown = new KeyDown();	//�L�[���͗p
	reverse = false;			//���]�`�悷�邩
}

//�f�X�g���N�^
Player::~Player()
{
	delete keydown;	//keydown�j��
}

//�����ݒ�
bool Player::SetInit()
{
	if (!hp_img->GetIsLoad()) { return false; }	//�ǂݍ��ݎ��s
	hp_img->SetInit();	//�摜�����ݒ�
	HP_X = GAME_WIDTH - hp_img->GetWidth();	//HP�`��X�ʒu
	HP_Y = PLAYER_HP_DRAW_Y;				//HP�`��Y�ʒu
	reverse = true;	//���]�`��
	return true;	//�ǂݍ��ݐ���
}

//*********************** �L�[���͊֌W ***********************************
//���͒��̐�����`�悷��
void Player::DrawInputNum()
{

	string inp = std::to_string(InputNum);	//���͂��ꂽ�����𕶎���ɕϊ�

	int Strlen = strlen(inp.c_str());													//������̒������擾
	int Width = GetDrawStringWidthToHandle(inp.c_str(), Strlen, Font::GetNowHandle());	//�����擾
	int Height = GetFontSizeToHandle(Font::GetNowHandle());								//�����擾

	DrawFormatStringToHandle((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), COLOR_WHITE, Font::GetNowHandle(), "%s", inp.c_str());	//���͒��̐�����`��

}

//�L�[���͒����m�F
//�߂�l�Fbool�Ftrue ���͏I���Ffalse ���͒�
bool Player::CheckInputKey()
{
	keydown->KeyDownUpdate();			//�L�[���͍X�V
	int InputNumBuf = InputNum;			//���݂̓��͂���Ă���l���擾
	static int Weight = 10;				//���̏d��
	int NewInputKey = GetInputKey();	//�V���ɓ��͂��ꂽ�L�[

	if (INPUT_NUM_0 <= NewInputKey && NewInputKey <= INPUT_NUM_9)	//���l����͂�����
	{
		unsigned int check = 0;	//�m�F�p

		//�}�C�i�X�̒l�̏ꍇ�A���̒l�ɕϊ�����
		InputNumBuf < 0 ? check = InputNumBuf * -1 : check = InputNumBuf;

		check *= Weight;
		check += NewInputKey;

		if (check < INT_MAX)		//int�^�͈͓̔��Ȃ�
		{
			//���͒l�Ɍ��̏d�݂�t���Čv�Z
			//���̒l�̎��́A�}�C�i�X�A���̒l�̎��́A�v���X�ŁA�v�Z����
			InputNumBuf < 0 ? InputNumBuf = (InputNumBuf * Weight) - NewInputKey : InputNumBuf = (InputNumBuf * Weight) + NewInputKey;

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

		if (NewInputKey == INPUT_MINUS)	//�}�C�i�X�L�[�������ꂽ��
		{
			InputNumBuf *= -1;			//�}�C�i�X�̒l�ɕϊ�
		}
	}

	//InputNum = std::to_string(InputNumBuf);	//���͂��ꂽ������ݒ�
	InputNum = InputNumBuf;		//���͂��ꂽ������ݒ�

	return false;
}

//���̓��Z�b�g
void Player::InpReset()
{
	InputNum = 0;	//���͓��e���Z�b�g
}

//���͂��ꂽ�L�[���擾
int Player::GetInputKey()
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

//���͂��ꂽ�������擾
int Player::GetAns()
{
	return InputNum;
}
