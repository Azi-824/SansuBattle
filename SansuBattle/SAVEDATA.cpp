//SaveData.cpp
//�Z�[�u�f�[�^���Ǘ�����N���X

//################### �w�b�_�t�@�C���ǂݍ��� ##################
#include "SaveData.hpp"

//#################### �N���X��` #######################

//�R���X�g���N�^
SaveData::SaveData()
{
	return;
}

//�f�X�g���N�^
SaveData::~SaveData()
{

	for (int i = 0; i < DataCode.size(); ++i)
	{
		delete DataCode.at(i);
	}

	//vector�̃�����������s��
	std::vector<Data*> v;			//���vector���쐬����
	DataCode.swap(v);			//��ƒ��g�����ւ���


	return;
}

//�ǂ̃t�@�C�����g�p���邩�擾
const char* SaveData::GetFileName(int gamemode)
{
	switch (gamemode)	//�Q�[�����x�����ƂɃZ�[�u����t�@�C���𕪂���
	{

	case (int)GAMEMODE_SUM:		//�����Z�̎�

		return SAVE_NAME_ADD;	//�����Z�p�̃t�@�C��

		break;	//�����Z�̎������܂�

	case (int)GAMEMODE_DIFFERENCE:		//�����Z�̎�

		return SAVE_NAME_DIF;	//�����Z�p�̃t�@�C��

		break;	//�����Z�̎������܂�

	case (int)GAMEMODE_PRODUCT:		//�|���Z�̎�

		return SAVE_NAME_PRO;	//�|���Z�p�̃t�@�C��

		break;	//�|���Z�̎������܂�

	case (int)GAMEMODE_DEALER:		//����Z�̎�

		return SAVE_NAME_DEA;	//����Z�p�̃t�@�C��

		break;	//����Z�̎������܂�

	case (int)GAMEMODE_SUM_DIF:		//�����Z�A�����Z�̎�

		return  SAVE_NAME_SUM_DIF;	//�����Z�A�����Z�p�̃t�@�C��

		break;	//�����Z�A�����Z�̎������܂�

	case (int)GAMEMODE_PRO_DEA:		//�|���Z�A����Z�̎�

		return SAVE_NAME_PRO_DEA;	//�|���Z�A����Z�p�̃t�@�C��

		break;	//�|���Z�A����Z�̎������܂�

	default:
		break;
	}

}

//�Q�[�����[�h���̃e�L�X�g���擾
const char* SaveData::GetTextGameMode(int gamemode)
{
	switch (gamemode)	//�Q�[�����x�����ƂɃZ�[�u����t�@�C���𕪂���
	{

	case (int)GAMEMODE_SUM:		//�����Z�̎�

		return TEXT_GAMEMODE_ADD;	//�����Z�p�̃e�L�X�g

		break;	//�����Z�̎������܂�

	case (int)GAMEMODE_DIFFERENCE:		//�����Z�̎�

		return TEXT_GAMEMODE_DIF;	//�����Z�p�̃e�L�X�g

		break;	//�����Z�̎������܂�

	case (int)GAMEMODE_PRODUCT:		//�|���Z�̎�

		return TEXT_GAMEMODE_PRO;	//�|���Z�p�̃e�L�X�g

		break;	//�|���Z�̎������܂�

	case (int)GAMEMODE_DEALER:		//����Z�̎�

		return TEXT_GAMEMODE_DEA;	//����Z�p�̃e�L�X�g

		break;	//����Z�̎������܂�

	case (int)GAMEMODE_SUM_DIF:		//�����Z�A�����Z�̎�

		return  TEXT_GAMEMODE_SUM_DIF;	//�����Z�A�����Z�p�̃e�L�X�g

		break;	//�����Z�A�����Z�̎������܂�

	case (int)GAMEMODE_PRO_DEA:		//�|���Z�A����Z�̎�

		return TEXT_GAMEMODE_PRO_DEA;	//�|���Z�A����Z�p�̃e�L�X�g

		break;	//�|���Z�A����Z�̎������܂�

	default:
		break;
	}

}

//�w�肳�ꂽ�t�@�C�������݂��邩�擾
//�߂�l�Fbool�Ftrue�@�t�@�C�������݂���Ffalse�@�t�@�C�������݂��Ȃ�
bool SaveData::CheckCreateFile(string filename)
{
	struct stat statbuf;			//�t�@�C���̑��݊m�F�Ɏg�p

	if (stat(filename.c_str(), &statbuf) == 0)		//�Z�[�u�f�[�^�p�̃t�@�C�����쐬����Ă���ꍇ
		return true;	//���݂���
	else	//�Ȃ��ꍇ
		return false;	//���݂��Ȃ�
}

//�f�[�^�ǉ�
void SaveData::Add(int score)
{

	DATEDATA Date;		//���ݎ���

	GetDateTime(&Date);	//���ݎ����擾

	DataCode.push_back(new Data(Date.Year,Date.Mon,Date.Day,score));	//�f�[�^���ǉ�

	return;

}

//�Z�[�u
bool SaveData::Save(int gamemode)
{
	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	if (!CheckCreateFile(LoadFile))//�Z�[�u�f�[�^�p�̃t�H���_���쐬����Ă��Ȃ��ꍇ�i���߂ẴZ�[�u�̏ꍇ�j
	{
		_mkdir(SAVEDATA_DIR);	//�Z�[�u�f�[�^���i�[����t�H���_���쐬
	}
	LoadFile += GetFileName(gamemode);


	std::ofstream ofs(LoadFile.c_str(), std::ios_base::ate);	//�t�@�C���I�[�v��

	if (!ofs)		//�t�@�C���I�[�v�����s��
	{
		string ErrorMsg(DATA_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErrorMsg += TEXT('\n');						//���s
		ErrorMsg += LoadFile;					//�摜�̃p�X

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * ��Ԃ�
			TEXT(DATA_ERROR_TTILE),
			MB_OK);

		return false;		//�Z�[�u���s

	}

	//�Z�[�u�f�[�^����������
	for (int i = 0; i < SAVE_MAX; ++i)	//�ۑ�����ő吔�܂Ń��[�v
	{

		if (i >= DataCode.size())	//�f�[�^�̌��ɒB������
			break;

		ofs << DataCode.at(i)->GetYear() << ',';				//�N�A�����o��
		ofs << DataCode.at(i)->GetMonth() << ',';				//���A�����o��
		ofs << DataCode.at(i)->GetDay() << ',';				//���A�����o��
		if (i == DataCode.size() - 1)	//�Ō�̏������݂�������
		{
			//�I�[������t����
			ofs << DataCode.at(i)->GetScore() << '\0';			//�������A�����o��
		}
		else	//�Ō�̏������݂���Ȃ����
		{
			//���s����
			ofs << DataCode.at(i)->GetScore() << '\n';			//�������A�����o��
		}


	}

	return true;		//�Z�[�u����
}

//�ǂݍ���
bool SaveData::Load(int gamemode)
{
	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += GetFileName(gamemode);

	if (CheckCreateFile(LoadFile))	//�ǂݍ��ރt�@�C�������݂���ꍇ
	{
		std::ifstream ifs(LoadFile.c_str());	//�t�@�C���ǂݎ��

		if (!ifs)		//�t�@�C���I�[�v�����s��
		{
			string ErrorMsg(DATA_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
			ErrorMsg += TEXT('\n');						//���s
			ErrorMsg += LoadFile;					//�摜�̃p�X

			MessageBox(
				NULL,
				ErrorMsg.c_str(),	//char * ��Ԃ�
				TEXT(DATA_ERROR_TTILE),
				MB_OK);

			return false;	//�ǂݍ��ݎ��s

		}


		string buf;
		int yy = 0, mm = 0, dd = 0, sc = 0;		//�N�A���A���A�X�R�A

		while (!ifs.eof())				//�Ō�̍s�܂œǂݍ���
		{
			std::getline(ifs, buf, ',');		//�J���}�܂œǂݍ���
			yy = atoi(buf.c_str());			//�N�ǂݍ���

			std::getline(ifs, buf, ',');	//�J���}�܂œǂݍ���
			mm = atoi(buf.c_str());			//���ǂݍ���

			std::getline(ifs, buf, ',');	//�J���}�܂œǂݍ���
			dd = atoi(buf.c_str());			//���ǂݍ���

			std::getline(ifs, buf, '\n');	//���s�܂œǂݍ���
			sc = atoi(buf.c_str());			//�X�R�A�ǂݍ���

			DataCode.push_back(new Data(yy, mm, dd, sc));		//�f�[�^�ǉ�

		}

	}

	return true;	//�ǂݍ��ݐ���
}

//**************** �\�[�g�֌W ******************
//�Z�[�u�f�[�^���~���ɕ��בւ���
void SaveData::Sort()
{

	for (int i = 0; i < DataCode.size(); ++i)
	{
		for (int j = DataCode.size() - 1; j > i; --j)
		{
			if (DataCode.at(j)->GetScore() > DataCode.at(j - 1)->GetScore())
			{
				auto temp = DataCode.at(j);
				DataCode.at(j) = DataCode.at(j - 1);
				DataCode.at(j - 1) = temp;
			}
		}
	}

	return;
}

//�f�[�^�`��
void SaveData::Draw(int gamemode)
{

	int Height = GetFontSizeToHandle(NowFontHandle);		//�����擾

	string text_gamemode = TEXT_GAMEMODE;	//�Q�[�����[�h�̃e�L�X�g
	text_gamemode += GetTextGameMode(gamemode);	//�Q�[�����[�h���̃e�L�X�g���擾

	DrawStringToHandle(DRAW_DATA_X, DRAW_DATA_Y, text_gamemode.c_str(), COLOR_WHITE, NowFontHandle);		//�����L���O�^�C�g���`��

	for (int i = 0; i < DataCode.size();++i)
	{

		if (i >= DRAW_DATA_MAX)		//�����L���O�`�悷��ő吔�ɂȂ�����
		{
			break;					//���[�v�𔲂���
		}

		DrawFormatStringToHandle(DRAW_DATA_X, DRAW_DATA_Y + (i + 1) * Height, COLOR_WHITE, NowFontHandle, DRAW_DATA_TEXT,
			i + 1,						//���ʂ�
			DataCode.at(i)->GetScore(),	//�X�R�A
			DataCode.at(i)->GetYear(),	//�N
			DataCode.at(i)->GetMonth(),	//��
			DataCode.at(i)->GetDay());	//��
	}

	return;
}
