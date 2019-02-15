#include "CircleLineModel.h"
#include "common/definitionlevels/DefinitionLevel3.h"

CircleLineModel::CircleLineModel(cocos2d::Scene *scene) : CoreModel("sprites/gameplay/level3/circle/circle_line.png")
{
    mCoreSprite = cocos2d::Sprite::create(mModelName);

    // Init vector Circle obstacle model
    InitCircleObstacleModels(mCoreSprite);

    // Init position item of vector Circle obstacle model
    InitPositionCircleObstacleModels();

    scene->addChild(mCoreSprite);
}

CircleLineModel::~CircleLineModel()
{
    // Destructor
}

void CircleLineModel::Init()
{

}

void CircleLineModel::Update()
{
    mCoreSprite->setRotation(mCoreSprite->getRotation() + 1);
}

void CircleLineModel::InitCircleObstacleModels(cocos2d::Sprite* sprite)
{
    for (int i = 0; i < CIRCLE_OBSTACLE_MODELS_SIZE; i ++)
    {
        mCircleObstacleModels.push_back(new CircleObstacleModel(CIRCLE_OBSTACLE_NAME_PATH, sprite));
    }
}

void CircleLineModel::InitPositionCircleObstacleModels()
{
    float radius = GetContentSize().width / 2;
    float corner = 0;

    for (int i = 0; i < CIRCLE_OBSTACLE_MODELS_SIZE; i++)
    {
        mCircleObstacleModels.at(i)->SetPosition(radius + cos(corner * M_PI / 180.0F) * radius,
                radius + sin(corner * M_PI / 180.0F) * radius);
        corner += 360 / CIRCLE_OBSTACLE_MODELS_SIZE;
    }
}
