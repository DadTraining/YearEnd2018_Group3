#pragma once

#include "models/objects/obstacles/level8/core/CoreObstacle.h"

#include "cocos2d.h"

class Spike : public CoreObstacle
{
private:
	void Init() override;
	void Update() override;

public:
	Spike(cocos2d::Scene* scene, const float& travelingDuration, const bool& isOnTheRightSide);

	void StartTraveling() override;
};