#include "MenuScene.h"
#include "scenes/gameplay/GamePlayScene.h"
#include "common/Definition.h"
#include "common/DefinitionUI.h"
#include"ui/CocosGUI.h"

#include "models/objects/obstacles/level5/LineFrame.h"
LineFrame* line;

cocos2d::Scene* MenuScene::createScene()
{
	return MenuScene::create();
}

bool MenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto background = cocos2d::Sprite::create("sprites/ui/menuscene/background.png");
	background->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(background, -1);

	mCurrentPassedLevelIndex = 63;

	setListButton();

	this->scheduleUpdate();

	return true;
}
void MenuScene::setListButton()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	std::string png = ".png", normal, pressed, num = ".1", path = "sprites/ui/menuscene/";
	char c;

	// Create ScrollView
	auto scrollView = cocos2d::ui::ScrollView::create();
	scrollView->setDirection(cocos2d::ui::ScrollView::Direction::HORIZONTAL);
	scrollView->setContentSize(cocos2d::Size(visibleSize.width  , 200));
	scrollView->setInnerContainerSize(cocos2d::Size(BUTTON_SIZE_WIDTH * 10 , 0));
	scrollView->setBounceEnabled(true);
	scrollView->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
	scrollView->setScrollBarOpacity(0);
	scrollView->setPosition(cocos2d::Vec2(SREEEN_RESOLUTION_WIDTH / 2, SREEEN_RESOLUTION_HEIGHT / 2 - 200));

	for (int i = 0; i < 9; i++)
	{
		c = '0' + (i + 1);
		pressed = path + c + num + png;

		auto button = cocos2d::ui::Button::create(pressed, pressed);
		button->setPosition(cocos2d::Vec2(i * 200 + 100, scrollView->getContentSize().height / 2));
		scrollView->addChild(button, 1);

		if (((1 << i) & mCurrentPassedLevelIndex) != (1 << i))
		{
			auto lockSprite = cocos2d::Sprite::create("sprites/ui/menuscene/lock.png");
			lockSprite->setPosition(button->getPosition());
			scrollView->addChild(lockSprite, 2);
			button->setTouchEnabled(false);
		}

		// Touch Event
		button->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::ENDED:

				auto scene = GamePlayScene::createScene(i + 1);
				cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));

				break;
			}
		});

	}
	addChild(scrollView);
}
void MenuScene::update(float dt)
{
}
