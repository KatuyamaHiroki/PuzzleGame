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
	int _nextNumber; // 次にタップすべき番号
	float _time; // ゲームスタトからの経過時間（秒）
	 // タッチされた時の処理
	bool onTouchBegan(Touch* touch, Event* e);

	Vector<Sprite*> _items;
};