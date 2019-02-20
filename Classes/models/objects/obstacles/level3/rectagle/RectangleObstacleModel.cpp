#include "RectangleObstacleModel.h"
#include "common/definitionlevels/DefinitionLevel3.h"

RectangleObstacleModel::RectangleObstacleModel(cocos2d::Scene *scene) : CoreModel(RECTAGLE_NAME_PATH)
{
    Init();
    scene->addChild(mCoreSprite);
}

RectangleObstacleModel::RectangleObstacleModel(cocos2d::Node *node) : CoreModel(RECTAGLE_NAME_PATH)
{
    Init();
    node->addChild(mCoreSprite);
}

RectangleObstacleModel::~RectangleObstacleModel()
{

}

void RectangleObstacleModel::Init()
{
    mCoreSprite = cocos2d::Sprite::create(RECTAGLE_LINE_PATH_NAME_PATH);
}

void RectangleObstacleModel::Update()
{

}
