#include "BarriersCreation.h"
#include "common/definitionlevels/DefinitionLevel7.h"

BarriersCreation::BarriersCreation(cocos2d::Scene* scene)
{
	// Set local data //
	mFrameCount = 0;
	mIndexListBarrier = 0;
	mMode = EASY_MODE;
	mBarrierObstacleSpawnTime = BARRIER_OBSTACLES_SPAWN_TIME_EASY;

	/* Generate barriers */
	for (int i = 0; i < BARRER_OBSTACLE_SIZE; i++)
	{
		int color = cocos2d::random(0, 3);
		int mode = cocos2d::random(0, 5);
		int counterMode = (mode % 2 == 0) ? (mode + 1) : (mode - 1);
		switch (color)
		{
		case 0:
			mBarriers.push_back(new Barrier(scene, BARRIER_BLUE_OBSTACLE_PATH, mode, Barrier::COLOR_BLUE));
			mCounterBarriers.push_back(new Barrier(scene, BARRIER_GREEN_OBSTACLE_PATH, counterMode, Barrier::COLOR_GREEN));
			break;
		case 1:
			mBarriers.push_back(new Barrier(scene, BARRIER_RED_OBSTACLE_PATH, mode, Barrier::COLOR_RED));
			mCounterBarriers.push_back(new Barrier(scene, BARRIER_YELLOW_OBSTACLE_PATH, counterMode, Barrier::COLOR_YELLOW));
			break;
		case 2:
			mBarriers.push_back(new Barrier(scene, BARRIER_GREEN_OBSTACLE_PATH, mode, Barrier::COLOR_GREEN));
			mCounterBarriers.push_back(new Barrier(scene, BARRIER_BLUE_OBSTACLE_PATH, counterMode, Barrier::COLOR_BLUE));
			break;
		default:
			mBarriers.push_back(new Barrier(scene, BARRIER_YELLOW_OBSTACLE_PATH, mode, Barrier::COLOR_YELLOW));
			mCounterBarriers.push_back(new Barrier(scene, BARRIER_RED_OBSTACLE_PATH, counterMode, Barrier::COLOR_RED));
			break;
		}
	}
}

int BarriersCreation::GetMode()
{
	return this->mMode;
}

void BarriersCreation::ActiveBarrier()
{
	if (!mBarriers.at(mIndexListBarrier)->IsActive() &&
		!mCounterBarriers.at(mIndexListBarrier)->IsActive())
	{
		mBarriers.at(mIndexListBarrier)->Init();
		mCounterBarriers.at(mIndexListBarrier)->Init();
	}
	
	mIndexListBarrier++;

	if (mIndexListBarrier >= mBarriers.size())
	{
		mIndexListBarrier = 0;
	}
}

void BarriersCreation::Update()
{
	mFrameCount++;

	if (mFrameCount % (FPS * mBarrierObstacleSpawnTime) == 0)
	{
		ActiveBarrier();
	}

	/* Update list of barrier*/
	for (int i = 0; i < mBarriers.size(); i++)
	{
		mBarriers.at(i)->Update();
	}
	
	for (int i = 0; i < mCounterBarriers.size(); i++)
	{
		mCounterBarriers.at(i)->Update();
	}

	if (mFrameCount >= (FPS * EASY_MODE))
	{
		mMode = NORMAL_MODE;
		mBarrierObstacleSpawnTime = BARRIER_OBSTACLES_SPAWN_TIME_NORMAL;
	}
	
	if (mFrameCount >= (FPS * NORMAL_MODE))
	{
		mMode = HARD_MODE;
		mBarrierObstacleSpawnTime = BARRIER_OBSTACLES_SPAWN_TIME_HARD;
	}

	if (mFrameCount >= (FPS * COMPLETE_LEVEL))
	{
		mMode = COMPLETE_LEVEL;
	}
}
