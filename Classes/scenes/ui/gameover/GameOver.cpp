#include "GameOver.h"

cocos2d::Scene* GameOver::createScene()
{
	return GameOver::create();
}

bool GameOver::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	return true;
}

void GameOver::update(float dt)
{
	
}