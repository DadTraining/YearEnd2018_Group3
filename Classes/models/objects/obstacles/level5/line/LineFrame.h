#pragma once

#include "common/Definition.h"
#include "common/definitionlevels/level5/DefinitionLevel5.h"
#include "models/core/CoreModel.h"
#include "utils/physics/CustomPhysicsBody.h"

#include "cocos2d.h"

class LineFrame : public CoreModel{
private:
	bool mIsAlive;
	int mSpeed;
	cocos2d::PhysicsBody *mLineFramePhysicsBody;
public:
	LineFrame(cocos2d::Scene* scene, std::string name, std::string lineNamePath);
	~LineFrame();
	/**
	* Set moving speed when mode change
	*/
	void setMovingSpeed(int speed);
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