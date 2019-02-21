#include "CircleLineModel.h"
#include "common/definitionlevels/DefinitionLevel3.h"

CircleLineModel::CircleLineModel(cocos2d::Node* node) : CoreModel("sprites/gameplay/level3/circle/circle_line.png")
{
    Init();

    node->addChild(mCoreSprite);
    node->addChild(mNodeCoin);
}

CircleLineModel::~CircleLineModel()
{
    // Destructor
}

void CircleLineModel::Init()
{
    // Create circle line //
    mCoreSprite = cocos2d::Sprite::create(mModelName);

    // Init vector Circle obstacle model
    InitCircleObstacleModels(mCoreSprite);

    // Init position item of vector Circle obstacle model
    InitPositionCircleObstacleModels();

    // Create coin //
    mNodeCoin = cocos2d::Node::create();
    mNodeCoin->setContentSize(GetContentSize());
    mNodeCoin->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));

    // Init vector coin models
    InitCoinModels();

    // Init position coin models
    InitPositionCoinModels();

}

void CircleLineModel::Update()
{
<<<<<<< HEAD
    mCoreSprite->setRotation(mCoreSprite->getRotation() + 1);
=======
    mCoreSprite->setRotation(mCoreSprite->getRotation() + 0.5);
>>>>>>> + Create level3
    mNodeCoin->setPosition(GetPosition());
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

void CircleLineModel::InitCoinModels()
{
    for (int i = 0; i < COIN_MODELS_SIZE; i++)
    {
        mCoinModels.push_back(new CoinModel(mNodeCoin));
    }
}

void CircleLineModel::InitPositionCoinModels()
{
    float radius = GetContentSize().width / 3;
    float compensationRadius = GetContentSize().width / 2 - radius;
    float corner = 0;

    for (int i = 0; i < COIN_MODELS_SIZE; i++)
    {
        mCoinModels.at(i)->SetPosition((radius + compensationRadius) + cos(corner * M_PI / 180.0F) * radius,
                                       (radius + compensationRadius) + sin(corner * M_PI / 180.0F) * radius);
        corner += 360 / COIN_MODELS_SIZE;
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> + Create level3
