#pragma once

#include "models/levels/core/corelevelframe/CoreLevelFrame.h"

#include "cocos2d.h"

class Level1Frame1 : public CoreLevelFrame 
{
public:
    Level1Frame1(cocos2d::Scene* scene);
    ~Level1Frame1();

	void Init() override;
	void Update() override;
    bool HasFinishedMoving() override;
};
