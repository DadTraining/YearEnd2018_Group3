#pragma once

#include "models/levels/core/corelevelframe/CoreLevelFrame.h"
#include "models/objects/obstacles/level3/circleline/CircleLineModel.h"

class Level3Frame1 : public CoreLevelFrame
{
private:
    CircleLineModel* mCircleLine;

public:
    Level3Frame1(cocos2d::Scene* scene);
    ~Level3Frame1();

    void Init() override;
    void Update() override;
    bool HasFinishedMoving() override;
};
