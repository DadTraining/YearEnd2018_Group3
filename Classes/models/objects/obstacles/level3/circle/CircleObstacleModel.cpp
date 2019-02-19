#include "../circleline/CircleLineModel.h"
#include "CircleObstacleModel.h"
#include "../../../../../utils/physics/CustomPhysicsBody.h"
#include "../../../../../common/definitionlevels/DefinitionLevel3.h"

CircleObstacleModel::CircleObstacleModel(const std::string& name, cocos2d::Sprite* sprite) : CoreModel(name)
{
    Init();
    sprite->addChild(mCoreSprite);
}

CircleObstacleModel::CircleObstacleModel(const std::string& name, cocos2d::Node* node) : CoreModel(name)
{
    Init();
    node->addChild(mCoreSprite);
}

CircleObstacleModel::~CircleObstacleModel()
{
    // Destructor
}

void CircleObstacleModel::Init()
{
    mCoreSprite = cocos2d::Sprite::create(mModelName);

    CustomPhysicsBody::getInstance()->parseJsonFile(CIRCLE_OBSTACLE_PHYSICS_JSON);
    auto spriteBody = CustomPhysicsBody::getInstance()->bodyFormJson(mCoreSprite, CIRCLE_OBSTACLE_PHYSICS_NAME,
                                                                     cocos2d::PhysicsMaterial( 1, 1, 0 ));

    if (spriteBody != nullptr)
    {
        spriteBody->setDynamic(false);
        mCoreSprite->setPhysicsBody(spriteBody);
    }
}

void CircleObstacleModel::Update()
{

}
