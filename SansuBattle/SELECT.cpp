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
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_IMG_NAME));//+
	mode_img.push_back(new Image(BT_IMG_DIR, BT_DIF_IMG_NAME));//-
	mode_img.push_back(new Image(BT_IMG_DIR, BT_PRO_IMG_NAME));//*
	mode_img.push_back(new Image(BT_IMG_DIR, BT_DEA_IMG_NAME));// /
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_DIF_IMG_NAME));//+-
	mode_img.push_back(new Image(BT_IMG_DIR, BT_PRO_DEA_IMG_NAME));//*/
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_PRO_IMG_NAME));//+*
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_DEA_IMG_NAME));//+/
	mode_img.push_back(new Image(BT_IMG_DIR, BT_DIF_PRO_IMG_NAME));//-*
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_DIF_PRO_IMG_NAME));//+-*
	mode_img.push_back(new Image(BT_IMG_DIR, BT_SUM_DIF_DEA_IMG_NAME));//+-/
	mode_img.push_back(new Image(BT_IMG_DIR, BT_ALL_IMG_NAME));//all

	for (auto i : mode_img) { 
		if (!i->GetIsLoad())
		{
			IsLoad = false;
			return;
		}
	}	//�ǂݍ��ݐ���������

	//���x��
	level_img.push_back(new Image(BT_IMG_DIR, BT_EASY_IMG_NAME));//�ȒP
	level_img.push_back(new Image(BT_IMG_DIR, BT_NORMAL_IMG_NAME));//����
	level_img.push_back(new Image(BT_IMG_DIR, BT_HARD_IMG_NAME));//���

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

	next = new Button(new Image(BT_IMG_DIR, BT_NEXT_IMG_NAME));	//���̃y�[�W�ֈړ�����{�^��
	prev = new Button(new Image(BT_IMG_DIR, BT_PREV_IMG_NAME));	//�O�̃y�[�W�ֈړ�����{�^��


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

	delete next;	//next�{�^���j��
	delete prev;	//prev�{�^���j��


}

//�����ݒ�
void Select::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�

	//**************** �{�^�� ******************
	for (auto b : mode) { b->SetInit(20, 20); }
	for (auto b : level) { b->SetInit(20, 20); }
	next->SetInit();	//�����ݒ�
	next->SetRect(BT_NEXT_DRAW_X, GAME_HEIGHT / 2 - next->GetHeight() / 2);	//�ʒu�ݒ�
	prev->SetInit();	//�����ݒ�
	prev->SetRect(BT_PREV_DRAW_X, GAME_HEIGHT / 2 - next->GetHeight() / 2);	//�ʒu�ݒ�

	//�{�^�����O���[�v�ɓo�^
	mode_group = new Group(mode, BT_MODE_DRAW_X, BT_MODE_DRAW_Y, BT_MODE_INTERVAL_SIDE, BT_MODE_INTERVAL_VERTICAL);
	level_group = new Group(level, BT_LEVEL_DRAW_X, BT_LEVEL_DRAW_Y, BT_LEVEL_INTERVAL_SIDE, BT_LEVEL_INTERVAL_VERTICAL);

}


//�I����ʂ̏���
void Select::Run()
{

	bgm->Play();	//BGM�𗬂�
	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

	if (mode_group->GetIsSelect())	//���[�h�̑I����������
	{
		level_group->Draw();	//���x���`��
		level_group->Clik();	//���x���̃N���b�N����
	}
	else		//���[�h�̑I�������Ă��Ȃ����
	{
		mode_group->Draw();	//���[�h�`��
		mode_group->Clik();	//���[�h�N���b�N����
		//�O��̃y�[�W�ֈړ����邽�߂̃{�^��
		if (mode_group->CheckIsNextPage())	//���̃y�[�W������Ƃ�
		{
			next->Draw();	//���̃y�[�W�ֈړ����邽�߂̃{�^����`��
			if (next->OnClick())	//�N���b�N���ꂽ��
			{
				//�C�x���g��o�^���A���s
				next->Event([this]
					{
						mode_group->NextPage();	//���̃y�[�W��
					});
			}
		}
		if (mode_group->CheckIsPrevPage())	//�O�̃y�[�W������Ƃ�
		{
			prev->Draw();	//�O�̃y�[�W�ֈړ����邽�߂̃{�^����`��
			if (prev->OnClick())	//�N���b�N���ꂽ��
			{
				//�C�x���g��o�^���A���s
				prev->Event([this]
					{
						mode_group->PrevPage();	//�O�̃y�[�W��
					});
			}
		}
	}



	if (level_group->GetIsSelect())//���x���̑I����������
	{
		GameMode = mode_group->GetSelctNum();	//�I���������[�h��ݒ�
		GameLevel = level_group->GetSelctNum();	//�I���������x����ݒ�
		bgm->Stop();							//BGM���~�߂�
		NowScene = SCENE_PLAY;					//�v���C��ʂ�
	}

}