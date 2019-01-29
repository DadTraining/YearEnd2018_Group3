#include "SplashScreenScene.h"

cocos2d::Scene* SplashScreenScene::createScene()
{
	return SplashScreenScene::create();
}

bool SplashScreenScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	return true;
}

void SplashScreenScene::update(float dt)
{
	
}
