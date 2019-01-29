#include "RectagleBarrier.h"

RectagleBarrier::RectagleBarrier(cocos2d::Node* groupNode, std::string name) : CoreModel(name)
{
    mCoreSprite = cocos2d::Sprite::create();
    groupNode->addChild(mCoreSprite);
}

RectagleBarrier::~RectagleBarrier()
{
	// Destructor
}

void RectagleBarrier::Init()
{

}

void RectagleBarrier::Update()
{

}