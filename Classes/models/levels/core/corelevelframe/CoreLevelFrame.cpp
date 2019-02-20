#include "CoreLevelFrame.h"

CoreLevelFrame::CoreLevelFrame()
{
	mFrameCount = 0;
	mIsBelowCenter = false;

}

CoreLevelFrame::~CoreLevelFrame()
{
	// Destructor
}

void CoreLevelFrame::Update()
{
	if (mGroupNode->getPositionY() <= cocos2d::Director::getInstance()->getVisibleSize().height / 2)
	{
		mIsBelowCenter = true;
	}
}

bool CoreLevelFrame::IsBelowCenter()
{
	return mIsBelowCenter;
}
