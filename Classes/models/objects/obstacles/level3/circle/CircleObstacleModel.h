#pragma once

#include "../../../../core/CoreModel.h"

class CircleObstacleModel : public CoreModel
{

public:
    CircleObstacleModel(const std::string& name, cocos2d::Sprite* sprite);
    CircleObstacleModel(const std::string& name, cocos2d::Node* node);
    ~CircleObstacleModel();

    void Init() override;
    void Update() override;
};
