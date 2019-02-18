#pragma once

#include "models/levels/core/corelevelframe/CoreLevelFrame.h"

#include "cocos2d.h"

class Level5Frame1 : public CoreLevelFrame 
{
public:
	Level5Frame1(cocos2d::Scene* scene);
    ~Level5Frame1();

	void Init() override;
	void Update() override;
    bool HasFinishedMoving() override;
};