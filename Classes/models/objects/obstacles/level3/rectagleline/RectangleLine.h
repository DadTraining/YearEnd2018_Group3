#pragma once

#include <vector>

#include "models/core/CoreModel.h"
#include "models/objects/obstacles/level3/rectagle/RectangleObstacleModel.h"

#include "cocos2d.h"

class RectangleLine : CoreModel
{
private:
    std::vector<RectangleObstacleModel*> mRectangleObstacleModels;

    /**
     * Init vector RectangleObstacleModels
     */
    void InitRectangleObstacleModels();

    /**
     * Init the position of item of mRectangleObstacleModels
     */
    void InitPossitionRectangleModels();

public:
    RectangleLine(cocos2d::Scene* scene);
    RectangleLine(cocos2d::Node* node);
    ~RectangleLine();

    void Init() override;
    void Update() override;
};