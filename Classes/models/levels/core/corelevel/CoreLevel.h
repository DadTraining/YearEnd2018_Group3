#pragma once

#include <queue>

#include "models/levels/core/corelevelframe/CoreLevelFrame.h"

#include "cocos2d.h"

class CoreLevel 
{
protected:
    std::queue<CoreLevelFrame*> mQueueOfFrames;
	int mFrameCount;
	
public:
    CoreLevel();
    ~CoreLevel();

    virtual void Init() = 0;
    virtual void Update() = 0;
};
