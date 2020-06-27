//CalcInfo.cpp
//���̌v�Z�ɕK�v�ȏ����Ǘ�����N���X

//############## �w�b�_�t�@�C���ǂݍ��� ###############
#include "CalcInfo.hpp"

//############## �N���X��` ################

//�R���X�g���N�^
CalcInfo::CalcInfo(vector<int> min, vector<int>max, vector<int>value_num)
{
	Min = min;				//�ŏ��l�ݒ�
	Max = max;				//�ő�l�ݒ�
	Value_Num = value_num;	//���ݒ�
}

//�f�X�g���N�^
CalcInfo::~CalcInfo()
{
	//vector�̉��
	vector<int> v;
	Min.swap(v);
	vector<int> v2;
	Max.swap(v2);
	vector<int> v3;
	Value_Num.swap(v3);

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

//���擾
int CalcInfo::GetValueNum(int level)
{
	return Value_Num.at(level);
}
