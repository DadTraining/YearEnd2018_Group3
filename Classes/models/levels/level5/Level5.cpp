#include "Level5.h"

enum Mode
{
	EASY,
	NORMAL,
	HARD
};

Level5::Level5(cocos2d::Scene *scene)
{
	mMode = EASY;
	mFrameCount = 0;
	mIndexPath = cocos2d::random(1, 4);

	auto backgroundSprite = cocos2d::Sprite::create("sprites/gameplay/level5/background.png");
	backgroundSprite->setPosition(backgroundSprite->getContentSize().width / 2, SREEEN_RESOLUTION_HEIGHT / 2);
	scene->addChild(backgroundSprite, -1);

	mHorizontalLinePath = new HorizontalLinePath(scene, "sprites/gameplay/paths/horizontal_line_path.png",
		"sprites/gameplay/balloon/balloon.png", 100, BALLOON_MOVING_SPEED);

	mFirstLine = new LineFrame(scene, "first_line_frame", "sprites/gameplay/level5/line/line_frame_0.png");
	mFirstLine->Init();
	mFirstLine->SetPhysicsBody(0);
	mFirstLine->SetPosition(cocos2d::Vec2(mFirstLine->GetContentSize().width / 2, SREEEN_RESOLUTION_HEIGHT / 2));

	mSecondLine = new LineFrame(scene, "second_line_frame", GetLineFramePath());
	mSecondLine->Init();
	mSecondLine->SetPhysicsBody(mIndexPath);
	mSecondLine->SetPosition(cocos2d::Vec2(mFirstLine->GetPositionX(),
		mFirstLine->GetPositionY() + SREEEN_RESOLUTION_HEIGHT));

	mThirdLine = new LineFrame(scene, "third_line_frame", GetLineFramePath());
	mThirdLine->Init();
	mThirdLine->SetPhysicsBody(mIndexPath);
	mThirdLine->SetPosition(cocos2d::Vec2(mSecondLine->GetPositionX(),
		mSecondLine->GetPositionY() + SREEEN_RESOLUTION_HEIGHT));

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Level5::OnContactBegin, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, scene);
}

Level5::~Level5()
{

}

void Level5::MoveLine()
{
	mFrameCount++;

	if (mFrameCount % FPS == 0)
	{
		if (!mFirstLine->IsActive())
		{
			mFirstLine->setTexture(GetLineFramePath());
			mFirstLine->Init();
			mFirstLine->SetPhysicsBody(mIndexPath);
			mFirstLine->SetPosition(mThirdLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
		if (!mSecondLine->IsActive())
		{
			mSecondLine->setTexture(GetLineFramePath());
			mSecondLine->Init();
			mSecondLine->SetPhysicsBody(mIndexPath);
			mSecondLine->SetPosition(mFirstLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
		if (!mThirdLine->IsActive())
		{
			mThirdLine->setTexture(GetLineFramePath());
			mThirdLine->Init();
			mThirdLine->SetPhysicsBody(mIndexPath);
			mThirdLine->SetPosition(mSecondLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
	}
}

std::string Level5::GetLineFramePath()
{
	char linePath[50];
	sprintf(linePath, "sprites/gameplay/level5/line/line_frame_%d.png", mIndexPath);

	return linePath;
}

bool Level5::OnContactBegin(cocos2d::PhysicsContact & contact)
{
	auto shapeA = contact.getShapeA()->getBody()->getNode();
	auto shapeB = contact.getShapeB()->getBody()->getNode();

	if ((shapeA->getTag() == BALLOON_TAG && shapeB->getTag() == OBSTACLES_TAG) ||
		(shapeB->getTag() == BALLOON_TAG && shapeA->getTag() == OBSTACLES_TAG))
	{
		auto BalloonExplosion = cocos2d::ParticleSystemQuad::create("sprites/gameplay/balloon/balloon_explosion.plist");
		if (shapeA->getTag() == BALLOON_TAG)
		{
			shapeA->addChild(BalloonExplosion, 1000);
			BalloonExplosion->setPosition(0, 0);

			shapeA->setOpacity(0);
			shapeA->removeComponent(shapeA->getPhysicsBody());

			mIsGameOver = true;
		}
		else
		{
			shapeB->addChild(BalloonExplosion, 1000);
			BalloonExplosion->setPosition(0, 0);

			shapeB->setOpacity(0);
			shapeB->removeComponent(shapeB->getPhysicsBody());

			mIsGameOver = true;
		}
	}

	return true;
}

void Level5::Init()
{

}

void Level5::Update()
{
	mHorizontalLinePath->Update();
	MoveLine();
	mFirstLine->Update();
	mSecondLine->Update();
	mThirdLine->Update();

	// change mode //
	if (mFrameCount > FPS * EASY_MODE)
	{
		mMode = NORMAL;
	}
	if (mFrameCount > FPS * NORMAL_MODE)
	{
		mMode = HARD;
	}
	if (mFrameCount > FPS * HARD_MODE)
	{
		mFrameCount = 0;

		mMode = EASY;
	}
	if (mFrameCount > FPS * COMPLETE_LEVEL)
	{
		mIsCompletedLevel = true;
	}
	// change speed during speed change //
	if (mMode == EASY)
	{
		mIndexPath = cocos2d::random(1, 10);

		int speed = cocos2d::random(LINE_FRAME_MOVING_SPEED_EASY, LINE_FRAME_MOVING_SPEED_HARD);

		mHorizontalLinePath->setBalloonMovingSpeed(speed);

		mFirstLine->setMovingSpeed(speed);
		mSecondLine->setMovingSpeed(speed);
		mThirdLine->setMovingSpeed(speed);
	}
	else if (mMode == NORMAL)
	{
		mIndexPath = cocos2d::random(11, 16);

		mHorizontalLinePath->setBalloonMovingSpeed(BALLOON_MOVING_SPEED_NORMAL);

		mFirstLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_NORMAL);
		mSecondLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_NORMAL);
		mThirdLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_NORMAL);
	}
	else
	{
		mIndexPath = cocos2d::random(17, MAX_IMAGE_INDEX);

		mHorizontalLinePath->setBalloonMovingSpeed(BALLOON_MOVING_SPEED_HARD);

		mFirstLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_HARD);
		mSecondLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_HARD);
		mThirdLine->setMovingSpeed(LINE_FRAME_MOVING_SPEED_HARD);
	}
}

void Level5::LerpColor()
{
	//cocos2d::Action* lerpColorAction = cocos2d::TintTo::create(2, mListOfColors.at(mCurrentColorIndex));
	//mLineBackground->runAction(lerpColorAction);
	//mFrameCount++;

	//if (mFrameCount % (FPS * 5) == 0)
	//{
	//	mCurrentColorIndex++;

	//	if (mCurrentColorIndex >= mListOfColors.size())
	//		mCurrentColorIndex = 0;

	//	//LerpColor();
	//}


	//// Edit here //  

	//mCurrentColorIndex = 0;

	//mListOfColors.push_back(cocos2d::Color3B(cocos2d::Color3B::RED));
	//mListOfColors.push_back(cocos2d::Color3B(cocos2d::Color3B::GREEN));
	//mListOfColors.push_back(cocos2d::Color3B(cocos2d::Color3B::BLUE));
	//mListOfColors.push_back(cocos2d::Color3B(cocos2d::Color3B::WHITE));

	//mLineBackground = cocos2d::Sprite::create("sprites/gameplay/level5/line/line_frame_0.png");
	//mLineBackground->setAnchorPoint(cocos2d::Vec2(0, 0));
	////this->addChild(mLineBackground);
	//mLineBackground->setColor(mListOfColors[mCurrentColorIndex]);

	int mFrameCount;

	// Edit here //
	std::vector<cocos2d::Color3B> mListOfColors;
	cocos2d::Sprite* mLineBackground;
	int mCurrentColorIndex;
	//////////////////////////////////////////////////////////////////// 

}
