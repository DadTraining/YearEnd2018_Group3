#include "Level4Frame1.h"
#include "common/definitionlevels/DefinitionLevel4.h"

Level4Frame1::Level4Frame1(cocos2d::Scene *scene) : CoreLevelFrame()
{
    Init();

    scene->addChild(mGroupNode);
}

Level4Frame1::~Level4Frame1()
{
    // Destructor
}

void Level4Frame1::Init()
{
    // Initialize local variable
    mPosY = 0;
    mIndexRectangleObstacle = 0;

    mGroupNode = cocos2d::Node::create();

    for (int i = 0; i < LEVEL4_FRAME1_RECTANGLE_OBSTACLE_SIZE; i++)
    {
        mRectangleObstacleModels.push_back(new RectangleObstacleModel(mGroupNode));
        mRectangleObstacleModels.at(i)->SetActive(false);
    }

    while (mPosY < cocos2d::Director::getInstance()->getVisibleSize().height)
    {
        RandomRectangle();
    }
}

void Level4Frame1::Update()
{
    mGroupNode->setPositionY(mGroupNode->getPositionY() - LEVEL_SPEED);

    if (mGroupNode->getPositionY()  <= - cocos2d::Director::getInstance()->getVisibleSize().height - 100)
    {
        mHasFinishMoving = true;
    }else
    {
        mHasFinishMoving = false;
    }
}

bool Level4Frame1::HasFinishedMoving()
{
    return mHasFinishMoving;
}

void Level4Frame1::RandomRectangle()
{
    int randCountRec = cocos2d::RandomHelper::random_int(1, 3);
    auto obstacleSize = mRectangleObstacleModels.at(0)->GetContentSize();
    mIndexRectangleObstacle++;
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    mPosY = mPosY + 80 + obstacleSize.height;

    if (randCountRec == 1)
    {
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
    }else if (randCountRec == 2)
    {
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2 - obstacleSize.width / 2 - obstacleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
        mIndexRectangleObstacle++;
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2 + obstacleSize.width / 2 + obstacleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
    }else
    {
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2 - 90 - obstacleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
        mIndexRectangleObstacle++;
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
        mIndexRectangleObstacle++;
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetPosition(visibleSize.width / 2 + 90 + obstacleSize.width / 2, mPosY);
        mRectangleObstacleModels.at(mIndexRectangleObstacle)->SetActive(true);
    }
}