#include "Bar.h"
#include "common/definitionlevels/DefinitionLevel8.h"

// #include "utils/physics/MyBodyParser.h"

Bar::Bar(cocos2d::Scene* scene, const float& travelingDuration, const bool& isOnTheRightSide) : CoreObstacle(travelingDuration, isOnTheRightSide, "Bar")
{
	mCoreSprite = cocos2d::Sprite::create("sprites/gameplay/level8/bar_obstacle.png");
	scene->addChild(mCoreSprite, 1);

	Init();
}

void Bar::Init()
{
	this->SetActive(false);

	/*auto barPhysicsBody = MyBodyParser::getInstance()->bodyFormJson(mCoreSprite, "Bar", cocos2d::PhysicsMaterial(1, 0, 0));
	barPhysicsBody->setDynamic(false);
	barPhysicsBody->setCollisionBitmask(0x02);
	barPhysicsBody->setContactTestBitmask(true);
	mCoreSprite->setPhysicsBody(barPhysicsBody);*/
}

void Bar::Update()
{
	// Update //
}

void Bar::StartTraveling()
{
	CoreObstacle::StartTraveling();

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// Set the starting position //
	if (mIsOnTheRightSide)
		this->SetPosition(origin.x + visibleSize.width / 2 + 100, visibleSize.height + 100);
	else
		this->SetPosition(origin.x + visibleSize.width / 2 - 100, visibleSize.height + 100);

	// Traveling action //
	auto barObstacleTravelingAction = cocos2d::MoveTo::create(mTravelingDuration * visibleSize.height * OBSTACLES_MOVING_TIME_MULTIPLIER, 
		cocos2d::Vec2(this->GetPositionX(), -100));

	// Callback for setting back to inactive //
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		this->SetActive(false);
	});

	mCoreSprite->runAction(cocos2d::Sequence::create(barObstacleTravelingAction, callbackFinishedTraveling, nullptr));
}