#include "GamePlayScene.h"
#include "scenes/ui/menu/MapLevel.h"
#include "models/levels/level3/Level3.h"
#include "models/levels/level5/Level5.h"
#include "models/levels/level8/Level8.h"
#include "common/Definition.h"

int GamePlayScene::mCurrentLevelIndex = 0;

cocos2d::Scene* GamePlayScene::createScene(const int& levelIndex)
{
	auto scene = cocos2d::Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_NONE);

	mCurrentLevelIndex = levelIndex - 1;

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
	if (mCurrentLevelIndex == 0)
	{
		mListOfLevels.push_back(new Level3(this));
	}
	else if (mCurrentLevelIndex == 1)
	{
		mListOfLevels.push_back(new Level5(this));
	}
	else{
		mListOfLevels.push_back(new Level8(this));
	}

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
			auto scene = GamePlayScene::createScene(mCurrentLevelIndex + 1);
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
		}
	});

	backButton->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			auto scene = MapLevel::createScene();
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
		}
	});
}

void GamePlayScene::ShowLevelCompletionPanel()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto levelCompletePanel = cocos2d::Sprite::create("sprites/gameplay/background_scene_transition.png");
	levelCompletePanel->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(levelCompletePanel);

	// Create a fade-in action //
	auto fadeInAction = cocos2d::FadeIn::create(FADE_DURATION_TIME);
	levelCompletePanel->runAction(fadeInAction);

	// Create a button "Go"	to go to the next level //
	auto goButton = cocos2d::ui::Button::create("sprites/gameplay/button_go.png",
		"sprites/gameplay/button_go.png",
		"sprites/gameplay/button_go.png");
	goButton->setPosition(cocos2d::Vec2(levelCompletePanel->getContentSize().width / 2,
		levelCompletePanel->getContentSize().height / 2));

	// Create a fade-out action //
	auto fadeOutAction = cocos2d::FadeOut::create(FADE_DURATION_TIME);

	goButton->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			levelCompletePanel->runAction(fadeOutAction);

			// TODO:
			auto scene = GamePlayScene::createScene(mCurrentLevelIndex + 1);
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
		}
	});
}

void GamePlayScene::update(float dt)
{
	mListOfLevels[0]->Update();

	if (mListOfLevels[0]->IsGameOver())
	{
		this->unscheduleUpdate();
		ShowGameOverPanel();
	}

	if (mListOfLevels[0]->IsCompletedLevel())
	{
		ShowLevelCompletionPanel();

		mCurrentLevelIndex++;
		if (mCurrentLevelIndex >= mListOfLevels.size())
		{
			mCurrentLevelIndex = 0;
		}

		this->unscheduleUpdate();
	}
}
