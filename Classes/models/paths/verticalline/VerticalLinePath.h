#pragma once

#include "models/paths/core/CorePath.h"

#include "cocos2d.h"

class VerticalLinePath : public CorePath
{
private:
	bool mIsMovingDown;
	float mCenterPositionX;

	/* Change variables here to fit your needs */
	float mDistanceBetweenBaloonAndThePath; // Corresponding to your picture's width and height
	float mPathMovingSpeed;
	float mThresholdMovingDistance;
	/*******************************************/

	bool OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override;
	void OnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;

public:
	VerticalLinePath(cocos2d::Scene* scene, const float& distanceBetweenBaloonAndThePath,
		const float& pathMovingSpeed, const float& thresholdMovingDistance,
		const std::string& balloonNamePath, const std::string& pathNamePath,
		const float& pathPositionY);

	void Update() override;
};