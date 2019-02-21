#include "GamePlayScene.h"
#include "scenes/ui/menu/MenuScene.h"
#include "common/Definition.h"
#include "models/levels/level5/Level5.h"

int GamePlayScene::mCurrentLevelIndex = 0;

cocos2d::Scene* GamePlayScene::createScene()
{
	auto scene = cocos2d::Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
	scene->getPhysicsWorld()->setGravity(cocos2d::Vec2(0, -1200));

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
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// Add all of the levels into the list //
	mListOfLevels.push_back(new Level5(this));

	this->scheduleUpdate();

	return true;
}

void GamePlayScene::ShowGameOverPanel()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto gameOverPanel = cocos2d::Sprite::create("sprites/gameplay/game_dialog.png"); 
	gameOverPanel->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(gameOverPanel);

	auto replayButton = cocos2d::ui::Button::create("sprites/gameplay/button_replay.png",
		"sprites/gameplay/button_replay.png",
		"sprites/gameplay/button_replay.png");

	replayButton->setPosition(cocos2d::Vec2(gameOverPanel->getContentSize().width / 2 - 100, 
		gameOverPanel->getContentSize().height / 2));

	auto backButton = cocos2d::ui::Button::create("sprites/gameplay/button_back.png",
		"sprites/gameplay/button_back.png",
		"sprites/gameplay/button_back.png");
	backButton->setPosition(cocos2d::Vec2(gameOverPanel->getContentSize().width / 2 + 100, 
		gameOverPanel->getContentSize().height / 2));

	gameOverPanel->addChild(replayButton);
	gameOverPanel->addChild(backButton);


	replayButton->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{ 
			auto scene = GamePlayScene::createScene();
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
		}
	});

	backButton->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			/*auto scene = MenuScene::createScene();
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));*/
		}
	});
}

void GamePlayScene::ShowLevelCompletion()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto gameOverPanel = cocos2d::Sprite::create("sprites/gameplay/background_scene_transition.png");
	gameOverPanel->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(gameOverPanel);

	// Create fade in
	auto fadeInAction = cocos2d::FadeIn::create(FADE_DURATION_TIME);
	gameOverPanel->runAction(fadeInAction);

	// Create a button "Go"	
	auto goButton = cocos2d::ui::Button::create("sprites/gameplay/button_go.png",
		"sprites/gameplay/button_go.png",
		"sprites/gameplay/button_go.png");
	goButton->setPosition(cocos2d::Vec2(gameOverPanel->getContentSize().width / 2,
		gameOverPanel->getContentSize().height / 2));

	// Create fade out
	auto fadeOutAction = cocos2d::FadeOut::create(FADE_DURATION_TIME);

	goButton->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			gameOverPanel->runAction(fadeOutAction);
			auto scene = GamePlayScene::createScene();
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
		}
	});
}

void GamePlayScene::update(float dt)
{
	if (mListOfLevels[mCurrentLevelIndex]->IsGameOver()) 
	{
		this->unscheduleUpdate();
		ShowGameOverPanel();
	}

	if (mListOfLevels[mCurrentLevelIndex]->IsCompletedLevel())
	{
<<<<<<< HEAD
=======
		ShowLevelCompletion();
>>>>>>> update level5
		mCurrentLevelIndex++;
		if (mCurrentLevelIndex >= mListOfLevels.size())
		{
			mCurrentLevelIndex = 0;
		}

		this->unscheduleUpdate();
	}

	mListOfLevels[mCurrentLevelIndex]->Update();
}
