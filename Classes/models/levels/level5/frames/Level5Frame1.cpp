#include "Level5Frame1.h"
#include "models/objects/orther/line/Line.h"

Level5Frame1::Level5Frame1(cocos2d::Scene *scene) : CoreLevelFrame()
{	
	/*mGroupNode = cocos2d::Node::create();
	CoreModel* lineFrame0 = new Line(mGroupNode, "line_frame_0");
	mObjectsDictionary[lineFrame0->GetModelName()] = lineFrame0;
    scene->addChild(mGroupNode);*/
}

Level5Frame1::~Level5Frame1()
{
	// Destructor
}

void Level5Frame1::Init()
{
	// Initalization
}

void Level5Frame1::Update()
{
    mGroupNode->setPosition(mGroupNode->getPosition().x, mGroupNode->getPosition().y - 1);
    if (mGroupNode->getPositionY() < -cocos2d::Director::getInstance()->getVisibleSize().height)
    {
        mHasFinishMoving = true;
    }

    mFrameCount++;
    if (mFrameCount == 180) //FPS * 3
    {
		
    }
}

bool Level5Frame1::HasFinishedMoving()
{
    return mHasFinishMoving;
}