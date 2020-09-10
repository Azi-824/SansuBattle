//Save.cpp
//�Z�[�u�֌W�̃N���X

//################## �w�b�_�t�@�C���ǂݍ��� ####################
#include "Save.hpp"

//################### �N���X��` ######################

vector<string> Save::NameTable;	//�t�@�C�����̃e�[�u��

//�R���X�g���N�^
Save::Save(){}

//�f�X�g���N�^ 
Save::~Save(){}

//�ǂݍ���
bool Save::Load(vector<Data*> *data, int mode)
{

	CreateTable();	//�e�[�u���̍쐬

	if (!data->empty())	//�󂶂�Ȃ����
	{
		data->clear();		//�f�[�^���Z�b�g
		Data::CntClear();	//�J�E���g���N���A
	}

	struct stat statbuf;			//�t�@�C���̑��݊m�F�Ɏg�p
	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += NameTable.at(mode);
	if (stat(LoadFile.c_str(), &statbuf) == 0)		//�Z�[�u�f�[�^�p�̃t�@�C�����쐬����Ă���ꍇ
	{

		std::ifstream ifs(LoadFile.c_str());	//�t�@�C���ǂݎ��

		if (!ifs)		//�t�@�C���I�[�v�����s��
		{
			string ErrorMsg(DATA_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
			ErrorMsg += TEXT('\n');				//���s
			ErrorMsg += LoadFile;				//�摜�̃p�X

			MessageBox(
				NULL,
				ErrorMsg.c_str(),	//char * ��Ԃ�
				TEXT(DATA_ERROR_TTILE),
				MB_OK);

			return false;	//�ǂݍ��ݎ��s

		}

		string buf;
		int sc = 0;		//�X�R�A
		int cnt = 0;	//�J�E���g�p
		DATEDATA date;	//���t�f�[�^

		while (!ifs.eof())				//�Ō�̍s�܂œǂݍ���
		{
			std::getline(ifs, buf, ',');	//�J���}�܂œǂݍ���
			date.Year = atoi(buf.c_str());	//�N�ǂݍ���

			std::getline(ifs, buf, ',');	//�J���}�܂œǂݍ���
			date.Mon = atoi(buf.c_str());	//���ǂݍ���

			std::getline(ifs, buf, ',');	//�J���}�܂œǂݍ���
			date.Day = atoi(buf.c_str());	//���ǂݍ���

			std::getline(ifs, buf, '\n');	//���s�܂œǂݍ���
			sc = atoi(buf.c_str());			//�X�R�A�ǂݍ���


			data->push_back(new Data(date, sc));		//�f�[�^�ǉ�
		}

	}

	return true;	//�ǂݍ��ݐ���
}

//�Z�[�u
bool Save::DataSave(vector<Data*> data, int mode)
{

	CreateTable();	//�e�[�u���̍쐬

	struct stat statbuf;			//�t�@�C���̑��݊m�F�Ɏg�p
	if (stat(SAVEDATA_DIR, &statbuf) != 0)		//�Z�[�u�f�[�^�p�̃t�@�C�����쐬����Ă��Ȃ��ꍇ
	{
		_mkdir(SAVEDATA_DIR);	//�Z�[�u�f�[�^���i�[����t�H���_���쐬
	}

	string LoadFile;
	LoadFile += SAVEDATA_DIR;
	LoadFile += NameTable.at(mode);

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

	vector<DATEDATA> date;	//���t�f�[�^
	vector<int>	score;		//�X�R�A
	for (auto d : data)
	{
		date.push_back(d->GetDate());	//���t�f�[�^���R�s�[
		score.push_back(d->GetScore());	//�X�R�A���R�s�[
	}

	//�Z�[�u�f�[�^����������
	for (int i = 0; i < SAVE_MAX; ++i)	//�ۑ�����ő吔�܂Ń��[�v
	{

		if (i >= data.size())	//�f�[�^�̌��ɒB������
			break;

		ofs << date.at(i).Year << ',';	//�N�A�����o��
		ofs << date.at(i).Mon << ',';	//���A�����o��
		ofs << date.at(i).Day << ',';	//���A�����o��
		ofs << score.at(i);				//�X�R�A�����o��

		//�Ō�̏������݂Ȃ�I�[������t���A��������Ȃ���Ή��s
		i == data.size() - 1 ? ofs << '\0' : ofs << '\n';

	}

	//vector�̉��
	vector<DATEDATA> v;	
	date.swap(v);
	vector<int>	v2;
	score.swap(v2);

	return true;	//�Z�[�u����
}

//�\�[�g����
void Save::Sort(vector<Data*> *data)
{
	for (int i = 0; i < data->size(); ++i)
	{
		for (int j = data->size() - 1; j > i; --j)
		{
			if (data->at(j)->GetScore() > data->at(j - 1)->GetScore())
			{
				auto temp = data->at(j);
				data->at(j) = data->at(j - 1);
				data->at(j - 1) = temp;
				//�v�f�ԍ��̌���
				auto temp2 = data->at(j)->GetElement();
				data->at(j)->SetElement(data->at(j - 1)->GetElement());
				data->at(j - 1)->SetElement(temp2);
			}
		}
	}
}

//�e�[�u���̍쐬
void Save::CreateTable()
{
	if (NameTable.empty())	//�e�[�u�����쐬����Ă��Ȃ����
	{
		//�t�@�C�����̃e�[�u�����쐬
		NameTable = { SAVE_NAME_SUM ,	//�����Z
			SAVE_NAME_DIF,				//�����Z
			SAVE_NAME_PRO,				//�|���Z
			SAVE_NAME_DEA,				//����Z
			SAVE_NAME_SUM_DIF,			//+-
			SAVE_NAME_PRO_DEA,			//*/
			SAVE_NAME_SUM_PRO,			//+*
			SAVE_NAME_SUM_DEA,			//+/
			SAVE_NAME_DIF_PRO,			// /*
			SAVE_NAME_SUM_DIF_PRO,		//+-*
			SAVE_NAME_SUM_DIF_DEA,		//+-/
			SAVE_NAME_ALL				//+-*/
		};
	}
}