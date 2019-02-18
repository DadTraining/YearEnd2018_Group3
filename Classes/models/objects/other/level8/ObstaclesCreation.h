#pragma once

#include <map>
#include <vector>

#include "models/paths/verticalline/VerticalLinePath.h"
#include "models/objects/obstacles/level8/core/CoreObstacle.h"

#include "cocos2d.h"

class ObstaclesCreation
{
private:
	std::map<int, std::vector<CoreObstacle*>> mMapOfObstacles;
	int mFrameCount;

	/**
	 * Get an inactive obstacle and make it start to travel
	 * @return CoreObstacle
	 */
	CoreObstacle* GetAnInactiveObstacle(const int& mapIndex);

public:
	ObstaclesCreation(cocos2d::Scene* scene);

	/**
	 * Update every single frame
	 */
	void Update(const Stage& mStage);
};
