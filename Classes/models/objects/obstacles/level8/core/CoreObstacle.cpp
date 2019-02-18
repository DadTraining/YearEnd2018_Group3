#include "CoreObstacle.h"

CoreObstacle::CoreObstacle(const float& travelingDuration,bool isOnTheRightSide, const std::string& name) : CoreModel(name)
{
	mTravelingDuration = travelingDuration;
	mIsOnTheRightSide = isOnTheRightSide;
}

void CoreObstacle::StartTraveling()
{ 
	this->SetActive(true);
}
