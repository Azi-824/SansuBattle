//SELECT.cpp
//�I�������Ǘ�����N���X

//################# �w�b�_�t�@�C���ǂݍ��� #######################
#include "SELECT.hpp"

//################# �N���X��` ########################

//�R���X�g���N�^
SELECT::SELECT(const char* dir, const char* name)
{

	//�����o�[�ϐ�������
	this->Choise_SelectCode = -1;		//�I�񂾑I�����̃R�[�h��������
	this->IsChoise = false;				//�I��������������

	this->SelectImage = new IMAGE(dir, name);					//�I�����̉摜�𐶐�
	this->IsCreateSelect = this->SelectImage->GetIsLoad();		//�摜��ǂݍ��߂����ݒ�
	this->SelectCode.push_back(this->SelectCode.size());		//�I�����̃R�[�h�ԍ���ݒ�

	return;
}

//�f�X�g���N�^
SELECT::~SELECT()
{
	//vector�̃�����������s��
	std::vector<int> v;				//���vector���쐬����
	this->SelectCode.swap(v);		//��ƒ��g�����ւ���

	return;

}

//�I��������ꂽ���擾
bool SELECT::GetIsCreateSelect()
{
	return this->IsCreateSelect;
}

//�I������ǉ�
bool SELECT::Add(const char* dir, const char* name)
{
	this->IsCreateSelect = this->SelectImage->AddImage(dir, name);		//�摜��ǉ�
	this->SelectCode.push_back(this->SelectCode.size());				//�I�����R�[�h��ݒ�
	return this->IsCreateSelect;
}

//�`��
/*
�����Fint�F�`��J�nX�ʒu
�����Fint�F�`��J�nY�ʒu
�����Fint�F�`��\����
*/
void SELECT::Draw(int x, int y, int width)
{

}
