//Load.cpp
//���[�h��ʂ̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� #################
#include "Load.hpp"

//############## �N���X��` ################

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

		IsGameStart = true;		//�Q�[���X�^�[�g�ł���
	}

	DrawStringToHandle(TEXT_DISCRIPTION_X, TEXT_DISCRIPTION_Y, TEXT_DISCRIPTION, GetColor(255, 255, 255), Font::GetNowHandle());

}
