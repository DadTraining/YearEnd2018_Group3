#include "VerticalLinePath.h"
#include "common/Definition.h"

VerticalLinePath::VerticalLinePath(cocos2d::Scene* scene, const float& distanceBetweenBaloonAndThePath,
	const float& pathMovingSpeed, const float& thresholdMovingDistance,
	const std::string& balloonNamePath, const std::string& pathNamePath,
	const float& pathPositionY) : CorePath(pathPositionY, 0)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// Set local data // 
	mIsMovingDown = true;
	mCenterPositionX = origin.x + visibleSize.width / 2;

	/* Change variables here to fit your needs */
	mDistanceBetweenBaloonAndThePath = distanceBetweenBaloonAndThePath;
	mPathMovingSpeed = pathMovingSpeed;
	mThresholdMovingDistance = thresholdMovingDistance;
	/*******************************************/

	// The line path sprite //
	mPathSprite = cocos2d::Sprite::create(pathNamePath);
	mPathSprite->setPosition(mCenterPositionX, mPathPositionY);
	scene->addChild(mPathSprite, 1);

	// The balloon sprite //
	mBalloonSprite = cocos2d::Sprite::create(balloonNamePath);
	mBalloonSprite->setPosition(mPathSprite->getContentSize().width / 2 + mDistanceBetweenBaloonAndThePath,
		mPathSprite->getContentSize().height / 2);
	mPathSprite->addChild(mBalloonSprite, 2);

	// Called automatically when users manipulate the screen for the balloon's movement //
	auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(VerticalLinePath::OnTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(VerticalLinePath::OnTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, scene);
}

bool VerticalLinePath::OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	mIsTouching = true;

	if (touch->getLocation().x >= SREEEN_RESOLUTION_WIDTH / 2)
		mIsTouchingRight = true;
	else
		mIsTouchingRight = false;

	return true;
}

void VerticalLinePath::OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	mIsTouching = false;
}

void VerticalLinePath::Update()
{
	// The screen touching controller
	if (mIsTouching)
	{
		if (mIsTouchingRight)
		{
			mBalloonSprite->setPosition(mPathSprite->getContentSize().width / 2 + mDistanceBetweenBaloonAndThePath,
				mPathSprite->getContentSize().height / 2);
		}
		else
		{
			mBalloonSprite->setPosition(mPathSprite->getContentSize().width / 2 - mDistanceBetweenBaloonAndThePath,
				mPathSprite->getContentSize().height / 2);
		}
	}

	// The line path's movement //
	if (mIsMovingDown)
	{
		mPathSprite->setPosition(mPathSprite->getPosition().x,
			mPathSprite->getPosition().y - mPathMovingSpeed);

		if (mPathSprite->getPosition().y <= mPathPositionY - mThresholdMovingDistance)
		{
			mIsMovingDown = false;
		}
	}
	else
	{
		mPathSprite->setPosition(mPathSprite->getPosition().x,
			mPathSprite->getPosition().y + mPathMovingSpeed);

		if (mPathSprite->getPosition().y >= mPathPositionY + mThresholdMovingDistance)
		{
			mIsMovingDown = true;
		}
	}
}