//Question.hpp
//���֌W�̑S�Ă̊�ɂȂ�N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Global.hpp"
#include "Image.hpp"

//################# �}�N����` #################
#define Q_IMG_DRAW_Y 490	//���̉摜�i���j�`��Y�ʒu
#define Q_DRAW_Y 520		//���̕`��Y�ʒu

#define EASY_VALUE_MAX 15	//�ȒP���x���̖��̍ő�l
#define NORMAL_VALUE_MAX 20	//���ʃ��x���̖��̍ő�l
#define HARD_VALUE_MAX	25	//������x���̖��̍ő�l
#define EASY_NUM	2		//�ȒP���x���̐����̐�
#define NR_NUM		3		//���ʃ��x���̐����̐�
#define HARD_NUM	4		//������x���̐����̐�

#define VALUE_MIN	3		//�l�̍ŏ��l

#define Q_IMAGE_DIR		R"(.\Image\Question)"		//���֌W�̉摜�̃f�B���N�g��

#define	Q_IMAGE_KOKUBAN_NAME	R"(\kokuban.png)"	//���̉摜�̖��O

//################# �񋓌^ ###################
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
	static vector<vector<int>> CalcType_Table;	//�e�Q�[�����[�h�̌v�Z�̎�ނ̃e�[�u��

	string Q_Text;				//��蕶
	int Anser;					//����
	bool IsCreate;				//�����쐬������

	bool IsAnswerd;				//�񓚍ς݂�

	void SetCalcType(int, int,int, vector<int>*);				//�v�Z�̎�ނ�ݒ�
	void SetOrder(vector<int>, vector<int>*);					//�v�Z�̏��Ԃ�ݒ�
	int GetMax(int, vector<int>);								//�ő�l�擾
	void CreateQuestion(vector<int>, vector<int>, vector<int>);	//�����쐬
	void CreateTable();											//�e�Q�[�����[�h�̌v�Z�̎�ނ̃e�[�u�����쐬
	void SetText(vector<int>, vector<int>, vector<int>);		//��蕶�̃e�L�X�g��ݒ�
	void Create(int, int);										//���쐬

public:

	Question(int, int);			//�R���X�g���N�^
	~Question();				//�f�X�g���N�^


	void DrawQuestion();		//����`�悷��

	bool JudgAnser(int);		//���������肷��
	bool GetIsCreate();			//�����쐬�������擾

};
