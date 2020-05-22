//SELECT.hpp
//�I�������Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "DxLib.h"
#include "IMAGE.hpp"
#include <vector>

//##################### �}�N����` ######################

//##################### �N���X��` ######################
class SELECT
{

private:

	IMAGE* SelectImage;							//�I�����̉摜

	std::vector<int> SelectCode;				//�I�����̃R�[�h�ԍ�

	int Choise_SelectCode;						//�I�񂾑I�����̃R�[�h�ԍ�

	bool IsCreateSelect;						//�I��������ꂽ��
	bool IsChoise;								//�I��������

public:

	SELECT(const char *,const char *);			//�R���X�g���N�^
	~SELECT();									//�f�X�g���N�^

	bool GetIsCreateSelect();					//�I��������ꂽ���擾

	bool Add(const char*, const char*);			//�I������ǉ�

};
