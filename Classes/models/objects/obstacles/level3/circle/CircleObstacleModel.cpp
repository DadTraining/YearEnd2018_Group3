#include "CircleObstacleModel.h"
#include "utils/physics/PhysicsShapeCache.h"

CircleObstacleModel::CircleObstacleModel(const std::string& name, cocos2d::Sprite* sprite) : CoreModel(name)
{
    mCoreSprite = cocos2d::Sprite::create(name);

    //auto physicsCache = PhysicsShapeCache::getInstance();
    //physicsCache->addShapesWithFile("sprites/gameplay/level3/circle/circle.plist");
    //physicsCache->setBodyOnSprite("circle", mCoreSprite);
    //mCoreSprite->getPhysicsBody()->setDynamic(false);

    sprite->addChild(mCoreSprite);
}

CircleObstacleModel::~CircleObstacleModel()
{
    // Destructor
}

void CircleObstacleModel::Init()
{

}

void CircleObstacleModel::Update()
{

}
