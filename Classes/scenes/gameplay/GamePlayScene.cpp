#include "GamePlayScene.h"
#include "common/Definition.h"

cocos2d::Scene* GamePlayScene::createScene()
{
	auto scene = cocos2d::Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(cocos2d::Vec2(0, GRAVITY));

	auto layer = GamePlayScene::create();
	scene->addChild(layer);
	return scene;
}

bool GamePlayScene::init()
{
	if (!Scene::initWithPhysics())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	mLevel5 = new Level5(this);
	mLevel5->Init();
	this->scheduleUpdate();
	return true;
}

void GamePlayScene::update(float dt)
{
	mLevel5->Update();
}
