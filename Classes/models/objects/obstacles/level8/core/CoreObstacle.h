#pragma once

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class CoreObstacle : public CoreModel
{
protected:
	float mTravelingDuration;
	bool mIsOnTheRightSide; 

public:
	CoreObstacle(const float& travelingDuration, bool isOnTheRightSide, const std::string& name);

	/**
	* Make the obstacles to move up or down
	*/
	virtual void StartTraveling() = 0;
};
