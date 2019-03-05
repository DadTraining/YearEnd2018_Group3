#include "LineFrame.h"

LineFrame::LineFrame(cocos2d::Scene* scene, std::string name) : CoreModel(name)
{
	mCurrentColorIndex = 0;
	mSpeed = LINE_FRAME_MOVING_SPEED_EASY;

	mCoreSprite = cocos2d::Sprite::create(name);
	
	mCorePhysicsBody = nullptr;
	SetPhysicsBody(0);

	SetActive(false);
	scene->addChild(mCoreSprite, -1);

	mCoreSprite->setTag(OBSTACLES_TAG);

	/* generate color */
	mListOfColors.push_back(cocos2d::Color3B(213, 0, 0)); // Red
	mListOfColors.push_back(cocos2d::Color3B(197, 17, 98)); // Pink
	mListOfColors.push_back(cocos2d::Color3B(170, 0, 255)); // Purple
	mListOfColors.push_back(cocos2d::Color3B(41, 98, 255)); // blue
	mListOfColors.push_back(cocos2d::Color3B(48, 79, 254)); // Indigo
	mListOfColors.push_back(cocos2d::Color3B(0, 184, 212)); // Cyan
	mListOfColors.push_back(cocos2d::Color3B(0, 200, 83)); // Green
	mListOfColors.push_back(cocos2d::Color3B(255, 109, 0)); // Orange
	mListOfColors.push_back(cocos2d::Color3B(255, 214, 0)); // Yellow

	mCoreSprite->setColor(mListOfColors[mCurrentColorIndex]);
}

LineFrame::~LineFrame()
{
	// Destructor
}

void LineFrame::LerpColor()
{
	cocos2d::Action* lerpColorAction = cocos2d::TintTo::create(2, mListOfColors.at(mCurrentColorIndex));
	mCoreSprite->runAction(lerpColorAction);
}

void LineFrame::setTexture(std::string linenamepath)
{
	mCoreSprite->setTexture(linenamepath);
}

void LineFrame::SetPhysicsBody(int indexPath)
{ 
	SetActive(true);

	/*get name physics body in json file*/
	char name[15];
	sprintf(name, LINE_FRAME_NAME_FORMAT, indexPath);

	CustomPhysicsBody::getInstance()->clearCache();
	CustomPhysicsBody::getInstance()->parseJsonFile(LINE_FRAME_JSON_PATH);
	mCorePhysicsBody = CustomPhysicsBody::getInstance()->bodyFormJson(mCoreSprite, name, cocos2d::PhysicsMaterial(1, 1, 0));

	if (mCorePhysicsBody != nullptr)
	{
		mCoreSprite->removeComponent(mCorePhysicsBody);
		mCorePhysicsBody->setDynamic(false);
		mCorePhysicsBody->setCollisionBitmask(0x01);
		mCorePhysicsBody->setContactTestBitmask(true);
		mCoreSprite->addComponent(mCorePhysicsBody);
	}
}

void LineFrame::Init()
{
	// Initialize
}

void LineFrame::Update()
{
	mFrameCount++;

	if (IsActive())
	{
		SetPosition(cocos2d::Vec2(GetPositionX(), GetPositionY() - mSpeed));
	}

	if (GetPositionY() <= -GetContentSize().height)
	{
		SetActive(false);
	}

	if (mFrameCount % (FPS * 7) == 0)
	{
		LerpColor();
		mCurrentColorIndex++;

		if (mCurrentColorIndex >= mListOfColors.size())
		{
			mCurrentColorIndex = 0;
		}
	}

	if (mFrameCount > (FPS * EASY_MODE))
	{
		mSpeed = LINE_FRAME_MOVING_SPEED_NORMAL;
	}
	if (mFrameCount > (FPS * NORMAL_MODE))
	{
		mSpeed = LINE_FRAME_MOVING_SPEED_HARD;
	}
}