#include "CoreLevel.h"

CoreLevel::CoreLevel() 
{
	mFrameCount = 0;
}

CoreLevel::~CoreLevel() 
{
	// Destructor
}

void CoreLevel::Init() 
{
    // Initialization
}

void CoreLevel::Update() 
{
    if (!mQueueOfFrames.empty())
    {
        mQueueOfFrames.front()->Update();
        if (mQueueOfFrames.front()->HasFinishedMoving())
        {
            mQueueOfFrames.pop();
        }
    }
}
