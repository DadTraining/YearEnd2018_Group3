#include "Level7.h"
#include "common/definitionlevels/DefinitionLevel7.h"
#include "common/Definition.h"

Level7::Level7(cocos2d::Scene *scene)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto backgroundSprite = cocos2d::Sprite::create("sprites/gameplay/level5/background.png");
	backgroundSprite->setPosition(backgroundSprite->getContentSize().width / 2, visibleSize.height / 2);
	scene->addChild(backgroundSprite, -1);

	mCircleLine = new CircleLineModel(scene, CIRCLE_LINE_PATH, CircleLineModel::PATH);
	mCircleLine->SetPosition(visibleSize.width / 2, visibleSize.height / 2);
	
	mBarriersCreation = new BarriersCreation(scene);

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Level7::OnContactBegin, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, scene);
}

Level7::~Level7()
{

}

bool Level7::OnContactBegin(cocos2d::PhysicsContact & contact)
{
	auto shapeA = contact.getShapeA()->getBody();
	auto shapeB = contact.getShapeB()->getBody();

	if (shapeA != nullptr && shapeB != nullptr)
	{
		if (shapeA->getNode()->getTag() == shapeB->getNode()->getTag())
		{
			// Barriers with same colors //
			if (shapeA->getCollisionBitmask() == shapeB->getCollisionBitmask())
			{
				return false;
			}

			if (shapeA->getCollisionBitmask() == 0x02)
			{
				DisappearNode(shapeA->getNode());
			}
			else
			{
				DisappearNode(shapeB->getNode());
			}
		}
		else
		{
			if (shapeA->getCollisionBitmask() != shapeB->getCollisionBitmask())
			{
				mIsGameOver = true;
			}
		}
	}

	return true;
}

void Level7::DisappearNode(cocos2d::Node * node)
{
	std::string barrierExplosionPath;
	//node->setVisible(false);
	if (node->getTag() == BLUE_BARRIER_OBSTACLES_TAG)
	{
		barrierExplosionPath = BLUE_BARRIER_OBSTACLE_EXPLOSION_PATH;
	}
	else if (node->getTag() == RED_BARRIER_OBSTACLES_TAG)
	{
		barrierExplosionPath = RED_BARRIER_OBSTACLE_EXPLOSION_PATH;
	}
	else if (node->getTag() == GREEN_BARRIER_OBSTACLES_TAG)
	{
		barrierExplosionPath = GREEN_BARRIER_OBSTACLE_EXPLOSION_PATH;
	}
	else
	{
		barrierExplosionPath = YELLOW_BARRIER_OBSTACLE_EXPLOSION_PATH;
	}
	
	auto barrierExplosionSystem = cocos2d::ParticleSystemQuad::create(barrierExplosionPath);
	barrierExplosionSystem->setPosition(cocos2d::Vec2(node->getContentSize().width / 2, 0));
	node->addChild(barrierExplosionSystem, 1000);

	node->setOpacity(0);
	node->getPhysicsBody()->setEnabled(false);
}

void Level7::Init()
{
	// Initialize
}

void Level7::Update()
{
	mFrameCount++;
	
	mCircleLine->Update();

	mBarriersCreation->Update();

	if (mBarriersCreation->GetMode() == COMPLETE_LEVEL)
	{
		mIsCompletedLevel = true;
	}

	if (mIsCompletedLevel || mIsGameOver)
	{
		mBarriersCreation->InactiveBarrier();
	}
}
