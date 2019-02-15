#include "Level3Frame1.h"

Level3Frame1::Level3Frame1(cocos2d::Scene* scene) : CoreLevelFrame()
{
    mGroupNode = cocos2d::Node::create();
    mGroupNode->setContentSize(cocos2d::Director::getInstance()->getVisibleSize());

    mCircleLine = new CircleLineModel(mGroupNode);
    mCircleLine->SetPosition(mGroupNode->getContentSize().width * 0.5, mGroupNode->getContentSize().height * 0.5);

    scene->addChild(mGroupNode);
}

Level3Frame1::~Level3Frame1()
{

}

void Level3Frame1::Init()
{

}

void Level3Frame1::Update()
{
    mCircleLine->Update();

    mGroupNode->setPosition(mGroupNode->getPosition().x, mGroupNode->getPosition().y - 1);
    if (mGroupNode->getPositionY() < -cocos2d::Director::getInstance()->getVisibleSize().height)
    {
        mHasFinishMoving = true;
    }
}

bool Level3Frame1::HasFinishedMoving()
{
    return mHasFinishMoving;
}
