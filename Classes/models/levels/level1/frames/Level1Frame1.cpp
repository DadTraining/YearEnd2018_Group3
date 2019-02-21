#include "Level1Frame1.h"
#include "models/objects/obstacles/RectagleBarrier.h"

Level1Frame1::Level1Frame1(cocos2d::Scene *scene) : CoreLevelFrame() 
{
    CoreModel* c = new RectagleBarrier(mGroupNode, "rec1");
    mObjectsDictionary[c->GetModelName()] = c;

    CoreModel* c2 = new RectagleBarrier(mGroupNode, "rec2");
    mObjectsDictionary[c2->GetModelName()] = c2;

    scene->addChild(mGroupNode);
}

Level1Frame1::~Level1Frame1() 
{
	// Destructor
}

void Level1Frame1::Init() 
{
	// Initalization
}

void Level1Frame1::Update()
{
    CoreLevelFrame::Update();

    mGroupNode->setPosition(mGroupNode->getPosition().x, mGroupNode->getPosition().y - 1);
    if (mGroupNode->getPositionY() < -cocos2d::Director::getInstance()->getVisibleSize().height / 2)
    {
        mHasFinishMoving = true;
    }

    mFrameCount++;
    if (mFrameCount == 180) //FPS * 3
    {
        mObjectsDictionary["rec1"]->SetRotation(1);
    }
}

bool Level1Frame1::HasFinishedMoving() 
{
    return mHasFinishMoving;
}
