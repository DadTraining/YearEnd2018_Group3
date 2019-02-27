#include "Level4.h"
#include "common/definitionlevels/DefinitionLevel4.h"
#include "common/Definition.h"

Level4::Level4(cocos2d::Scene *scene) : CoreLevel()
{
    // Init local variable
    mIndexFrame = 0;
    mPosY = cocos2d::Director::getInstance()->getVisibleSize().height;

    auto background = cocos2d::Sprite::create("sprites/gameplay/level3/background/color_white.jpg");
    background->setAnchorPoint(cocos2d::Vec2(0, 0));
    scene->addChild(background);

    Init();

    InitFrame(scene);
    InitPositionFrame();

    mCirclePath = new CirclePath(scene, 100, "sprites/gameplay/balloon/balloon.png", "sprites/gameplay/level3/circle/circle_path.png", 150, 2);

    mEventPhysics = cocos2d::EventListenerPhysicsContact::create();
    mEventPhysics->onContactBegin = CC_CALLBACK_1(Level4::OnContactBegin, this);
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mEventPhysics, scene);
}

Level4::~Level4()
{
    // Destructor
}

void Level4::Init()
{
    // Initialize function
}

void Level4::Update()
{
    mCirclePath->Update();

    for (int i = 0; i < mLevelFrames.size(); i++)
    {
        mLevelFrames.at(i)->Update();
    }

    for (int i = 0; i < mLevelFrames.size(); i++)
    {
        if (mLevelFrames.at(i)->HasFinishedMoving())
        {
            mLevelFrames.at(i)->SetPositionY(mPosY);
        }
    }

    mFrameCount++;
    if (mFrameCount >= FPS * 70)
    {
        mIsCompletedLevel = true;
    }
}

void Level4::InitFrame(cocos2d::Scene *scene)
{
    for (int i = 0; i < LEVEL4_SIZE_FRAME; i++)
    {
        int randFrame = cocos2d::RandomHelper::random_int(1, 20);

        if (randFrame % 2 == 0)
        {
            mLevelFrames.push_back(new Level4Frame1(scene));
        }else
        {
            mLevelFrames.push_back(new Level4Frame2(scene));
        }
    }
}

void Level4::InitPositionFrame()
{
    for (int i = 0; i < mLevelFrames.size(); i++)
    {
        mLevelFrames.at(i)->SetPositionY(mPosY);
        mPosY += cocos2d::Director::getInstance()->getVisibleSize().height + 80;
    }

    mPosY -= 2 * (cocos2d::Director::getInstance()->getVisibleSize().height + 80);
}

bool Level4::OnContactBegin(cocos2d::PhysicsContact &physicsContact)
{
    auto nodeA = physicsContact.getShapeA()->getBody()->getNode();
    auto nodeB = physicsContact.getShapeB()->getBody()->getNode();

    if (nodeA != nullptr && nodeB != nullptr)
    {
        if ((nodeA->getTag() == OBSTACLES_TAG && nodeB->getTag() == BALLOON_TAG) ||
            (nodeB->getTag() == OBSTACLES_TAG && nodeA->getTag() == BALLOON_TAG)) {
            auto balloonExplosion = cocos2d::ParticleSystemQuad::create(
                    "sprites/gameplay/balloon/balloon_explosion.plist");
            balloonExplosion->setPosition(cocos2d::Vec2(0, 0));
            if (nodeA->getTag() == BALLOON_TAG) {
                nodeA->getPhysicsBody()->setEnabled(false);
                nodeA->setOpacity(0);
                nodeA->addChild(balloonExplosion);

                mIsGameOver = true;
            } else if (nodeB->getTag() == BALLOON_TAG) {
                nodeB->getPhysicsBody()->setEnabled(false);
                nodeB->setOpacity(0);
                nodeB->addChild(balloonExplosion);

                mIsGameOver = true;
            }
            mIsGameOver = true;
        }

        if ((nodeA->getTag() == COIN_TAG && nodeB->getTag() == BALLOON_TAG) ||
            (nodeB->getTag() == COIN_TAG && nodeA->getTag() == BALLOON_TAG)) {
            // Push coin
            if (nodeA->getTag() == COIN_TAG) {
                nodeA->getPhysicsBody()->setEnabled(false);
                nodeA->removeFromParent();
            } else if (nodeB->getTag() == COIN_TAG) {
                nodeB->getPhysicsBody()->setEnabled(false);
                nodeB->removeFromParent();
            }
        }
    }

	return true;
}