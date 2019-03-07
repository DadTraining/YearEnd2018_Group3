#include "LineFrame.h"

LineFrame::LineFrame(cocos2d::Scene* scene, std::string name) : CoreModel(name)
{
	mSpeed = LINE_FRAME_MOVING_SPEED_EASY;
	mCoreSprite = cocos2d::Sprite::create(name);
	
	mCorePhysicsBody = nullptr;
	SetPhysicsBody(0);

	SetActive(false);
	scene->addChild(mCoreSprite, -1);

	mCoreSprite->setTag(OBSTACLES_TAG);
}

LineFrame::~LineFrame()
{
	// Destructor
}

void LineFrame::LerpColor(cocos2d::Color3B color)
{
	cocos2d::Action* lerpColorAction = cocos2d::TintTo::create(2,color);
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

	if (mFrameCount > (FPS * EASY_MODE))
	{
		mSpeed = LINE_FRAME_MOVING_SPEED_NORMAL;
	}
	if (mFrameCount > (FPS * NORMAL_MODE))
	{
		mSpeed = LINE_FRAME_MOVING_SPEED_HARD;
	}
}