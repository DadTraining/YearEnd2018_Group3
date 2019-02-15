#pragma once

#include <vector>

#include "models/core/CoreModel.h"
#include "models/objects/obstacles/level3/circle/CircleObstacleModel.h"

#include "cocos2d.h"

class CircleLineModel : public CoreModel
{
private:
    std::vector<CircleObstacleModel*> mCircleObstacleModels;

    /**
     * Init vector circle obstacle
     */
    void InitCircleObstacleModels(cocos2d::Sprite* sprite);

    /**
     * Init the position of item of mCircleObstacleModels
     */
    void InitPositionCircleObstacleModels();

public:
    CircleLineModel(cocos2d::Scene* scene);
    ~CircleLineModel();

    void Init() override;
    void Update() override;
};