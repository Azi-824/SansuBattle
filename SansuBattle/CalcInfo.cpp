//CalcInfo.cpp
//���̌v�Z�ɕK�v�ȏ����Ǘ�����N���X

//############## �w�b�_�t�@�C���ǂݍ��� ###############
#include "CalcInfo.hpp"

//############## �N���X��` ################

//�R���X�g���N�^
CalcInfo::CalcInfo(vector<int> min, vector<int>max)
{
	Min = min;				//�ŏ��l�ݒ�
	Max = max;				//�ő�l�ݒ�
}

//�f�X�g���N�^
CalcInfo::~CalcInfo()
{
	//vector�̉��
	vector<int> v;
	Min.swap(v);
	vector<int> v2;
	Max.swap(v2);
}

//�ŏ��l�擾
int CalcInfo::GetMin(int level)
{
	return Min.at(level);
}

//�ő�l�擾
int CalcInfo::GetMax(int level)
{
	return Max.at(level);
}

