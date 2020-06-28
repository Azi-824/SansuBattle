//Question.hpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "CalcInfo.hpp"
#include <string>
#include <vector>
#include "KeyDown.hpp"
#include "Image.hpp"

//################# �}�N����` #################
#define Q_IMG_DRAW_Y 490	//���̉摜�i���j�`��Y�ʒu
#define Q_DRAW_Y 500		//���̕`��Y�ʒu

#define Q_EASY_VALUE_MAX 9	//�ȒP���[�h�̖��̍ő�l

#define Q_IMAGE_DIR		R"(.\MY_IMG\Question)"		//���֌W�̉摜�̃f�B���N�g��

#define	Q_IMAGE_KOKUBAN_NAME	R"(\kokuban.png)"	//���̉摜�̖��O

//################# �񋓌^ ###################
enum INPUT_NUM
{
	INPUT_NUM_0,		//���͒l0
	INPUT_NUM_1,		//���͒l1
	INPUT_NUM_2,		//���͒l2
	INPUT_NUM_3,		//���͒l3
	INPUT_NUM_4,		//���͒l4
	INPUT_NUM_5,		//���͒l5
	INPUT_NUM_6,		//���͒l6
	INPUT_NUM_7,		//���͒l7
	INPUT_NUM_8,		//���͒l8
	INPUT_NUM_9,		//���͒l9
	INPUT_ENTER = 100,	//����L�[
	INPUT_BACK = 200,	//�o�b�N�L�[
	INPUT_NOT_NUM = -1	//���l�ȊO
};		//���͒l�̒l

enum CALC_KIND
{
	CALC_SUM,			//�����Z
	CALC_DIFFERENCE,	//�����Z
	CALC_PRODUCT,		//�|���Z
	CALC_DEALER,		//����Z
	CALC_MAX			//�v�Z�̎�ނ̌�
};	//�v�Z�̎��

using std::vector;
using std::string;

//################# �N���X��` #################
class Question
{
private:

	static Image* img_kokuban;			//���̉摜
	static vector<CalcInfo*> calc_info;	//�v�Z�Ɏg�p������

	static vector<vector<int>> value_num;	//�l�̐�

	string Q_Text;				//��蕶
	int Anser;					//����
	int InputNum;				//���͂��ꂽ����
	int InputNumBuf;			//���͂��ꂽ�����𒙂߂Ă���
	bool IsCreate;				//�����쐬������

	int GetInputNum(KeyDown*);									//���͂��ꂽ�������擾
	void SetCalcType(int, int, vector<int>*);					//�v�Z�̎�ނ�ݒ�
	void SetOrder(vector<int>, vector<int>*);					//�v�Z�̏��Ԃ�ݒ�
	void CreateQuestion(vector<int>, vector<int>, vector<int>);	//�����쐬
	void CreateInfo(int);										//�v�Z�Ɏg�p��������쐬
	void CreateValueNum(int);									//�Q�[�����[�h���̒l�̐��̏����쐬

public:

	Question();							//�R���X�g���N�^
	~Question();						//�f�X�g���N�^

	void Create(int, int);			//���쐬

	void DrawQuestion();			//����`�悷��
	void DrawInputNum();			//���͒��̐�����`�悷��

	bool JudgAnser();			//���������肷��

	bool CheckInputKey(KeyDown*);//�L�[���͒����擾

	bool GetIsCreate();			//�����쐬�������擾

	void Reset();				//�������Z�b�g


};
