#include "ObstaclesCreation.h"
#include "models/objects/obstacles/level8/Bar.h"
#include "models/objects/obstacles/level8/Spike.h"
#include "common/Definition.h"
#include "common/definitionlevels/DefinitionLevel8.h"

ObstaclesCreation::ObstaclesCreation(cocos2d::Scene* scene)
{
	mFrameCount = 0;

	// Create some obstacles and store it in the map // 
	for (int i = 0; i < NUMBER_OF_INTIAL_OBSTACLES; i++)
	{
		mMapOfObstacles[0].push_back(new Bar(scene, 2, cocos2d::random(1, 2) % 2 == 0));
		mMapOfObstacles[1].push_back(new Spike(scene, 3, cocos2d::random(1, 2) % 2 == 0));
		mMapOfObstacles[2].push_back(new Bar(scene, 2, cocos2d::random(1, 2) % 2 == 0));
		mMapOfObstacles[3].push_back(new Spike(scene, 2, cocos2d::random(1, 2) % 2 == 0));
	}
}

CoreObstacle* ObstaclesCreation::GetAnInactiveObstacle(const int& mapIndex)
{
	for (int i = 0; i < mMapOfObstacles[mapIndex].size(); i++)
	{
		if (!mMapOfObstacles[mapIndex].at(i)->IsActive())
			return mMapOfObstacles[mapIndex].at(i);
	}

	return nullptr;
}

void ObstaclesCreation::Update(const Stage& mStage)
{
	// On stage 2: Make some obstacles to move downwards //
	if (mStage == STAGE_2)
	{
		mFrameCount++;

		if (mFrameCount % (OBSTACLES_SPAWNING_TIME_MULTIPLIER) == 0)
		{
			CoreObstacle* obstacle = GetAnInactiveObstacle(0);

			if (obstacle != nullptr)
				obstacle->StartTraveling();
		}
	}
	// On stage 4: Make some obstacles to move upwards //
	else if (mStage == STAGE_4)
	{
		mFrameCount++;

		if (mFrameCount % (OBSTACLES_SPAWNING_TIME_MULTIPLIER) == 0)
		{
			CoreObstacle* obstacle = GetAnInactiveObstacle(1);

			if (obstacle != nullptr)
				obstacle->StartTraveling();
		}
	}
	else if (mStage == STAGE_5)
	{
		mFrameCount++;

		if (mFrameCount % (OBSTACLES_SPAWNING_TIME_MULTIPLIER) == 0)
		{
			CoreObstacle* obstacle = GetAnInactiveObstacle(cocos2d::random(1, 2) % 2 == 0 ? 0 : 1);

			if (obstacle != nullptr)
				obstacle->StartTraveling();
		}
	}
}