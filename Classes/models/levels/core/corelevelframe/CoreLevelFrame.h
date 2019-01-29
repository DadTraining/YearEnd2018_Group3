#pragma once

#include <map>

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class CoreLevelFrame 
{
protected:
    std::map<std::string, CoreModel*> mObjectsDictionary;
    cocos2d::Node* mGroupNode;
    bool mHasFinishMoving;
	int mFrameCount;

public:
	CoreLevelFrame();
    ~CoreLevelFrame();

	virtual void Init() = 0;
	virtual void Update() = 0;
    virtual bool HasFinishedMoving() = 0;
};
