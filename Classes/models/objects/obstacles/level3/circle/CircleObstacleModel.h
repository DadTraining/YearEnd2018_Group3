#pragma once

#include "models/core/CoreModel.h"

class CircleObstacleModel : public CoreModel
{

public:
    CircleObstacleModel(const std::string& name, cocos2d::Sprite* sprite);
    ~CircleObstacleModel();

    void Init() override;
    void Update() override;
};