#pragma once

#include "models/objects/obstacles/level8/core/CoreObstacle.h"

#include "cocos2d.h"

class Bar : public CoreObstacle
{
private:
	void Init() override;
	void Update() override;

public:
	Bar(cocos2d::Scene* scene, const float& travelingDuration, const bool& isOnTheRightSide);

	void StartTraveling() override;
};
