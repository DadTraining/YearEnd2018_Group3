#include "CoreModel.h"

CoreModel::CoreModel(const std::string& name)
{
    mModelName = name;
    mFrameCount = 0;
}

CoreModel::~CoreModel()
{
    // Destructor
}

cocos2d::Vec2 CoreModel::GetPosition() const
{
    return mCoreSprite->getPosition();
}

float CoreModel::GetPositionX() const
{
    return mCoreSprite->getPositionX();
}

float CoreModel::GetPositionY() const
{
    return mCoreSprite->getPositionY();
}

void CoreModel::SetPosition(const cocos2d::Vec2& position)
{
    mCoreSprite->setPosition(position);
}

void CoreModel::SetPosition(const float& x, const float& y)
{
    mCoreSprite->setPosition(cocos2d::Vec2(x, y));
}

cocos2d::Size CoreModel::GetContentSize() const
{
    return mCoreSprite->getContentSize();
}

float CoreModel::GetWidth() const
{
    return mCoreSprite->getContentSize().width;
}

float CoreModel::GetHeight() const
{
    return mCoreSprite->getContentSize().height;
}

bool CoreModel::IsActive() const
{
    return mIsActive;
}

void CoreModel::SetActive(const bool& active)
{
    mIsActive = active;
    mCoreSprite->setVisible(active); 
	mCorePhysicsBody->setEnabled(active);
}

std::string CoreModel::GetModelName() const
{
    return mModelName;
}

void CoreModel::SetRotation(const float& degree)
{
    mCoreSprite->setRotation(degree);
}
