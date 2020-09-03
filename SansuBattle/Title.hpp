//Title.hpp
//�^�C�g����ʂ̏���

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ################
#include "Scene.hpp"
#include "Button.hpp"

//################### �}�N����` #####################
#define BT_START_X	70		//�X�^�[�g�{�^��X�ʒu
#define BT_START_Y	500		//�X�^�[�g�{�^��Y�ʒu
#define BT_END_X	500		//�X�^�[�g�{�^��X�ʒu
#define BT_END_Y	500		//�X�^�[�g�{�^��Y�ʒu

//################### �N���X��` #####################
class Title : public Scene	//Scene�N���X���p��
{
private:

	vector<Image*> bt_img;	//�{�^���̉摜
	vector<Button*> button;	//�{�^��

public:

	Title();		//�R���X�g���N�^ 
	~Title();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void Run() override;	//�^�C�g����ʂ̏���

};
