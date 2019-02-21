#include "CirclePathExtend.h"
#include "common/Definition.h"
#include "common/Definition.h"

CirclePathExtend::CirclePathExtend(cocos2d::Scene *scene) : CirclePath(scene, 100, "sprites/gameplay/balloon/balloon.png", "sprites/gameplay/level3/circle/circle_path.png", 150, 2)
{
    mBalloonSprite->setTag(BALLOON_TAG);

    auto balloonPhysics = cocos2d::PhysicsBody::createCircle(mBalloonSprite->getContentSize().width / 2);
    balloonPhysics->setDynamic(false);
    balloonPhysics->setCollisionBitmask(BALLOON_COLLISION_BITMASK);
    balloonPhysics->setContactTestBitmask(true);

    mBalloonSprite->addComponent(balloonPhysics);
}

CirclePathExtend::~CirclePathExtend()
{

}

void CirclePathExtend::Update()
{
    CirclePath::Update();
}
