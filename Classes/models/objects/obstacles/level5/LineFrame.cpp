#include "LineFrame.h"

LineFrame::LineFrame(cocos2d::Scene* scene, std::string name, std::string lineNamePath) : CoreModel(name)
{
	mCoreSprite = cocos2d::Sprite::create(lineNamePath);
	SetPhysicsBody(0);
	SetActive(false);
	scene->addChild(mCoreSprite, -1);

	mCoreSprite->setTag(OBSTACLES_TAG);

	mSpeed = LINE_FRAME_MOVING_SPEED_EASY;
}

LineFrame::~LineFrame()
{
	// Destructor
}

void LineFrame::setMovingSpeed(int speed)
{
	mSpeed = speed;
}

void LineFrame::setTexture(std::string linenamepath)
{
	mCoreSprite->setTexture(linenamepath);
}

void LineFrame::SetPhysicsBody(int indexPath)
{ 
	char jsonPath[50];
	char name[15];
	sprintf(jsonPath, "sprites/gameplay/level5/line/line_frame_%d.json", indexPath);
	sprintf(name, "line_frame_%d", indexPath);

	CustomPhysicsBody::getInstance()->clearCache();
	CustomPhysicsBody::getInstance()->parseJsonFile(jsonPath);
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
	SetActive(true);
}

void LineFrame::Update()
{
	if (IsActive())
	{
		SetPosition(cocos2d::Vec2(GetPositionX(), GetPositionY() - mSpeed));
	}

	if (GetPositionY() <= -SREEEN_RESOLUTION_HEIGHT)
	{
	SetActive(false);
	}
}