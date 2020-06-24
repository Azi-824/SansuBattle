/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Image.cpp     																				�@ */
/*       																						�@ */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Image.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
Image::Image(const char *dir,const char *name)
{
	//�����o�ϐ���������
	FilePath = "";	//�p�X
	FileName = "";	//���O
	
	IsLoad = false;	//�ǂݍ��߂����H

	//�摜��ǂݍ���
	string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	Handle = LoadGraph(LoadfilePath.c_str());//�摜��ǂݍ���
	
	if (Handle == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');				//���s
		ErroeMsg += LoadfilePath;			//�摜�̃p�X

		MessageBox(
			NULL, 
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(IMAGE_ERROR_TITLE),
			MB_OK);

		return;
	}

	FilePath = LoadfilePath;		//�摜�̃p�X��ݒ�
	FileName = name;				//�摜�̖��O��ݒ�

	IsLoad = true;		//�ǂݍ��߂�

	IsDraw = true;	//�`�悵�Ă悢

	IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
	FadeEnd = false;//�t�F�[�h�G�t�F�N�g���I����Ă��Ȃ�

	return;
}

//�f�X�g���N�^
Image::~Image()
{
	//for (int handle : this->Handle)
	//{
	//	DeleteGraph(handle);		//�ǂݍ��񂾉摜���폜
	//}

	DeleteGraph(Handle);	//�ǂݍ��񂾉摜���폜

	//vector�̃�����������s��
	//std::vector<int> v;			//���vector���쐬����
	//this->Handle.swap(v);		//��ƒ��g�����ւ���

	//std::vector<int>v2;
	//this->Width.swap(v2);

	//std::vector<int>v3;
	//this->Height.swap(v3);

	//std::vector<bool>v4;
	//this->IsDraw.swap(v4);

	//std::vector<bool>v5;
	//this->IsFade.swap(v5);

	//std::vector<bool>v6;
	//this->FadeEnd.swap(v6);

	//return;
}

//�t�@�C���̖��O���擾
std::string Image::GetFileName(void)
{
	return FileName;
}

//�T�C�Y��ݒ肷��
void Image::SetInit(void)
{
	//Width.resize(Handle.size());	//�T�C�Y�ύX
	//Height.resize(Handle.size());	//�T�C�Y�ύX
	//�摜�̐��������[�v����
	//for (int i = 0; i < this->Handle.size(); ++i)
	//{
	//	GetGraphSize(this->Handle[i], &this->Width[i], &this->Height[i]);	//�摜�T�C�Y�擾
	//}

	GetGraphSize(Handle, &Width, &Height);	//�摜�T�C�Y�擾
	return;
}

//�摜�����擾����
//int Image::GetSize(void)
//{
//	return this->Handle.size();
//}

//�����擾
int Image::GetWidth()
{
	return Width;
}

//�������擾
int Image::GetHeight()
{
	return Height;
}

//�ǂݍ��߂��H
bool Image::GetIsLoad(void)
{
	return IsLoad;
}

//�`�悵�Ă悢���ݒ�
void Image::SetIsDraw(bool isdraw)
{
	IsDraw = isdraw;
	FadeEnd = false;	//�t�F�[�h�A�E�g�I���t���O���Z�b�g
}

//�摜��`��
void Image::Draw(int x, int y)
{

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{
				
				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);											//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;			//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g
			IsFade = false;			//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}
	

	return;

}

//�摜��`��i�����j
//�����Fint�F��ʂ̉����F�f�t�H���g�̓Q�[����ʂ̉���
//�����Fint�F�`�悷�鍂���F�f�t�H���g�̓Q�[����ʂ̍���
void Image::DrawCenter(int width,int height)
{

	int x = 0, y = 0;	//�`�悷��X�ʒu,Y�ʒu
	x = (width / 2) - (Width / 2);			//��ʒ����ɂȂ�悤�Ɍv�Z
	y = (height / 2) - (Height / 2);		//��ʒ����ɂȂ�悤�Ɍv�Z

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{

				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);					//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;	//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;				//�J�E���g���Z�b�g
			IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}



	return;
}

//�摜��ǉ�
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
//bool Image::AddImage(const char *dir, const char *name)
//{
//
//	this->IsLoad = false;	//�ǂݍ��߂Ă��Ȃ�
//
//	//�摜��ǂݍ���
//	std::string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
//	LoadfilePath += dir;
//	LoadfilePath += name;
//
//	this->Handle.push_back(LoadGraph(LoadfilePath.c_str()));	//�摜��ǂݍ���
//
//
//	if (this->Handle.back() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
//	{
//		std::string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
//		ErroeMsg += TEXT('\n');					//���s
//		ErroeMsg += LoadfilePath;				//�摜�̃p�X
//
//		MessageBox(
//			NULL,
//			ErroeMsg.c_str(),	//char * ��Ԃ�
//			TEXT(IMAGE_ERROR_TITLE),
//			MB_OK);
//
//		return false;
//	}
//
//	this->IsLoad = true;		//�ǂݍ��߂�
//
//	this->IsDraw.push_back(true);	//�`�悵�Ă悢
//	this->IsFade.push_back(false);	//�t�F�[�h�A�E�g���Ȃ�
//	this->FadeEnd.push_back(false);	//�t�F�[�h�G�t�F�N�g���I����Ă��Ȃ�
//
//	this->ImageKind = this->Handle.size();	//�ǂݍ��񂾐����擾
//
//	return true;
//
//}
//
////�`�悷��摜��ύX
//void Image::ChengeImage(int kind)
//{
//	this->Draw_Num = kind;
//	return;
//}
//
////�`�悷��摜������̉摜��
//void Image::NextImage()
//{
//	if (this->Draw_Num < this->Handle.size() - 1)	//�`�悷��摜���Ō�̉摜����Ȃ����
//	{
//		++this->Draw_Num;	//���̉摜��
//	}
//	return;
//}
//
////�`�悷��摜���w�肳�ꂽ���A���̉摜��
//void Image::NextImage(int value)
//{
//	if (this->Draw_Num + value < this->Handle.size() - 1)	//�`�悷��摜���Ō�̉摜����Ȃ����
//	{
//		this->Draw_Num += value;	//�w�肳�ꂽ���A���̉摜��
//	}
//	return;
//}
//
////�`�悷��摜����O�̉摜��
//void Image::PrevImage()
//{
//	if (this->Draw_Num > 0)	//�`�悷��摜���ŏ��̉摜����Ȃ����
//	{
//		--this->Draw_Num;	//�O�̉摜��
//	}
//	return;
//}
//
////�`�悷��摜���w�肳�ꂽ���A�O�̉摜��
//void Image::PrevImage(int value)
//{
//	if (this->Draw_Num - value > 0)	//�`�悷��摜���ŏ��̉摜����Ȃ����
//	{
//		this->Draw_Num -= value;		//�O�̉摜��
//	}
//	return;
//}
//
////�`�悷��摜��擪�̉摜��
//void Image::ChengeImageFront()
//{
//	this->Draw_Num = 0;	//�擪�̉摜��
//	return;
//}

//�t�F�[�h�A�E�g���邩�ݒ�
void Image::SetIsFade(bool isfade)
{
	IsFade = isfade;
	FadeEnd = false;	//�t�F�[�h�A�E�g�I���t���O���Z�b�g

	return;
}

//�t�F�[�h�G�t�F�N�g���I�����Ă��邩�擾
bool Image::GetFadeEnd()
{
	return FadeEnd;
}
