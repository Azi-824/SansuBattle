//CalcInfo.hpp
//���̌v�Z�ɕK�v�ȏ����Ǘ�����N���X

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Global.hpp"
#include <vector>

using std::vector;

//############# �N���X��` ###############
class CalcInfo
{
private:

	vector<int>	Min;		//�ŏ��l
	vector<int> Max;		//�ő�l

public:

	CalcInfo(vector<int>, vector<int>);		//�R���X�g���N�^
	~CalcInfo();							//�f�X�g���N�^

	int GetMin(int);		//�ŏ��l�擾
	int GetMax(int);		//�ő�l�擾

};
