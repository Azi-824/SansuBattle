//Effect.hpp
//�G�t�F�N�g���Ǘ�����N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include "Animation.hpp"
#include "Music.hpp"

//###################### �}�N����` #################################

//###################### �񋓌^ ##########################
enum EFFECT_NAME
{
	EF_NAME_DAMEGE,		//�_���[�W�G�t�F�N�g
};

using std::vector;
using std::string;
//################### �N���X��` #########################
class Effect
{
private:

	Animation* anim;			//�A�j���[�V����
	Music* se;					//���ʉ�

	bool IsFadeout;				//�t�F�[�h�A�E�g�������s����
	bool IsFadein;				//�t�F�[�h�C���������s����

public:

	Effect(Animation*,Music*);	//�R���X�g���N�^
	Effect();					//�R���X�g���N�^
	~Effect();					//�f�X�g���N�^

	bool GetIsLoad();			//�ǂݍ��߂����擾
	void SetEffect(Animation*,Music*);	//�G�t�F�N�g��ݒ�

	void Draw(int, int);	//�`��
	void DrawCenter();		//��ʒ����ɕ`��
	void DrawCenter(RECT);	//�w�肳�ꂽ�̈���̒����ɕ`��

	void SetInit();						//�����ݒ�

	bool GetIsNowEffect();				//�G�t�F�N�g�`�撆���擾
	bool GetIsEffectEnd();				//�G�t�F�N�g�I���������擾
	void Reset();						//���Z�b�g

};
