#include "Level8.h"

Level8::Level8(cocos2d::Scene *scene)
{ 
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	// The background sprite //
	auto backgroundSprite = cocos2d::Sprite::create("sprites/gameplay/level8/background.png");
	backgroundSprite->setPosition(cocos2d::Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	scene->addChild(backgroundSprite, 0);

	// The vertical line path controller //
	mVerticalLinePath = new VerticalLinePath(scene, 20, 3, 300, "sprites/gameplay/level8/balloon.png", "sprites/gameplay/level8/vertical_line_1.png", origin.y + visibleSize.height / 2);

	// The obstacles creation controller //
	mObstaclesCreation = new ObstaclesCreation(scene);
}

Level8::~Level8()
{
	// Destructor //
}

void Level8::Init()
{
	// Initialization //
}

void Level8::Update()
{ 
	// Update path controller //
	mVerticalLinePath->Update();
	  
	// Spawn obstacles //
	mObstaclesCreation->Update(mVerticalLinePath->GetStage());
}
