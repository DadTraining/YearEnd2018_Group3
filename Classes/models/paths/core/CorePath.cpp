#include "CorePath.h"

CorePath::CorePath(const float& pathPositionY, const float& balloonMovingSpeed)
{
	mPathPositionY = pathPositionY;
	mBalloonMovingSpeed = balloonMovingSpeed;

	mIsTouching = false;
	mIsTouchingRight = true;
}

CorePath::~CorePath()
{
	// Destructor
}

void CorePath::setBalloonMovingSpeed(int balloonSpeed)
{
	mBalloonMovingSpeed = balloonSpeed;
} 

void CorePath::Disappear()
{
	mBalloonSprite->setOpacity(0);
	mBalloonSprite->removeComponent(mBalloonSprite->getPhysicsBody());
}
