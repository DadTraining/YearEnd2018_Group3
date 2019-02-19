#pragma once

#include <vector>

#include "models/levels/core/corelevel/CoreLevel.h"
#include "frames/Level1Frame1.h"

#include "cocos2d.h"

class Level1 : public CoreLevel 
{
public:
    Level1(cocos2d::Scene* scene);
    ~Level1();

    void Init() override;
    void Update() override;
};
