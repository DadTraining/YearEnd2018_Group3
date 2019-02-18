#include "Line.h"
#include "common/Definition.h"

Line::Line(cocos2d::Scene* scene, std::string name, std::string lineNamePath) : CoreModel(name)
{
    mCoreSprite = cocos2d::Sprite::create(lineNamePath);
	SetActive(false);
	mCoreSprite->setAnchorPoint(cocos2d::Vec2(0.5, 1));
	scene->addChild(mCoreSprite);
}

Line::~Line()
{
	// Destructor
}

void Line::setTexture(std::string linenamepath)
{
	mCoreSprite->setTexture(linenamepath);
}

void Line::Init()
{
	SetActive(true);
}

void Line::Update()
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