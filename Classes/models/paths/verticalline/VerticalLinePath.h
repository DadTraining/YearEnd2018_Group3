#pragma once

#include "models/paths/core/CorePath.h"

#include "cocos2d.h"

enum Stage
{
	STAGE_1,
	STAGE_2,
	STAGE_3,
	STAGE_4,
	STAGE_5,
	STAGE_6,
	DONE
};

class VerticalLinePath : public CorePath
{
private:
	bool mIsMovingDown;
	float mCenterPositionX;
	int mFrameCount;
	Stage mStage;

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

	/**
	 *  Update every single frame
	 */
	void Update() override;

	/**
	* Get the current stage of the path
	* @return Stage
	*/
	Stage GetStage();
};