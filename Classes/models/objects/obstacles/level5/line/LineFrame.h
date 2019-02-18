#pragma once

#include "models/core/CoreModel.h"

#include "cocos2d.h"

class LineFrame : public CoreModel {
private:
	bool mIsAlive;
public:
	LineFrame(cocos2d::Scene* scene, std::string name, std::string lineNamePath);
    ~LineFrame();

	/**
	* Change line frame
	*/
	void setTexture(std::string linenamepath);
    void Init() override;
    void Update() override;
};
