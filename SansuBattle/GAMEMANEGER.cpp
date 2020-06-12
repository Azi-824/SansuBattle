//GAMEMANEGER.cpp
//�Q�[���̃V�X�e�����Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� ################
#include "GAMEMANEGER.hpp"

//############### �N���X��` ################

//�R���X�g���N�^
GAMEMANEGER::GAMEMANEGER()
{
	//�I�u�W�F�N�g�̐���
	fps = new FPS(GAME_FPS_SPEED);	//FPS�N���X�̃I�u�W�F�N�g�𐶐�
	keydown = new KEYDOWN();			//KEYDOWN�N���X�̃I�u�W�F�N�g�𐶐�

	//�����o�[�ϐ�������
	NowScene = (int)SCENE_LOAD;		//�ŏ��̃V�[���́A���[�h���
	IsLoad = false;					//�ǂݍ��݁A������
	GameLevel = -1;					//�Q�[���̃��x��������
	return;

}

//�f�X�g���N�^
GAMEMANEGER::~GAMEMANEGER()
{
	//�I�u�W�F�N�g�̔j��
	delete fps;				//fps�j��
	delete keydown;			//keydown�j��
	delete back;			//back�j��
	delete level_select;	//level_select�j��
	delete stage_select;	//stage_select�j��
	delete player;			//player�j��
	delete font;			//font�j��
	delete gamelimittime;	//gamelimittime�j��
	delete effect_atk;		//effect_atk�j��
	delete bgm;				//bgm�j��

	
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

	//�X�R�A�֌W
	for (int i = 0; i < score.size(); ++i)	//�X�R�A�̎�ޕ�
	{
		delete score.at(i);	//score�j��
	}

	//vector�̃�����������s��
	std::vector<Q_BASE*> v;		//���vector���쐬����
	quesiton.swap(v);			//��ƒ��g�����ւ���

	//vector�̃�����������s��
	std::vector<ENEMY*> v2;		//���vector���쐬����
	enemy.swap(v2);				//��ƒ��g�����ւ���

	//vector�̃�����������s��
	std::vector<ScoreBase*> v3;		//���vector���쐬����
	score.swap(v3);					//��ƒ��g�����ւ���

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
	font = new FONT(FONT_DIR, FONT_FILE_NAME, FONT_NAME);		//�t�H���g���Ǘ�����I�u�W�F�N�g�𐶐�
	if (font->GetIsLoad() == false) { return false; }			//�ǂݍ��ݎ��s

	//���Ԋ֌W
	gamelimittime = new Time();		//�Q�[���̐������Ԃ��Ǘ�����I�u�W�F�N�g�𐶐�

	//�摜�֌W
	//�w�i�摜
	back = new IMAGE(IMG_DIR_BACK, IMG_NAME_TITLE);		//�w�i�摜���Ǘ�����I�u�W�F�N�g�𐶐�
	if (back->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_PLAY) == false) { return false; }	//�v���C��ʂ̔w�i�摜��ǉ�
	if (back->AddImage(IMG_DIR_BACK, IMG_NAME_DAMMY) == false) { return false; }	//�_�~�[�摜��ǉ�

	//�I�����֌W
	//��Փx�̑I����
	level_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM, Q_LEVEL_SUM);		//��Փx�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (level_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DIFFERENCE, Q_LEVEL_DIFFERENCE) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRODUCT, Q_LEVEL_PRODUCT) == false) { return false; }		//�_�~�[�摜�ǉ�
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_DEALER, Q_LEVEL_DEALER) == false) { return false; }			//�_�~�[�摜�ǉ�
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_SUM_DIFF, Q_LEVEL_SUM_DIFFERENCE) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (level_select->Add(SELECT_IMG_DIR, IMG_NAME_SELECT_PRO_DEA, Q_LEVEL_PRODUCT_DEALER) == false) { return false; }	//�_�~�[�摜�ǉ�

	//�X�e�[�W�̑I����
	stage_select = new SELECT(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY01, STAGE_LEVEL_EASY);		//�X�e�[�W�̑I�������Ǘ�����I�u�W�F�N�g�𐶐�
	if (stage_select->GetIsCreateSelect() == false) { return false; }			//�ǂݍ��ݎ��s
	//�I�����̒ǉ�
	if (stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY02, STAGE_LEVEL_NORMAL) == false) { return false; }	//�_�~�[�摜�ǉ�
	if (stage_select->Add(SELECT_IMG_DIR, IMG_NAME_STAGE_DAMMY03, STAGE_LEVEL_HARD) == false) { return false; }	//�_�~�[�摜�ǉ�


	//�v���C���[�֌W
	player = new PLAYER();		//�v���C���[���Ǘ�����I�u�W�F�N�g�𐶐�

	//�G�֌W
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_FIRST));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(1�̖�)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_SECOND));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(2�̖�)
	enemy.push_back(new ENEMY(IMG_DIR_ENEMY, IMG_NAME_ENEMY_THIRD));	//�G���Ǘ�����I�u�W�F�N�g�𐶐�(3�̖�)
	for (int i = 0; i < enemy.size(); ++i)	//�G�̐�����
	{
		if (enemy.at(i)->GetIsLoad() == false) { return false; }		//�ǂݍ��ݎ��s
	}

	//�G�t�F�N�g�֌W
	effect_atk = new Effect(EFFECT_DIR, EFFECT_NAME_ATACK, EFFECT_ATACK_ALL_CNT, EFFECT_ATACK_YOKO_CNT, EFFECT_ATACK_TATE_CNT, EFFECT_ATACK_WIDTH, EFFECT_ATACK_HEIGHT, EFFECT_ATACK_SPEED, false);	//�U���G�t�F�N�g���Ǘ�����I�u�W�F�N�g�𐶐�
	if (effect_atk->GetIsLoad() == false) { return false; }//�ǂݍ��ݎ��s
	if (effect_atk->AddSe(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_ATK) == false) { return false; }	//���ʉ��ǉ�

	//���y�֌W
	//BGM
	bgm = new MUSIC(MUSIC_DIR_BGM, BGM_NAME_TITLE_BGM);								//BGM���Ǘ�����I�u�W�F�N�g�𐶐�
	if (bgm->GetIsLoad() == false) { return false; }								//�ǂݍ��ݎ��s
	if (bgm->Add(MUSIC_DIR_BGM, BGM_NAME_SELECT_BGM) == false) { return false; }	//�I����ʂ�BGM�ǉ�

	//���֌W
	//�����Z
	quesiton.push_back(new Q_ADD());	//�����Z�̖����Ǘ�����I�u�W�F�N�g�𐶐�

	//�X�R�A�֌W
	//�����Z
	score.push_back(new ScoreAdd());	//�����Z�̃X�R�A���Ǘ�����I�u�W�F�N�g�𐶐�

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

	keydown->KeyDownUpdate();	//�L�[�̓��͏�Ԃ��X�V����

	fps->Update();		//FPS�̏���[�X�V]

	//�����������Q�[���̃V�[���������灥��������

	ProcesScene();		//�e�V�[���̏���

	//�����������Q�[���̃V�[�������܂Ł���������

	//this->fps->Draw(0, 0);		//FPS�`��

	ScreenFlip();				//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	fps->Wait();			//FPS�̏���[�҂�]

	return true;				//����

}

//�e�V�[���̏���
void GAMEMANEGER::ProcesScene()
{
	switch (NowScene)		//���݂̃V�[���̕`�揈�������s
	{

	case (int)SCENE_LOAD:	//���[�h��ʂ̂Ƃ�

		Scene_Load();			//���[�h��ʂ̏���

		Draw_Scene_Load();	//���[�h��ʂ̕`�揈��

		break;				//���[�h��ʂ̂Ƃ������܂�

	case (int)SCENE_TITLE:	//�^�C�g����ʂ̂Ƃ�

		Scene_Title();		//����

		Draw_Scene_Title();	//�`��

		break;				//�^�C�g����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISELEVEL:	//��Փx�I����ʂ̂Ƃ�

		Scene_ChoiseLevel();		//����

		Draw_Scene_ChoiseLevel();	//�`��

		break;				//��Փx�I����ʂ̂Ƃ������܂�

	case (int)SCENE_CHOISESTAGE:	//�X�e�[�W�I����ʂ̂Ƃ�

		Scene_ChoiseStage();		//����

		Draw_Scene_ChoiseStage();	//�`��

		break;				//�X�e�[�W�I����ʂ̂Ƃ������܂�

	case (int)SCENE_PLAY:	//�v���C��ʂ̂Ƃ�

		Scene_Play();			//����

		Draw_Scene_Play();	//�`��

		break;				//�v���C��ʂ̂Ƃ������܂�

	case (int)SCENE_DRAWSCORE:	//�X�R�A�\����ʂ̂Ƃ�

		Scene_DrawScore();		//����

		Draw_SceneDrawScore();	//�`��

		break;				//�X�R�A�\����ʂ̂Ƃ������܂�

	case (int)SCENE_END:	//�G���h��ʂ̂Ƃ�

		Scene_End();		//����

		Draw_Scene_End();	//�`��

		break;				//�G���h��ʂ̂Ƃ������܂�

	default:
		break;
	}

	return;	

}

//�����ݒ�
void GAMEMANEGER::SetInit()
{
	back->SetInit();			//�摜�����ݒ�
	level_select->SetInit(SELECT_LEVEL_DRAW_X, SELECT_LEVEL_DRAW_Y, GAME_WIDTH);	//��Փx�̑I���������ݒ�
	stage_select->SetInit(SELECT_STAGE_DRAW_X, SELECT_STAGE_DRAW_Y, GAME_WIDTH);	//�X�e�[�W�̑I���������ݒ�
	player->SetInit(PLAYER_HP_DRAW_X, PLAYER_HP_DRAW_Y);							//�v���C���[�����ݒ�
	effect_atk->SetInit();															//�G�t�F�N�g�����ݒ�

	for (int i = 0; i < enemy.size(); ++i)
	{
		enemy.at(i)->SetInit();								//�G�̏����ݒ�
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
	if (IsLoad)	//�ǂݍ��݂��������Ă�����
	{
		if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
		{
			NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
		}
	}
	else		//�ǂݍ��݂��������Ă��Ȃ�������
	{
		if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
		{

			SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�

			SetInit();			//�����ݒ�

			IsLoad = true;		//�ǂݍ��݊���
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

	back->ChengeImage((int)TITLE_BACK);	//�w�i�摜��ύX

	bgm->Play((int)BGM_TYPE_TITLE);		//BGM���Đ�

	level_select->Init();	//��Փx�̑I����������
	stage_select->Init();	//�X�e�[�W�̑I����������

	if (this->keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		bgm->Stop();								//�Đ����̉��y���~�߂�
		NowScene = (int)SCENE_CHOISELEVEL;	//��Փx�I����ʂ�
	}

	return;
}

//�^�C�g����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Title()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	return;
}

//��Փx�I����ʂ̏���
void GAMEMANEGER::Scene_ChoiseLevel()
{

	bgm->Play((int)BGM_TYPE_SELECT);	//�I����ʂ�BGM���Đ�

	level_select->Operation(keydown);			//�I�����L�[����

	if (level_select->GetIsChoise())			//�I��������
	{
		GameLevel = level_select->GetChoiseSelectCode();		//�Q�[�����x���ݒ�
		NowScene = (int)SCENE_CHOISESTAGE;						//�X�e�[�W�I����ʂ�
	}

	return;
}

//��Փx�I����ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_ChoiseLevel()
{

	level_select->Draw();	//��Փx�̑I�����`��

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

	stage_select->Draw();		//�X�e�[�W�I�����`��

	return;
}

//�v���C��ʂ̏���
void GAMEMANEGER::Scene_Play()
{

	back->ChengeImage((int)PLAY_BACK);	//�w�i�摜��ύX

	gamelimittime->UpdateLimitTime(GAME_LIMIT_TIME);	//�������Ԃ̍X�V

	if (!Q_BASE::GetIsCreate())	//�����쐬���Ă��Ȃ����
	{
		quesiton.at(GameLevel)->CreateQuestion();	//�����쐬
	}

	if (Q_BASE::CheckInputKey(keydown))	//�L�[���͂�����������
	{
		if (Q_BASE::JudgAnser())				//�v���C���[�̉񓚂�������������
		{
			effect_atk->SetIsDraw(true,(int)EFFECT_ATACK);			//�A�j���[�V�����̕`����J�n����
		}
		else		//�s������������
		{
			player->SendDamege();	//�v���C���[�Ƀ_���[�W��^����
		}

	}

	if (effect_atk->GetIsDrawEnd())							//�A�j���[�V�����`�悪�I�������
	{
		effect_atk->SetIsDraw(false, (int)EFFECT_ATACK);					//�A�j���[�V������`�悵�Ȃ�
		effect_atk->ResetIsAnime((int)EFFECT_ATACK);						//�A�j���[�V������Ԃ����Z�b�g
		enemy.at(ENEMY::GetNowEnemyNum())->SendDamege();					//�G�Ƀ_���[�W��^����
		score.at(GameLevel)->CalcScore(gamelimittime->GetElapsedTime());	//�X�R�A���Z						
		gamelimittime->SetTime();											//�������Ԃ̍Čv��
	}

	if (enemy.at(ENEMY::GetNowEnemyNum())->GetHp() <= 0)		//�G��HP��0�ɂȂ�����
	{
		enemy.at(ENEMY::GetNowEnemyNum())->SetIsArive(false);	//�G���S
		if (enemy.at(ENEMY::GetNowEnemyNum())->GetFadeEnd())	//�t�F�[�h�A�E�g�I��������
		{
			ENEMY::NextEnemy();	//���̓G��
		}
	}
	
	if (ENEMY::GetNowEnemyNum() >= enemy.size() ||			//�G�̐����A�ő吔�𒴂�����
		player->GetHp() <= 0)								//�v���C���[��HP��0�ɂȂ�����	
	{
		NowScene = (int)SCENE_DRAWSCORE;		//�X�R�A�\����ʂ�
	}

	return;
}

//�v���C��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_Play()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	player->DrawHp();				//�v���C���[HP�`��

	if (ENEMY::GetNowEnemyNum() < enemy.size())	//���݂̓G���A�G�̍ő吔�ʓ���������
	{
		enemy.at(ENEMY::GetNowEnemyNum())->DrawCenter();	//�G�L�����`��
		enemy.at(ENEMY::GetNowEnemyNum())->DrawHp();		//HP�`��
	}

	Q_BASE::DrawQuestion();				//��蕶�`��
	Q_BASE::DrawInputNum();				//���͒��̐�����`��

	ScoreBase::DrawNowScore();			//���݂̃X�R�A�`��

	gamelimittime->DrawLimitTime(GAME_LIMITTIME_DRAW_X, GAME_LIMITTIME_DRAW_Y, GAME_LIMIT_TIME);			//�������Ԃ̕`��

	effect_atk->DrawCenter((int)EFFECT_ATACK);	//�U���G�t�F�N�g�`��

	return;
}

//�X�R�A�\����ʂ̏���
void GAMEMANEGER::Scene_DrawScore()
{

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		NowScene = (int)SCENE_END;	//�G���h��ʂ�
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

	back->ChengeImage((int)DAMMY_BACK);	//�w�i�摜��ύX

	if (keydown->IsKeyDownOne(KEY_INPUT_RETURN))		//�G���^�[�L�[�������ꂽ��
	{
		NowScene = (int)SCENE_TITLE;	//�^�C�g����ʂ�
	}

	return;
}

//�G���h��ʂ̕`�揈��
void GAMEMANEGER::Draw_Scene_End()
{

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, END_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	return;
}
