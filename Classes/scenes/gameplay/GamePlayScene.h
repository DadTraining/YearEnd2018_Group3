#pragma once

#include<vector>

#include "models/levels/core/corelevel/CoreLevel.h"

#include "cocos2d.h"

class GamePlayScene : public cocos2d::Scene
{
private:
	static int mCurrentLevelIndex;
	std::vector<CoreLevel*> mListOfLevels;

	void update(float dt);

	void ShowGameOverPanel();
	void ShowLevelCompletion();

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayScene);
};
