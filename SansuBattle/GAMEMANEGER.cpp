//GAMEMANEGER.cpp
//�Q�[���̃V�X�e�����Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ################
#include "GAMEMANEGER.hpp"

//############### �N���X��` ################

//�R���X�g���N�^
GAMEMANEGER::GAMEMANEGER()
{
	//�I�u�W�F�N�g�̐���
	this->fps = new FPS(GAME_FPS_SPEED);	//FPS�N���X�̃I�u�W�F�N�g�𐶐�
	this->keydown = new KEYDOWN();			//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�

	//�����o�[�ϐ�������
	this->NowScene = (int)SCENE_LOAD;		//�ŏ��̃V�[���́A���[�h���
	this->IsLoad = false;					//�ǂݍ��݁A������

	return;

}

//�f�X�g���N�^
GAMEMANEGER::~GAMEMANEGER()
{
	//�I�u�W�F�N�g�̔j��
	delete this->fps;			//fps�j��
	delete this->keydown;		//keydown�j��
	delete this->back;			//back�j��
	delete this->level_select;	//level_select�j��
	delete this->stage_select;	//stage_select�j��

	return;

}

//�Q�[�����Ŏg�p����f�[�^�̓ǂݍ��ݏ���
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GAMEMANEGER::Load()
{
	//�摜�֌W
	this->back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//�w�i�摜���Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->back->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	if (this->back->AddImage(IMG_DIR_BACK, IMG_NAME_DAMMY) == false) { return false; }	//�_�~�[�摜��ǉ�

	//�I�����֌W
	//��Փx�̑I����
	this->level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY1, CODE_LEVEL_SUM);		//��Փx�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->level_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY2, CODE_LEVEL_DIFFERENCE) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY3, CODE_LEVEL_PRODUCT) == false) { return false; }			//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY4, CODE_LEVEL_DEALER) == false) { return false; }			//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY5, CODE_LEVEL_SUM_DEFFERENCE) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DAMMY6, CODE_LEVEL_PRODUCT_DEALER) == false) { return false; }	//�_�~�[�摜�ǉ�

	//�X�e�[�W�̑I����
	this->stage_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY01, CODE_STAGE_EASY);		//�X�e�[�W�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->stage_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY02, CODE_STAGE_NORMAL) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY03, CODE_STAGE_HARD) == false) { return false; }	//�_�~�[�摜�ǉ�


	return true;	//�ǂݍ��ݐ���
}

//�Q�[���̃��C�����[�v
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GAMEMANEGER::GameMainLoop()
{
	if (ProcessMessage() != 0) { return false; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return false; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	this->keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

	this->fps->Update();		//FPS�̏���[�X�V]

	//�����������Q�[���̃V�[���������灥��������

	this->ProcesScene();		//�e�V�[���̏���

	//�����������Q�[���̃V�[�������܂Ł���������

	this->fps->Draw(0, 0);		//FPS�`��

	ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	this->fps->Wait();			//FPS�̏���[�҂�]

	return true;				//����

}

//�e�V�[���̏���
void GAMEMANEGER::ProcesScene()
{
	switch (this->NowScene)		//���݂̃V�[���̕`�揈�������s
	{

	case (int)SCENE_LOAD:	//���[�h��ʂ̂Ƃ�

		this->Scene_Load();			//���[�h��ʂ̏���

		this->Draw_Scene_Load();	//���[�h��ʂ̕`�揈��

		break;				//���[�h��ʂ̂Ƃ������܂�

	case (int)SCENE_TITLE:	//�^�C�g����ʂ̂Ƃ�

		this->Scene_Title();		//����

		this->Draw_Scene_Title();	//�`��

		break;				//�^�C�g����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISELEVEL:	//��Փx�I����ʂ̂Ƃ�

		this->Scene_ChoiseLevel();		//����

		this->Draw_Scene_ChoiseLevel();	//�`��

		break;				//��Փx�I����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISESTAGE:	//�X�e�[�W�I����ʂ̂Ƃ�

		this->Scene_ChoiseStage();		//����

		this->Draw_Scene_ChoiseStage();	//�`��

		break;				//�X�e�[�W�I����ʂ̂Ƃ������܂�

	case (int)SCENE_PLAY:	//�v���C��ʂ̂Ƃ�

		this->Scene_Play();			//����

		this->Draw_Scene_Play();	//�`��

		break;				//�v���C��ʂ̂Ƃ������܂�

	case (int)SCENE_DRAWSCORE:	//�X�R�A�\����ʂ̂Ƃ�

		this->Scene_DrawScore();		//����

		this->Draw_SceneDrawScore();	//�`��

		break;				//�X�R�A�\����ʂ̂Ƃ������܂�

	case (int)SCENE_END:	//�G���h��ʂ̂Ƃ�

		this->Scene_End();		//����

		this->Draw_Scene_End();	//�`��

		break;				//�G���h��ʂ̂Ƃ������܂�

	default:
		break;
	}

	return;	

}

//***************************** �V�[�����̏��� ********************************
//���[�h��ʂ̏���
void GAMEMANEGER::Scene_Load()
{
	if (this->IsLoad)	//�ǂݍ��݂��������Ă�����
	{
		if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
		{
			this->NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
		}
	}
	else		//�ǂݍ��݂��������Ă��Ȃ�������
	{
		if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
		{

			SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�

			this->back->SetInit();			//�摜�����ݒ�
			this->level_select->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH);	//��Փx�̑I���������ݒ�
			this->stage_select->SetInit(SELECT_STAGE_DRAW_X, SELECT_STAGE_DRAW_Y, GAME_WIDTH);	//�X�e�[�W�̑I���������ݒ�

			this->IsLoad = true;		//�ǂݍ��݊���
		}

	}


	return;		
}

//���[�h��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Load()
{

	if (IsLoad)	//�ǂݍ��݂�����������
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, COLOR_WHITE);	//�v�b�V���A�̃e�L�X�g��`��
	}
	else		//�������Ă��Ȃ����
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, COLOR_WHITE);	//�ǂݍ��ݒ��̃e�L�X�g��`��
	}

	return;
}

//�^�C�g����ʂ̏���
void GAMEMANEGER::Scene_Title()
{

	this->back->ChengeImage((int)TITLE_BACK);	//�w�i�摜��ύX

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		this->NowScene = (int)SCENE_CHOISELEVEL;	//��Փx�I����ʂ�
	}

	return;
}

//�^�C�g����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Title()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

//��Փx�I����ʂ̏���
void GAMEMANEGER::Scene_ChoiseLevel()
{

	this->level_select->Operation(keydown);			//�I�����L�[����

	if (this->level_select->GetIsChoise())			//�I��������
	{
		this->NowScene = (int)SCENE_CHOISESTAGE;	//�X�e�[�W�I����ʂ�
	}

	return;
}

//��Փx�I����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	this->level_select->Draw();	//��Փx�̑I�����`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISELEVEL_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

//�X�e�[�W�I����ʂ̏���
void GAMEMANEGER::Scene_ChoiseStage()
{

	this->stage_select->Operation(keydown);		//�I�����L�[����

	if (this->stage_select->GetIsChoise())		//�I��������
	{
		this->NowScene = (int)SCENE_PLAY;		//�v���C��ʂ�
	}

	return;
}

//�X�e�[�W�I����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_ChoiseStage()
{

	this->stage_select->Draw();		//�X�e�[�W�I�����`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, CHOISESTAGE_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

//�v���C��ʂ̏���
void GAMEMANEGER::Scene_Play()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		this->NowScene = (int)SCENE_DRAWSCORE;	//�X�R�A�\����ʂ�
	}

	return;
}

//�v���C��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Play()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

//�X�R�A�\����ʂ̏���
void GAMEMANEGER::Scene_DrawScore()
{

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		this->NowScene = (int)SCENE_END;	//�G���h��ʂ�
	}

	return;
}

//�X�R�A�\����ʂ̕`�揈��
void GAMEMANEGER::Draw_SceneDrawScore()
{

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, DRAWSCORE_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}


//�G���h��ʂ̏���
void GAMEMANEGER::Scene_End()
{

	this->back->ChengeImage((int)DAMMY_BACK);	//�w�i�摜��ύX

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		this->NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
	}

	return;
}

//�G���h��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_End()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}

