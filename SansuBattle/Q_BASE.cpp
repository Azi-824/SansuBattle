//Q_BASE.cpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

//############### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Q_BASE.hpp"

//############### �N���X��` ####################

//�R���X�g���N�^
Q_BASE::Q_BASE()
{
	//�����o�[�ϐ�������
	this->Anser = -1;		//����������
	this->Q_Text = "";		//��蕶������

	return;
}

//�f�X�g���N�^
Q_BASE::~Q_BASE()
{
	return;
}

//����`�悷��
void Q_BASE::DrawQuestion()
{
	DrawFormatString(Q_DRAW_X, Q_DRAW_Y, GetColor(255, 255, 255), "%s", this->Q_Text.c_str());	//��蕶��`��

	return;
}

//���������肷��
/*
�����Fint�F�v���C���[�̓���
�߂�l�Fbool�Ftrue �����Ffalse �s����
*/
bool Q_BASE::JudgAnser(int plyer_ans)
{
	if (this->Anser == plyer_ans)		//�v���C���[�̉񓚂��A�����ƈꏏ��������
		return true;					//����
	else								//�ꏏ����Ȃ�������
		return false;					//�s����
}
