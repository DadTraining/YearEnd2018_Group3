#include "MapLevel.h"
#include "scenes/gameplay/GamePlayScene.h"
#include "common/Definition.h"

#include"ui/CocosGUI.h"

cocos2d::Scene* MapLevel::createScene()

{
	return MapLevel::create();
}

bool MapLevel::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto background = cocos2d::Sprite::create("sprites/ui/mapLevel.png");

	background->setPosition(cocos2d::Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	addChild(background, -1);
	setListButton();

	return true;
}
void MapLevel::setListButton()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	std::string png = ".png", normal, pressed, num = ".1", path = "sprites/ui/";
	char c;

	for (int i = 1; i < 5; i++)
	{
		////////////////
		//add button to list
		c = '0' + i;
		normal = path + c + png;
		pressed = path + c + num + png;
		auto button = cocos2d::ui::Button::create(pressed, pressed);
		mListButton.push_back(button);


		///////////////////
		//set position for button
		switch (i)
		{
		case 1:
		{
			button->setPosition(cocos2d::Vec2(100 + button->getContentSize().width / 2, visibleSize.height * 3.07 / 4));
			break;
		}
		case 2:
		{
			button->setPosition(cocos2d::Vec2(visibleSize.width - button->getContentSize().width, visibleSize.height * 3.07 / 4));
			break;
		}
		case 3:
		{
			button->setPosition(cocos2d::Vec2(100 + button->getContentSize().width / 2, visibleSize.height / 2.02));
			break;
		}
		case 4:
		{
			button->setPosition(cocos2d::Vec2(visibleSize.width - button->getContentSize().width , visibleSize.height / 2.02));
			break;
		}
		default:
			break;
		}

		this->addChild(button);



		button->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::ENDED:

				CCLOG(" sad %i", i);
				auto scene = GamePlayScene::createScene(i);
				cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));

				break;
			}
		});
	}
}
void MapLevel::update(float dt)
{
	
}
