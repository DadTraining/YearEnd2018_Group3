#include "Level3Frame1.h"
#include "common/definitionlevels/DefinitionLevel3.h"

Level3Frame1::Level3Frame1(cocos2d::Scene* scene) : CoreLevelFrame()
{
    Init();
    scene->addChild(mGroupNode);
}

Level3Frame1::~Level3Frame1()
{

}

void Level3Frame1::Init()
{
    mGroupNode = cocos2d::Node::create();
    mGroupNode->setContentSize(cocos2d::Director::getInstance()->getVisibleSize());
    mGroupNode->setPositionY(cocos2d::Director::getInstance()->getVisibleSize().height);

    InitHorizontalLines();
}

void Level3Frame1::Update()
{
	mGroupNode->setPositionY(mGroupNode->getPositionY() - 1);

    for (int i = 0; i < HORIZONTAL_LINE_SIZE; i++)
    {
        mHorizontalLines.at(i)->Update();
    }

	if (mGroupNode->getPositionY() < -cocos2d::Director::getInstance()->getVisibleSize().height)
	{
		mHasFinishMoving = true;
	}
}

bool Level3Frame1::HasFinishedMoving()
{
    return mHasFinishMoving;
}

void Level3Frame1::InitHorizontalLines()
{
    for (int i = 0; i < HORIZONTAL_LINE_SIZE; i++)
    {
		int rand = cocos2d::RandomHelper::random_int(0, 10);
		if (rand % 2 == 0)
		{
			mHorizontalLines.push_back(new HorizontalLine(mGroupNode, HorizontalLine::MODE_TRIANGULAR));
		}
		else if (rand % 2 != 0)
		{
			mHorizontalLines.push_back(new HorizontalLine(mGroupNode, HorizontalLine::MODE_CIRCLE));
		}
    }

    // Set position of line //
    int positionY = 64; // position y of horizontal line

    for (int i =0; i < HORIZONTAL_LINE_SIZE; i++)
    {
        mHorizontalLines.at(i)->SetPosition(mGroupNode->getContentSize().width / 2,  positionY);
        positionY += 192;
    }
}
