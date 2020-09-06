//End.cpp
//�G���h��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "End.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
End::End()
{
	
}

//�f�X�g���N�^
End::~End()
{

}

//�����ݒ�
void End::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	for (auto b : bgm) { b->SetInit(DX_PLAYTYPE_LOOP, VOL_DEF); }	//BGM�����ݒ�
}


//�G���h��ʂ̏���
void End::Run()
{

	bgm.front()->Play();		//BGM�𗬂�

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm.front()->Stop();	//BGM���~�߂�
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}

	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

}