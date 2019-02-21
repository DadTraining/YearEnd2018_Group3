#pragma once

#include "CirclePath.h"
#include "utils/physics/CustomPhysicsBody.h"

class CirclePathExtend : public CirclePath
{
public:
    CirclePathExtend(cocos2d::Scene* scene);
    ~CirclePathExtend();

    void Update();
};
