#pragma once

#include "models/levels/core/corelevel/CoreLevel.h"
#include "frames/frame1/Level3Frame1.h"

class Level3 : public CoreLevel
{
private:
    Level3Frame1* mLevel3Frame1;

public:
    Level3(cocos2d::Scene* scene);
    ~Level3();

    void Init() override;
    void Update() override;
};
