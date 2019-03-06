#include "LevelCompletionPanel.h"
#include "scenes/ui/menu/MenuScene.h"
#include "scenes/gameplay/GamePlayScene.h"
#include "common/DefinitionUI.h"

#include "ui/CocosGUI.h"

LevelCompletionPanel::LevelCompletionPanel(cocos2d::Scene* scene)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// The background sprite //
	auto backgroundSprite = cocos2d::Sprite::create("sprites/ui/panels/level_completion/background.png");
	backgroundSprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	scene->addChild(backgroundSprite, 10);
	backgroundSprite->setOpacity(0);
	auto backgroundFadingAction = cocos2d::FadeIn::create(0.5F);
	backgroundSprite->runAction(backgroundFadingAction);

	// The ray sprite //
	auto raySprite = cocos2d::Sprite::create("sprites/ui/panels/level_completion/sun_ray.png");
	raySprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y
		- raySprite->getContentSize().height / 2 + 100));
	scene->addChild(raySprite, 11);
	auto rayRotatingAction = cocos2d::RotateBy::create(10, 180);
	raySprite->runAction(cocos2d::RepeatForever::create(rayRotatingAction));

	// The congratulations sprite //
	auto congratulationsSprite = cocos2d::Sprite::create("sprites/ui/panels/level_completion/congratulations_title.png");
	congratulationsSprite->setPosition(raySprite->getPosition());
	scene->addChild(congratulationsSprite, 12);

	// The first label //
	auto firstLabel = cocos2d::Label::createWithTTF("LEVEL CLEAR!", "fonts/AvenirLTStd-Heavy.otf", 35);
	firstLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 + origin.y - visibleSize.height / 5));
	scene->addChild(firstLabel, 11);

	// The second label //
	auto secondLabel = cocos2d::Label::createWithTTF("You have just finished this level.", "fonts/AvenirLTStd-Heavy.otf", 20);
	secondLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x,
		firstLabel->getPositionY() - secondLabel->getContentSize().height * 2));
	scene->addChild(secondLabel, 11);

	// The third label //
	auto thirdLabel = cocos2d::Label::createWithTTF("Ready for the next one?", "fonts/AvenirLTStd-Heavy.otf", 25);
	thirdLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x,
		secondLabel->getPositionY() - thirdLabel->getContentSize().height));
	thirdLabel->enableBold();
	scene->addChild(thirdLabel, 11);

	// The goToNextLevel button //
	auto goToNextLevelButton = cocos2d::ui::Button::create("sprites/ui/panels/level_completion/go_button_normal.png",
		"sprites/ui/panels/level_completion/go_button_click.png", "sprites/ui/panels/level_completion/go_button_click.png");
	goToNextLevelButton->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x,
		thirdLabel->getPositionY() - goToNextLevelButton->getContentSize().height));
	scene->addChild(goToNextLevelButton, 11);
	goToNextLevelButton->addTouchEventListener([=](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			GoToNextLevel();
		}
	});

	// The menu button //
	auto menuButton = cocos2d::ui::Button::create("sprites/ui/panels/gameover/menu_button_normal.png",
		"sprites/ui/panels/gameover/menu_button_click.png", "sprites/ui/panels/gameover/menu_button_click.png");
	menuButton->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x,
		menuButton->getContentSize().height));
	scene->addChild(menuButton, 11);
	auto menuButtonMovingAction = cocos2d::MoveBy::create(1.1F, cocos2d::Vec2(-visibleSize.width, 0));
	menuButton->runAction(menuButtonMovingAction);

	menuButton->addTouchEventListener([=](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			Menu();
		}
	});
}

void LevelCompletionPanel::GoToNextLevel()
{
	if (GamePlayScene::sCurrentLevelIndex == 5)
	{
		// TODO:: Open Introend scene //
	}
	else
	{
		auto newScene = GamePlayScene::createScene(GamePlayScene::sCurrentLevelIndex + 1);
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, newScene));
	}
}

void LevelCompletionPanel::Menu()
{
	auto newScene = MenuScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, newScene));
}