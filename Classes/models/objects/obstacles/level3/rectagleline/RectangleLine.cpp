#include "RectangleLine.h"
#include "common/definitionlevels/DefinitionLevel3.h"

RectangleLine::RectangleLine(cocos2d::Scene *scene) : CoreModel(RECTANGLE_LINE_PATH_NAME_PATH)
{
    Init();
    scene->addChild(mCoreSprite);
}

RectangleLine::RectangleLine(cocos2d::Node *node) : CoreModel(RECTANGLE_LINE_PATH_NAME_PATH)
{
    Init();
    node->addChild(mCoreSprite);
}

RectangleLine::~RectangleLine()
{
    // Destructor
}

void RectangleLine::Init()
{
    mCoreSprite = cocos2d::Sprite::create(mModelName);

    // Init vector rectangle
    InitRectangleObstacleModels();
    InitPossitionRectangleModels();
}

void RectangleLine::Update()
{

}

void RectangleLine::InitRectangleObstacleModels()
{
    for (int i = 0; i < RECTANGLE_OBSTACLE_MODELS_SIZE; i++)
    {
        mRectangleObstacleModels.push_back(new RectangleObstacleModel(mCoreSprite));
    }
}

void RectangleLine::InitPossitionRectangleModels()
{

}
