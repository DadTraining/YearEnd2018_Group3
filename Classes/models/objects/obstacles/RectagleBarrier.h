#pragma once

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class RectagleBarrier : public CoreModel 
{
public:
    RectagleBarrier(cocos2d::Node* groupNode, std::string name);
    ~RectagleBarrier();

    void Init() override;
	void Update() override;
};
