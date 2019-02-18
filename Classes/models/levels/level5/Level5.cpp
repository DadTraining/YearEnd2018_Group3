#include "Level5.h"

Level5::Level5(cocos2d::Scene *scene)
{
	mHorizontalLinePath = new HorizontalLinePath(scene, "sprites/gameplay/paths/horizontal_line_path.png",
		"sprites/gameplay/balloon/balloon.png", 100, 5);

	mFirstLine = new LineFrame(scene, "line_frame_0", GetLineFramePath());
	mSecondLine = new LineFrame(scene, "line_frame_1", GetLineFramePath());
	mThirdLine = new LineFrame(scene, "line_frame_2", GetLineFramePath());
}

Level5::~Level5()
{

}

void Level5::MoveLine()
{
	mFrameCount++;
	if (mFrameCount % 60 == 0)
	{		
		if (!mFirstLine->IsActive())
		{
			mFirstLine->setTexture(GetLineFramePath());
			mFirstLine->Init();
			mFirstLine->SetPosition(mThirdLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
		if (!mSecondLine->IsActive())
		{			
			mSecondLine->setTexture(GetLineFramePath());
			mSecondLine->Init();
			mSecondLine->SetPosition(mFirstLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
		if (!mThirdLine->IsActive())
		{
			mThirdLine->setTexture(GetLineFramePath());
			mThirdLine->Init();
			mThirdLine->SetPosition(mSecondLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
		}
	}
}

std::string Level5::GetLineFramePath()
{
	char lineFramePath[50];
	int indexPath = cocos2d::random(0, MAX_IMAGE);
	cocos2d::log("%d", indexPath);
	sprintf(lineFramePath, "sprites/gameplay/level5/line/line_frame_%d.png", indexPath);
	return lineFramePath;
}

void Level5::Init()
{
	mFirstLine->Init();
	mFirstLine->SetPosition(cocos2d::Vec2(SREEEN_RESOLUTION_WIDTH / 2, SREEEN_RESOLUTION_HEIGHT));
	
	mSecondLine->Init();
	mSecondLine->SetPosition(mFirstLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));

	mThirdLine->Init();
	mThirdLine->SetPosition(mSecondLine->GetPosition() + cocos2d::Vec2(0, SREEEN_RESOLUTION_HEIGHT));
}

void Level5::Update()
{
	mHorizontalLinePath->Update();
	MoveLine();
	mFirstLine->Update();
	mSecondLine->Update();
	mThirdLine->Update();
}
