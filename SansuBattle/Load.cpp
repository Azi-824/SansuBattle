//Load.cpp
//���[�h��ʂ̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� #################
#include "Load.hpp"

//############## �N���X��` ################

bool Load::LoadEnd = false;	//�ǂݍ��݂��I�������

//�R���X�g���N�^
Load::Load()
{
	//�����o�[������
	IsGameStart = false;	//�Q�[���X�^�[�g�ł��邩

	IsLoad = true;

}

//�f�X�g���N�^
Load::~Load(){}

//�����ݒ�
void Load::SetInit(){}

//�ǂݍ��݉�ʂ̏���
void Load::Run()
{
	if (IsGameStart)	//�Q�[���X�^�[�g�ł���Ȃ�
	{
		if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
		{
			NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
		}

	}

	if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
	{

		SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�
		LoadEnd = true;				//�ǂݍ��ݏI��
		IsGameStart = true;			//�Q�[���X�^�[�g�ł���

		//�������b�Z�[�W��`��
		//DrawStringToHandle(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_DISCRIPTION, COLOR_WHITE, Font::GetNowHandle());
		DrawString(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_DISCRIPTION, COLOR_WHITE);
	}
	else		//�ǂݍ��ݒ���
	{
		//�ǂݍ��݃��b�Z�[�W��`��
		//DrawStringToHandle(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_LOAD_MSG, COLOR_WHITE, Font::GetNowHandle());
		DrawString(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_LOAD_MSG, COLOR_WHITE);

	}


}

//�ǂݍ��݂��I��������擾
bool Load::IsLoadEnd()
{
	return LoadEnd;
}
