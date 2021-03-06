#include "HelloWorldScene.h"
#include "GameScene.h"

#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardNpc.h"
#include "cardInfo/ManagerSkill.h"
#include "PlayerList.h"
#include "Player.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	auto start = cocos2d::MenuItemFont::create("start", CC_CALLBACK_1(HelloWorld::menuStartCallback,this));
	auto menu = cocos2d::Menu::create();
	menu->addChild(start);
	addChild(menu);

	auto player = new Player(1, 24);
	player->pushHandCard(HandCardManager::getSingleton().getOne());
	PlayerList::getSingleton().joinPlayer(player);
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(2,28));
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(3,27));
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(1,25));
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(4,28));
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(5,29));
	PlayerList::getSingleton().joinPlayer(new NpcPlayer(1,25));
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuStartCallback(cocos2d::Ref* pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);
}