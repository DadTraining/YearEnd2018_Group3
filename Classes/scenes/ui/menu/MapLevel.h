#pragma once

#include "cocos2d.h"

#include "ui/CocosGUI.h"

class MapLevel : public cocos2d::Scene
{
private:
	void update(float dt);
	std::vector<cocos2d::ui::Button*> mListButton;
	std::vector<MapLevel*> mListLevel;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void setListButton();
	CREATE_FUNC(MapLevel);
};
