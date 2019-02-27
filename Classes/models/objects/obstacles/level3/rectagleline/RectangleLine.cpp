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
    // Init Sprite
    mCoreSprite = cocos2d::Sprite::create(mModelName);

    // Init Coin
    mCoin = new CoinModel(mCoreSprite);
    mCoin->SetPosition(GetContentSize().width / 2, GetContentSize().height / 2);

    // Init vector rectangle
    InitTriangleObstacleModels();
    InitPositionTriangleModels();
}

void RectangleLine::Update()
{
	for (int i = 0; i < mTriangularObstacleModels.size(); i++)
    {
	    mTriangularObstacleModels.at(i)->Update();
    }
}

void RectangleLine::InitTriangleObstacleModels()
{
    for (int i = 0; i < RECTANGLE_OBSTACLE_MODELS_SIZE; i++)
    {
        mTriangularObstacleModels.push_back(new TriangularObstacleModel(mCoreSprite, TriangularObstacleModel::MOVE_VERTICAL));
    }
}

void RectangleLine::InitPositionTriangleModels()
{
    mTriangularObstacleModels.at(0)->SetPosition(GetContentSize().width / 4, GetContentSize().height);
    mTriangularObstacleModels.at(0)->SetRotation(180);

    mTriangularObstacleModels.at(1)->SetPosition(GetContentSize().width / 4 * 3, GetContentSize().height);
    mTriangularObstacleModels.at(1)->SetRotation(180);

    mTriangularObstacleModels.at(2)->SetPosition(GetContentSize().width, 0);
    mTriangularObstacleModels.at(3)->SetPosition(GetContentSize().width / 2, 0);
}
