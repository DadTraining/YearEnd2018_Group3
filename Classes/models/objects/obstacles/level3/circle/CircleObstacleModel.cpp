#include "CircleObstacleModel.h"
#include "utils/physics/CustomPhysicsBody.h"
#include "common/definitionlevels/DefinitionLevel3.h"
#include "common/Definition.h"

const int CircleObstacleModel::MODE_NONE = 0;
const int CircleObstacleModel::MODE_MOVE_HORIONTAL = 1;

CircleObstacleModel::CircleObstacleModel(const std::string& name, cocos2d::Sprite* sprite, int mode) : CoreModel(name)
{
	mMode = mode;
    Init();

    sprite->addChild(mCoreSprite);
}

CircleObstacleModel::CircleObstacleModel(const std::string& name, cocos2d::Node* node, int mode) : CoreModel(name)
{
	mMode = mode;
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
    mCoreSprite->setTag(OBSTACLES_TAG);

    CustomPhysicsBody::getInstance()->parseJsonFile(CIRCLE_OBSTACLE_PHYSICS_JSON);
    mCorePhysicsBody = CustomPhysicsBody::getInstance()->bodyFormJson(mCoreSprite, CIRCLE_OBSTACLE_PHYSICS_NAME,
                                                                     cocos2d::PhysicsMaterial( 1, 1, 0 ));

    if (mCorePhysicsBody != nullptr)
    {
        mCorePhysicsBody->setDynamic(false);
        mCorePhysicsBody->setCategoryBitmask(OBSTACLES_COLLISION_BITMASK);
        mCorePhysicsBody->setContactTestBitmask(true);

        mCoreSprite->setPhysicsBody(mCorePhysicsBody);
    }
}

void CircleObstacleModel::Update()
{
	if (mMode == MODE_MOVE_HORIONTAL && IsActive())
	{
		SetPosition(cocos2d::Vec2(GetPositionX() - 1, GetPositionY()));
		if (GetPositionX() <= - GetContentSize().width / 2)
		{
			SetActive(false);
			SetPosition(cocos2d::Director::getInstance()->getVisibleSize().width 
				+ mCoreSprite->getContentSize().width, GetPositionY());
		}
	}
}
