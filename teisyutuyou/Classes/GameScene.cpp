#include "GameScene.h"
#include<algorithm>

static const int COLUMN = 3;
static const int ROW = 3;
static const int BUTTON_SIZE = 80;
static const int TAG_TIME_LABEL = 10000;



GameScene* GameScene::create()
{
	auto scene = new GameScene();
	scene->init();
	scene->autorelease();

	return scene;
}
bool GameScene::init()
{
	Scene::init();
	_nextNumber = 1;
	_time = 0;
	srand(time(nullptr));
	auto numbers = std::vector<int>();

	auto bg = Sprite::create("bg3.jpg");
	bg->setPosition(640 / 2, 960 / 2);
	bg->setScale(1.5, 1.5);
	addChild(bg);

	//文字画像
	std::string numFileName = "numbers.png";
	int width = 10;
	int height = 14;
	char startChar = '0';
	auto label = Label::createWithCharMap(numFileName, width, height, startChar);
	label->setPosition(640 / 2, 600);
	label->setScale(3, 3);
	label->setLocalZOrder(3);
	label->setString(StringUtils::toString(_count));
	label->setName("count");
	addChild(label);

	// 1 から 16 までの数を用意する
	for (int i = 1; i<= COLUMN * ROW; i++) {
		numbers.push_back(i);
	}

	//起点
	Vec2 origin = Vec2(240, 360);

	//ボタン生成、設置
	for (unsigned int i = 0; i <numbers.size(); i++)
	{
		int row = i % COLUMN; // ( 下から )何行目か
		int column = i / COLUMN; // ( 左から )何列目か
		Vec2 position = origin + Vec2(column * BUTTON_SIZE, row * BUTTON_SIZE);
		int number = numbers[i];
		auto button = Sprite::create(StringUtils::format("%02d.png", number));
		if(number==2||number==4||number==6)
			button->setColor(Color3B(127.5,127.5 ,127.5));
		button->setTag(number); //ボタン番号をタグに使う
		button->setPosition(position);
		addChild(button);
		_items.pushBack(button);
	}
	
	// 画面がタッチされた時に onTouchBegan メソッドが呼び出されるように登録
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan =
		[this](Touch* touch, Event* e) { return onTouchBegan(touch, e); };
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener, this);
	return true;

}
// タッチされた時の処理
bool GameScene::onTouchBegan(Touch *pTouch, Event *pEvent) {
	Vec2 location = pTouch->getLocation();
	auto color = TintBy::create(0.0, 127.5, 127.5, 127.5);	//色変えるとき用

	for (int i = 0; i < (int)_items.size(); i++) {
		Sprite *item = _items.at(i);
		Rect spriteRect = Rect(item->getPosition().x - item->getContentSize().width / 2,
			item->getPosition().y - item->getContentSize().width / 2,
			item->getContentSize().width,
			item->getContentSize().height);
		if (spriteRect.containsPoint(location)) {
			if (item->getTag() == 1) {
				auto pImg = (CCSprite*)this->getChildByTag(1);
				pImg->runAction(color);
				aim[0] *= -1;
				pImg= (CCSprite*)this->getChildByTag(2);
				pImg->runAction(color->clone());
				aim[1] *= -1;
				pImg = (CCSprite*)this->getChildByTag(4);
				pImg->runAction(color->clone());
				aim[3] *= -1;
			}
			if (item->getTag() == 2)
			{
				auto pImg = (CCSprite*)this->getChildByTag(1);
				pImg->runAction(color);
				aim[0] *= -1;
				pImg = (CCSprite*)this->getChildByTag(2);
				pImg->runAction(color->clone());
				aim[1] *= -1;
				pImg = (CCSprite*)this->getChildByTag(3);
				pImg->runAction(color->clone());
				aim[2] *= -1;
				pImg = (CCSprite*)this->getChildByTag(5);
				pImg->runAction(color->clone());
				aim[4] *= -1;
			}
			if (item->getTag() == 3)
			{
				auto pImg = (CCSprite*)this->getChildByTag(2);
				pImg->runAction(color->clone());
				aim[1] *= -1;
				pImg = (CCSprite*)this->getChildByTag(3);
				pImg->runAction(color->clone());
				aim[2] *= -1;
				pImg = (CCSprite*)this->getChildByTag(6);
				pImg->runAction(color->clone());
				aim[5] *= -1;
			}
			if (item->getTag() == 4)
			{
				auto pImg = (CCSprite*)this->getChildByTag(1);
				pImg->runAction(color->clone());
				aim[0] *= -1;
				pImg = (CCSprite*)this->getChildByTag(4);
				pImg->runAction(color->clone());
				aim[3] *= -1;
				pImg = (CCSprite*)this->getChildByTag(5);
				pImg->runAction(color->clone());
				aim[4] *= -1;
				pImg = (CCSprite*)this->getChildByTag(7);
				pImg->runAction(color->clone());
				aim[6] *= -1;
			}
			if (item->getTag() == 5)
			{
				auto pImg = (CCSprite*)this->getChildByTag(2);
				pImg->runAction(color->clone());
				aim[1] *= -1;
				pImg = (CCSprite*)this->getChildByTag(4);
				pImg->runAction(color->clone());
				aim[3] *= -1;
				pImg = (CCSprite*)this->getChildByTag(5);
				pImg->runAction(color->clone());
				aim[4] *= -1;
				pImg = (CCSprite*)this->getChildByTag(6);
				pImg->runAction(color->clone());
				aim[5] *= -1;
				pImg = (CCSprite*)this->getChildByTag(8);
				pImg->runAction(color->clone());
				aim[7] *= -1;
			}

			if (item->getTag() == 6)
			{
				auto pImg = (CCSprite*)this->getChildByTag(3);
				pImg->runAction(color->clone());
				aim[2] *= -1;
				pImg = (CCSprite*)this->getChildByTag(5);
				pImg->runAction(color->clone());
				aim[4] *= -1;
				pImg = (CCSprite*)this->getChildByTag(6);
				pImg->runAction(color->clone());
				aim[5] *= -1;
				pImg = (CCSprite*)this->getChildByTag(9);
				pImg->runAction(color->clone());
				aim[8] *= -1;
			}
			if (item->getTag() == 7)
			{
				auto pImg = (CCSprite*)this->getChildByTag(4);
				pImg->runAction(color->clone());
				aim[3] *= -1;
				pImg = (CCSprite*)this->getChildByTag(7);
				pImg->runAction(color->clone());
				aim[6] *= -1;
				pImg = (CCSprite*)this->getChildByTag(8);
				pImg->runAction(color->clone());
				aim[7] *= -1;
			}
			if (item->getTag() == 8)
			{
				auto	pImg = (CCSprite*)this->getChildByTag(5);
				pImg->runAction(color->clone());
				aim[4] *= -1;
				pImg = (CCSprite*)this->getChildByTag(7);
				pImg->runAction(color->clone());
				aim[6] *= -1;
				pImg = (CCSprite*)this->getChildByTag(8);
				pImg->runAction(color->clone());
				aim[7] *= -1;
				pImg = (CCSprite*)this->getChildByTag(9);
				pImg->runAction(color->clone());
				aim[8] *= -1;
			}
			if (item->getTag() == 9)
			{
				auto	pImg = (CCSprite*)this->getChildByTag(6);
				pImg->runAction(color->clone());
				aim[5] *= -1;
				pImg = (CCSprite*)this->getChildByTag(8);
				pImg->runAction(color->clone());
				aim[7] *= -1;
				pImg = (CCSprite*)this->getChildByTag(9);
				pImg->runAction(color->clone());
				aim[8] *= -1;
			}
			_count++;
			((Label*)getChildByName("count"))->setString(StringUtils::toString(_count));
			for (int i = 0; i < 9; i++)
			{
				CCLOG("%d  %d",i, aim[i]);
				if (aim[i] == -1)
				{
					return false;
				}
				if (i == 8 && aim[i] == 1) {
					auto gamecler = Sprite::create("Game.png");
					gamecler->setPosition(640/2,960/2+250);
					gamecler->setScale(2,2);
					addChild(gamecler);
					// タッチイベントリスナーを解除する
					Director::getInstance()->getEventDispatcher()
						->removeAllEventListeners();
				}
			}
		}
	}
	return true;
}