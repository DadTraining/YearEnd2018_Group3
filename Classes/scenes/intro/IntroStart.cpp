#include "IntroStart.h"

cocos2d::Scene* IntroStart::createScene()
{
	return IntroStart::create();
}

bool IntroStart::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	return true;
}

void IntroStart::update(float dt)
{
	
}
