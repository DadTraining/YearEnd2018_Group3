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
	bool mHasReleasedAnObstacleOnTheRightSide;
	bool mHasChangeFrameCount;

	/**
	 * Get an inactive obstacle and make it start to travel
	 * @return CoreObstacle
	 */
	CoreObstacle* GetAnInactiveObstacle(const int& mapIndex);

	/**
	 * Get a vector of active obstacles in the map
	 * @return list of vector of obstacles
	 */
	std::vector<CoreObstacle*> GetAVectorOfActiveObstacles();

public:
	ObstaclesCreation(cocos2d::Scene* scene);

	/**
	 * Make the active obstacles disappear from the scene
	 */
	void DisappearActiveObstacles();

	/**
	 * Update every single frame
	 */
	void Update(const Stage& mStage);
};
