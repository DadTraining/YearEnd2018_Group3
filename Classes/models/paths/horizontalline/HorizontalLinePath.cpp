#include "HorizontalLinePath.h" 

HorizontalLinePath::HorizontalLinePath(cocos2d::Scene* scene, 
	const std::string& pathNamePath, const std::string& balloonNamePath,
	const float& pathPositionY, const float& ballooonMovingSpeed) : CorePath(pathPositionY, ballooonMovingSpeed)
{
	mPathSprite = cocos2d::Sprite::create(pathNamePath);
	mPathSprite->setPosition(cocos2d::Vec2(SREEEN_RESOLUTION_WIDTH / 2, mPathPositionY));
	mBalloonSprite = cocos2d::Sprite::create(balloonNamePath);
	mBalloonSprite->setPosition(cocos2d::Vec2(SREEEN_RESOLUTION_WIDTH / 2, mPathSprite->getPositionY()));
	scene->addChild(mPathSprite);
	scene->addChild(mBalloonSprite);

	auto listenner = cocos2d::EventListenerTouchOneByOne::create();
	listenner->setSwallowTouches(true);
	listenner->onTouchBegan = CC_CALLBACK_2(HorizontalLinePath::OnTouchBegan, this);
	listenner->onTouchEnded = CC_CALLBACK_2(HorizontalLinePath::OnTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenner, scene);
}

HorizontalLinePath::~HorizontalLinePath()
{
	// destructor
}

void HorizontalLinePath::Update()
{
	if (mIsTouching)
	{
		cocos2d::log("sprite %f", mBalloonSprite->getPositionX());
		if (mIsTouchingRight)
		{
			mBalloonSprite->setPositionX(mBalloonSprite->getPositionX() + mBalloonMovingSpeed);
			if (mBalloonSprite->getPositionX() > 
				(SREEEN_RESOLUTION_WIDTH - mBalloonSprite->getContentSize().width / 2))
			{
				mBalloonSprite->setPositionX(
					SREEEN_RESOLUTION_WIDTH - mBalloonSprite->getContentSize().width / 2);
			}
		}
		else
		{
			mBalloonSprite->setPositionX(mBalloonSprite->getPositionX() - mBalloonMovingSpeed);

			if (mBalloonSprite->getPositionX() < mBalloonSprite->getContentSize().width / 2)
			{
				mBalloonSprite->setPositionX(mBalloonSprite->getContentSize().width / 2);
			}
		}
	}

}

bool HorizontalLinePath::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	mIsTouching = true;
	if (touch->getLocation().x > SREEEN_RESOLUTION_WIDTH / 2)
	{
		mIsTouchingRight = true;
	}
	else
	{
		mIsTouchingRight = false;
	}
	return true;
}

void HorizontalLinePath::OnTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	mIsTouching = false;
}