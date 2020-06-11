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
	delete this->player;		//player�j��
	//delete this->enemy;			//enemy�j��
	delete this->font;			//font�j��
	delete this->gamelimittime;	//gamelimittime�j��
	delete this->effect_atk;	//effect_atk�j��
	delete bgm;					//bgm�j��

	
	//���֌W
	for (int i = 0; i < quesiton.size(); ++i)	//���̎�ޕ�
	{
		delete quesiton.at(i);	//question�j��
	}

	//�G�֌W
	for (int i = 0; i < enemy.size(); ++i)	//�G�̐���
	{
		delete enemy.at(i);	//enemy�̔j��
	}

	//vector�̃�����������s��
	std::vector<Q_BASE*> v;		//���vector���쐬����
	quesiton.swap(v);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	std::vector<ENEMY*> v2;		//���vector���쐬����
	enemy.swap(v2);				//��ƒ��g�����ւ���


	return;

}

//�Q�[�����Ŏg�p����f�[�^�̓ǂݍ��ݏ���
/*
�߂�l�Ftrue�F����
�߂�l�Ffalse�F�G���[�A�����I��
*/
bool GAMEMANEGER::Load()
{

	//�t�H���g�֌W
	this->font = new FONT(FONT_DIR, FONT_FILE_NAME, FONT_NAME);		//�t�H���g���Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->font->GetIsLoad() == false) { return false; }			//�ǂݍ��ݎ��s

	//���Ԋ֌W
	this->gamelimittime = new Time();		//�Q�[���̐������Ԃ��Ǘ�����I�u�W�F�N�g�𐶐�

	//�摜�֌W
	//�w�i�摜
	this->back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//�w�i�摜���Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->back->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	if (this->back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }	//�v���C��ʂ̔w�i�摜��ǉ�
	if (this->back->AddImage(IMG_DIR_BACK, IMG_NAME_DAMMY) == false) { return false; }	//�_�~�[�摜��ǉ�

	//�I�����֌W
	//��Փx�̑I����
	this->level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM, Q_LEVEL_SUM);		//��Փx�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->level_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DIFFERENCE, Q_LEVEL_DIFFERENCE) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRODUCT, Q_LEVEL_PRODUCT) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DEALER, Q_LEVEL_DEALER) == false) { return false; }			//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM_DIFF, Q_LEVEL_SUM_DIFFERENCE) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (this->level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRO_DEA, Q_LEVEL_PRODUCT_DEALER) == false) { return false; }	//�_�~�[�摜�ǉ�

	//�X�e�[�W�̑I����
	this->stage_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY01, STAGE_LEVEL_EASY);		//�X�e�[�W�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->stage_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY02, STAGE_LEVEL_NORMAL) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (this->stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY03, STAGE_LEVEL_HARD) == false) { return false; }	//�_�~�[�摜�ǉ�


	//�v���C���[�֌W
	this->player = new PLAYER(IMG_DIR_PLAYER, IMG_NAME_HP);		//�v���C���[���Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->player->GetIsLoad() == false) { return false; }	//�ǂݍ��ݎ��s

	//�G�֌W
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_FIRST));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(1�̖�)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_SECOND));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(2�̖�)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_THIRD));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(3�̖�)
	for (int i = 0; i < enemy.size(); ++i)	//�G�̐�����
	{
		if (enemy.at(i)->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	}

	//�G�t�F�N�g�֌W
	this->effect_atk = new Effect(EFFECT_DIR, EFFECT_NAME_ATACK, EFFECT_ATACK_ALL_CNT, EFFECT_ATACK_YOKO_CNT, EFFECT_ATACK_TATE_CNT, EFFECT_ATACK_WIDTH, EFFECT_ATACK_HEIGHT, EFFECT_ATACK_SPEED, false);	//�U���G�t�F�N�g���Ǘ�����I�u�W�F�N�g�𐶐�
	if (this->effect_atk->GetIsLoad() == false) { return false; }//�ǂݍ��ݎ��s
	if (effect_atk->AddSe(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_ATK) == false) { return false; }	//���ʉ��ǉ�

	//���y�֌W
	//BGM
	bgm = new MUSIC(MUSIC_DIR_BGM, BGM_NAME_TITLE_BGM);								//BGM���Ǘ�����I�u�W�F�N�g�𐶐�
	if (bgm->GetIsLoad() == false) { return false; }								//�ǂݍ��ݎ��s
	if (bgm->Add(MUSIC_DIR_BGM, BGM_NAME_SELECT_BGM) == false) { return false; }	//�I����ʂ�BGM�ǉ�

	//���֌W
	//�����Z
	quesiton.push_back(new Q_ADD());	//�����Z�̖����Ǘ�����I�u�W�F�N�g�𐶐�

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

	//this->fps->Draw(0, 0);		//FPS�`��

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

//�����ݒ�
void GAMEMANEGER::SetInit()
{
	this->back->SetInit();			//�摜�����ݒ�
	this->level_select->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH);	//��Փx�̑I���������ݒ�
	this->stage_select->SetInit(SELECT_STAGE_DRAW_X, SELECT_STAGE_DRAW_Y, GAME_WIDTH);	//�X�e�[�W�̑I���������ݒ�
	this->player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//�v���C���[�����ݒ�
	this->effect_atk->SetInit();														//�G�t�F�N�g�����ݒ�

	for (int i = 0; i < enemy.size(); ++i)
	{
		enemy.at(i)->SetInit(ENEMY_DRAW_X, ENEMY_DRAW_Y);								//�G�̏����ݒ�
	}

	//���y�֌W
	bgm->ChengeVolume(30, (int)BGM_TYPE_TITLE);	//�^�C�g��BGM�̉��ʂ�30%�ɂ���
	bgm->ChengeVolume(30, (int)BGM_TYPE_SELECT);//�I����ʂ�BGM�̉��ʂ�30%�ɂ���
	bgm->ChengePlayType(DX_PLAYTYPE_LOOP);		//BGM�̍Đ����@�����[�v�Đ��ɕύX

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

			this->SetInit();			//�����ݒ�

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

	bgm->Play((int)BGM_TYPE_TITLE);		//BGM���Đ�

	this->level_select->Init();	//��Փx�̑I����������
	this->stage_select->Init();	//�X�e�[�W�̑I����������

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		bgm->Stop();								//�Đ����̉��y���~�߂�
		this->NowScene = (int)SCENE_CHOISELEVEL;	//��Փx�I����ʂ�
	}

	return;
}

//�^�C�g����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Title()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	return;
}

//��Փx�I����ʂ̏���
void GAMEMANEGER::Scene_ChoiseLevel()
{

	bgm->Play((int)BGM_TYPE_SELECT);	//�I����ʂ�BGM���Đ�

	this->level_select->Operation(keydown);			//�I�����L�[����

	if (this->level_select->GetIsChoise())			//�I��������
	{
		Q_BASE::SelectLevel = level_select->GetChoiseSelectCode();	//�I���������x����ݒ�
		this->NowScene = (int)SCENE_CHOISESTAGE;					//�X�e�[�W�I����ʂ�
	}

	return;
}

//��Փx�I����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	this->level_select->Draw();	//��Փx�̑I�����`��

	return;
}

//�X�e�[�W�I����ʂ̏���
void GAMEMANEGER::Scene_ChoiseStage()
{

	stage_select->Operation(keydown);		//�I�����L�[����

	if (stage_select->GetIsChoise())		//�I��������
	{
		bgm->Stop();						//�Đ�����BGM���~�߂�
		for (int i = 0; i < enemy.size(); ++i)	//�G�̐������[�v
		{
			enemy.at(i)->Init();			//�G������
		}
		gamelimittime->SetTime();			//�������Ԃ̌v���J�n
		NowScene = (int)SCENE_PLAY;			//�v���C��ʂ�
	}

	return;
}

//�X�e�[�W�I����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_ChoiseStage()
{

	this->stage_select->Draw();		//�X�e�[�W�I�����`��

	return;
}

//�v���C��ʂ̏���
void GAMEMANEGER::Scene_Play()
{

	this->back->ChengeImage((int)PLAY_BACK);	//�w�i�摜��ύX

	this->gamelimittime->UpdateLimitTime(GAME_LIMIT_TIME);	//�������Ԃ̍X�V

	if (!Q_BASE::GetIsCreate())	//�����쐬���Ă��Ȃ����
	{
		quesiton.at(Q_BASE::SelectLevel)->CreateQuestion();	//�����쐬
	}

	if (Q_BASE::CheckInputKey(this->keydown))	//�L�[���͂�����������
	{
		if (Q_BASE::JudgAnser())				//�v���C���[�̉񓚂�������������
		{
			effect_atk->SetIsDraw(true,(int)EFFECT_ATACK);			//�A�j���[�V�����̕`����J�n����
		}

	}

	if (effect_atk->GetIsDrawEnd())							//�A�j���[�V�����`�悪�I�������
	{
		effect_atk->SetIsDraw(false, (int)EFFECT_ATACK);	//�A�j���[�V������`�悵�Ȃ�
		effect_atk->ResetIsAnime((int)EFFECT_ATACK);		//�A�j���[�V������Ԃ����Z�b�g
		enemy.at(ENEMY::GetNowEnemyNum())->SendDamege();	//�G�Ƀ_���[�W��^����
	}

	if (enemy.at(ENEMY::GetNowEnemyNum())->GetHp() <= 0)		//�G��HP��0�ɂȂ�����
	{
		enemy.at(ENEMY::GetNowEnemyNum())->SetIsArive(false);	//�G���S
		ENEMY::NextEnemy();	//���̓G��
	}
	
	if (ENEMY::GetNowEnemyNum() >= enemy.size())	//�G�̐����A�ő吔�𒴂�����
	{
		NowScene = (int)SCENE_DRAWSCORE;		//�X�R�A�\����ʂ�
	}

	return;
}

//�v���C��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Play()
{

	this->back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	this->player->Draw();				//�v���C���[HP�`��

	if (ENEMY::GetNowEnemyNum() < enemy.size())	//���݂̓G���A�G�̍ő吔�ʓ���������
	{
		enemy.at(ENEMY::GetNowEnemyNum())->DrawCenter();	//�G�L�����`��
	}

	Q_BASE::DrawQuestion();				//��蕶�`��
	Q_BASE::DrawInputNum();				//���͒��̐�����`��

	this->gamelimittime->DrawLimitTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y, GAME_LIMIT_TIME);			//�������Ԃ̕`��

	this->effect_atk->DrawCenter((int)EFFECT_ATACK);	//�U���G�t�F�N�g�`��

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
