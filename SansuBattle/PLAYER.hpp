//Player.hpp
//�v���C���[���Ǘ�����N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Charactor.hpp"
#include "KeyDown.hpp"

//##################### �}�N����` #########################
#define IMG_DIR_PLAYER	R"(.\Image\Player)"		//�v���C���[�̉摜�̃f�B���N�g��

#define IMG_NAME_HP		R"(\hp.png)"				//HP�摜�̖��O

#define PLAYER_HP_DRAW_X		20	//HP�̕`��J�nX�ʒu
#define PLAYER_HP_DRAW_Y		500	//HP�̕`��J�nY�ʒu

//##################### �񋓌^ ##########################
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
	INPUT_MINUS = 300,	//�}�C�i�X�L�[
	INPUT_NOT_NUM = -1	//���l�ȊO
};		//���͒l�̒l

//##################### �N���X��` #########################
class Player : public Charactor		//�L�����N�^�[�N���X���p��
{
private:

	int InputNum;				//���͂��ꂽ����
	KeyDown* keydown;			//�L�[����

	int GetInputKey();			//���͂��ꂽ�L�[���擾

public:

	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	bool SetInit() override;	//�����ݒ�

	void DrawInputNum();		//���͒��̐�����`�悷��
	bool CheckInputKey();		//�L�[���͒����擾
	void InpReset();			//���͕������Z�b�g
	int GetAns();				//���͂��ꂽ�������擾

};
