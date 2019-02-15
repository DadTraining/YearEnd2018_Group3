#include "RectagleModel.h"
#include "common/definitionlevels/DefinitionLevel3.h"

RectagleModel::RectagleModel(cocos2d::Scene *scene) : CoreModel(RECTAGLE_NAME_PATH)
{
    Init();
    scene->addChild(mCoreSprite);
}

RectagleModel::RectagleModel(cocos2d::Node *node) : CoreModel(RECTAGLE_NAME_PATH)
{
    Init();
    node->addChild(mCoreSprite);
}

RectagleModel::~RectagleModel()
{

}

void RectagleModel::Init()
{
    mCoreSprite = cocos2d::Sprite::create(RECTAGLE_NAME_PATH);
}

void RectagleModel::Update()
{

}
