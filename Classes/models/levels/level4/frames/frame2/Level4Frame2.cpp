#include "Level4Frame2.h"
#include "common/definitionlevels/DefinitionLevel4.h"

Level4Frame2::Level4Frame2(cocos2d::Scene *scene) : CoreLevelFrame()
{
    mPositionY = cocos2d::Director::getInstance()->getVisibleSize().height / 3;

    Init();

    scene->addChild(mGroupNode);
}

Level4Frame2::~Level4Frame2()
{
    // Destructor
}

void Level4Frame2::Init()
{
    mGroupNode = cocos2d::Node::create();
    mGroupNode->setContentSize(cocos2d::Director::getInstance()->getVisibleSize());
    mGroupNode->setAnchorPoint(cocos2d::Vec2(0, 0));

    // Initialize LineObstacle
    mLineObstacleModel = new LineObstacleModel(mGroupNode);
    mLineObstacleModel->Rotate();
    mLineObstacleModel->SetPosition(cocos2d::Director::getInstance()->getVisibleSize().width / 2,
            mLineObstacleModel->GetContentSize().height / 2 + 96);

    // Initialize CircleLineObstacle
    mCircleLineObstacle = new CircleLineObstacle(mGroupNode);
    mCircleLineObstacle->SetPosition(cocos2d::Director::getInstance()->getVisibleSize().width / 2,
            cocos2d::Director::getInstance()->getVisibleSize().height - mCircleLineObstacle->GetContentSize().height / 2 + 64);
}

void Level4Frame2::Update()
{
    mCircleLineObstacle->Update();

    mGroupNode->setPositionY(mGroupNode->getPositionY() - LEVEL_SPEED);

    if (mGroupNode->getPositionY()  <= - cocos2d::Director::getInstance()->getVisibleSize().height - 100)
    {
        mHasFinishMoving = true;
    }else
    {
        mHasFinishMoving = false;
    }
}

bool Level4Frame2::HasFinishedMoving()
{
    return mHasFinishMoving;
}