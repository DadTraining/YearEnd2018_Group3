#pragma once

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class Enemy : public CoreModel {
public:
	Enemy(cocos2d::Node* groupNode, std::string name);
    ~Enemy();

    void Init() override;
    void Update() override;
};
