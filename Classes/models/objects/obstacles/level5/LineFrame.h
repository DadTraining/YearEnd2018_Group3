#pragma once

#include "common/Definition.h"
#include "common/definitionlevels/DefinitionLevel5.h"
#include "models/core/CoreModel.h"
#include "utils/physics/CustomPhysicsBody.h"

#include <vector>

#include "cocos2d.h"

class LineFrame : public CoreModel{
private:
	bool mIsAlive;
	int mSpeed;
	std::vector<cocos2d::Color3B> mListOfColors;
	int mCurrentColorIndex;

	/**
	* Lerp color
	*/
	void LerpColor();

public:
	LineFrame(cocos2d::Scene* scene, std::string name);
	~LineFrame();

	/**
	* Change line frame
	*/
	void setTexture(std::string linenamepath);

	/**
	* Set physics body for each image
	*/
	void SetPhysicsBody(int indexPath);

	void Init() override;
	void Update() override;
};