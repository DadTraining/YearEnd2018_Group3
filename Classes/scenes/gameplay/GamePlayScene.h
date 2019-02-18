#pragma once

#include "models\/levels\level5\Level5.h"
#include "common/Definition.h"

#include "cocos2d.h"

class GamePlayScene : public cocos2d::Scene
{
private:
	Level5* mLevel5;

	void update(float dt);
	
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayScene);
};
