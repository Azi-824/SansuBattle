//Select.cpp
//�I���̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Select.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
Select::Select()
{
	//�摜�֌W
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_SELECT)) { IsLoad = false; return; }	//�w�i�摜�ǂݍ���

	//BGM
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_SELECT)) { IsLoad = false; return; }	//BGM�ǂݍ���

	//**************************** �{�^�� ***************************
	//�{�^���̉摜��ǂݍ���
	//���[�h
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_IMG_NAME));
	for (auto i : mode_img) { 
		if (!i->GetIsLoad())
		{
			IsLoad = false;
			return;
		}
	}	//�ǂݍ��ݐ���������

	//���x��
	mode_img.push_back(new Image(BT_IMG_DIR, BT_EASY_IMG_NAME));
	for (auto i : level_img) {
		if (!i->GetIsLoad())
		{
			IsLoad = false;
			return;
		}
	}	//�ǂݍ��ݐ���������

	//�{�^���쐬
	for (auto i : mode_img){ mode.push_back(new Button(i)); }		//���[�h
	for (auto i : level_img) { level.push_back(new Button(i)); }	//���x��

}

//�f�X�g���N�^
Select::~Select()
{
	
	for (auto b : mode) { delete b; }
	//vector�̊J��
	vector<Button*> v;
	v.swap(mode);

	for (auto b : level) { delete b; }
	//vector�̊J��
	vector<Button*> v2;
	v2.swap(level);

	//�{�^���̉摜�́A�{�^���̔j���ƈꏏ�ɔj������邽��
	//vector�̊J���̂ݍs��
	vector<Image*> v3;
	v3.swap(level_img);
	vector<Image*> v4;
	v4.swap(level_img);


}

//�����ݒ�
void Select::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

	//**************** �{�^�� ******************
	for (auto b : mode) { b->SetInit(20, 20); }
	for (auto b : level) { b->SetInit(20, 20); }
}


//�I����ʂ̏���
void Select::Run()
{

	bgm->Play();	//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

	for (auto b : mode)
	{
		b->Draw();
	}

	for (auto b : level)
	{
		b->Draw();
	}

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_PLAY;	//�v���C��ʂ�
	}


}