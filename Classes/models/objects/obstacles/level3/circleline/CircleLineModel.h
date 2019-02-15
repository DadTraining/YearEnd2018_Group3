#pragma once

#include <vector>

#include "models/core/CoreModel.h"
#include "models/objects/obstacles/level3/circle/CircleObstacleModel.h"
#include "models/objects/obstacles/level3/coin/CoinModel.h"

#include "cocos2d.h"

class CircleLineModel : public CoreModel
{
private:
    std::vector<CircleObstacleModel*> mCircleObstacleModels;
    std::vector<CoinModel*> mCoinModels;

    cocos2d::Node* mNodeCoin;

    /**
     * Init vector circle obstacle
     */
    void InitCircleObstacleModels(cocos2d::Sprite* sprite);

    /**
     * Init the position of item in mCircleObstacleModels
     */
    void InitPositionCircleObstacleModels();

    /**
     * Init vector CoinModel
     */
    void InitCoinModels();

    /**
     * Init the position of item in mCoinModels
     */
    void InitPositionCoinModels();

public:
    CircleLineModel(cocos2d::Node* node);
    ~CircleLineModel();

    void Init() override;
    void Update() override;
};
