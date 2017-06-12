#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GameScene : public cocos2d::Scene
{
public:
	static GameScene* create();
	bool init();
	bool flag=false;
	int aim[9] = { 1,-1,1,-1,1,-1,1,1,1 };
	int _count=0;

private:
	int _nextNumber; // ���Ƀ^�b�v���ׂ��ԍ�
	float _time; // �Q�[���X�^�g����̌o�ߎ��ԁi�b�j
	 // �^�b�`���ꂽ���̏���
	bool onTouchBegan(Touch* touch, Event* e);

	Vector<Sprite*> _items;
};