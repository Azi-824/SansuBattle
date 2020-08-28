//End.cpp
//�G���h��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Ranking.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
Ranking::Ranking()
{
	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_RANKING)) { IsLoad = false; return; }	//�w�i�摜�ǂݍ���

	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_RANKING)) { IsLoad = false; return; }	//BGM�ǂݍ���
	IsLoad = true;

}

//�f�X�g���N�^
Ranking::~Ranking()
{

}

//�����ݒ�
void Ranking::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

}


//�G���h��ʂ̏���
void Ranking::Run()
{

	bgm->Play();	//BGM�𗬂�
	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}

	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

}