#pragma once

#include "models/core/CoreModel.h"

class RectagleObstacleModel : public CoreModel
{
public:
    RectagleObstacleModel(cocos2d::Scene* scene);
    RectagleObstacleModel(cocos2d::Node* node);
    ~RectagleObstacleModel();

    void Init() override;
    void Update() override;
};
