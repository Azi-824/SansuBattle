/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* KEYDOWN.cpp     																				   */
/* KEYDOWN�N���X																				   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "KEYDOWN.hpp"

//########## �N���X�̒�` ##########

//�C���X�^���X�𐶐�
char KEYDOWN::AllKeyState[256];
int KEYDOWN::InputKeyCode;

//�L�[�̓��͏�Ԃ��X�V����
VOID KEYDOWN::KeyDownUpdate(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
			InputKeyCode = i;	//���͒��̃L�[�R�[�h��ۑ�
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//�L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
BOOL KEYDOWN::IsKeyDown(int keycode)
{
	if (this->AllKeyState[keycode] != 0)
		return TRUE;
	else
		return FALSE;
}

//�L�[���������u�Ԃ���true��Ԃ�
bool KEYDOWN::IsKeyDownOne(int keycode)
{
	if (this->AllKeyState[keycode] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�L�[���͂����邩�擾
bool KEYDOWN::IsKeyInput()
{
	if (CheckHitKeyAll(DX_CHECKINPUT_KEY) == 0)	//�L�[���͂������
	{
		return true;
	}
	else	//�Ȃ����
	{
		return false;
	}
}

//���͒��̃L�[�R�[�h���擾
int KEYDOWN::GetInputKeyCode()
{
	return InputKeyCode;
}

//�R���X�g���N�^
KEYDOWN::KEYDOWN()
{
}

//�f�X�g���N�^
KEYDOWN::~KEYDOWN()
{
}


//########## �O���I�u�W�F�N�g ##########
extern KEYDOWN *keydown;