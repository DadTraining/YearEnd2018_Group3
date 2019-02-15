#include "Level3.h"
#include "frames/frame1/Level3Frame1.h"

Level3::Level3(cocos2d::Scene *scene) : CoreLevel()
{
    mLevel3Frame1 = new Level3Frame1(scene);
    //mQueueOfFrames.push(new Level3Frame1(scene));
}

Level3::~Level3()
{

}

void Level3::Init()
{

}

void Level3::Update()
{
    mLevel3Frame1->Update();
}
