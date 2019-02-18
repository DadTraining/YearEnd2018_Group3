#pragma once

#include <vector>

#include "models/levels/core/corelevel/CoreLevel.h"
#include "models/levels/level1/frames/Level1Frame1.h"
#include "models/objects/orther/line/Line.h"
#include "common/Definition.h"
#include "models/paths/horizontalline/HorizontalLinePath.h"
#include "common/definitionlevels/DefinitionLevel5.h"

#include "cocos2d.h"

class Level5 : public CoreLevel 
{
private:
	Line* mFirstLine;
	Line* mSecondLine;
	Line* mThirdLine;
	HorizontalLinePath* mHorizontalLinePath;
	int mFrameCount;
public:
	Level5(cocos2d::Scene* scene);
    ~Level5();

	/**
	* Moving line frame
	*/
	void MoveLine();

	/**
	* Get Line Frame Path
	*/
	std::string GetLineFramePath();

    void Init() override;
    void Update() override;
};