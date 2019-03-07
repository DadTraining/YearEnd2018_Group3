#include "Helper.h"

char* Helper::SKIP_INTRO_SCENE_VALUE = "SKIP_INTRO_SCENE_VALUE_1";
std::string Helper::sLevelNames[] = { "Duc Gioi", "Nhat Thien", "Nhi Thien", "Tam Thien", "Tu Thien", "Khong Vo Bien Xu","Thuc Vo Bien Xu","Vo So Huu Xu","Phi Tuong Phi Phi Tuong Xu" };
std::string Helper::sLevelDescriptions[] = { "The personification of heaven", "Roman God of water",
                                             "God of agriculture", "Roman God of the underworld, Hades", "Roman God of war", "World of Gods",
                                             "Ruler of the Roman Gods","Goddess of love and beauty","Messenger of the Roman Gods" };

std::vector<std::string> Helper::GetAVectorOfAnimationFramesNames(const char* format, const int& count)
{
    std::vector<std::string> animFramesNames;

    char str[100];

    for (int i = 1; i <= count; i++)
    {
        sprintf(str, format, i);
        animFramesNames.push_back(str);
    }

    return animFramesNames;
}

bool Helper::HasSkippedTheIntroScene()
{
    cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();

    return userDefault->getIntegerForKey(SKIP_INTRO_SCENE_VALUE, 0) == 1;
}

void Helper::SkipTheIntroScene()
{
    cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();
    userDefault->setIntegerForKey(SKIP_INTRO_SCENE_VALUE, 1);
}

std::string Helper::GetTheLevelNameBasedOnTheIndex(const int& index)
{
    return sLevelNames[index];
}

std::string Helper::GetTheLevelDescriptionBasedOnTheIndex(const int& index)
{
    return sLevelDescriptions[index];
}