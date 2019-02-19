#pragma once

#include "models/core/CoreModel.h"

class RectagleModel : public CoreModel
{
public:
    RectagleModel(cocos2d::Scene* scene);
    RectagleModel(cocos2d::Node* node);
    ~RectagleModel();

    void Init() override;
    void Update() override;
};
