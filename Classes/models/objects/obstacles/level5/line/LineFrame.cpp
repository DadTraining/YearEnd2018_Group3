#include "LineFrame.h"
#include "common/Definition.h"

LineFrame::LineFrame(cocos2d::Scene* scene, std::string name, std::string lineNamePath) : CoreModel(name)
{
    mCoreSprite = cocos2d::Sprite::create(lineNamePath);
	SetActive(false);
	mCoreSprite->setAnchorPoint(cocos2d::Vec2(0.5, 1));
	scene->addChild(mCoreSprite);
}

LineFrame::~LineFrame()
{
	// Destructor
}

void LineFrame::setTexture(std::string linenamepath)
{
	mCoreSprite->setTexture(linenamepath);
}

void LineFrame::Init()
{
	SetActive(true);
}

void LineFrame::Update()
{
	if (IsActive())
	{
		SetPosition(cocos2d::Vec2(GetPositionX(), GetPositionY() - 3));
	}
	
	if (GetPositionY() <= -100)
	{
		SetActive(false);
	}
}