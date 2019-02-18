#pragma once

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class Line : public CoreModel {
private:
	bool mIsAlive;
public:
	Line(cocos2d::Scene* scene, std::string name, std::string lineNamePath);
    ~Line();
	/**
	* Change line frame
	*/
	void setTexture(std::string linenamepath);
    void Init() override;
    void Update() override;
};
