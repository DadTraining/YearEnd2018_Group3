#include "Enemy.h"

Enemy::Enemy(cocos2d::Node* groupNode, std::string name) : CoreModel(name)
{
    mCoreSprite = cocos2d::Sprite::create();
    groupNode->addChild(mCoreSprite);
}

Enemy::~Enemy()
{
	// Destructor
}

void Enemy::Init()
{

}

void Enemy::Update()
{

}