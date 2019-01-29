#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.1)

set(APP_NAME TemplateCpp)

project(${APP_NAME})

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
if(NOT USE_COCOS_PREBUILT)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

include_directories(
        Classes
        ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)
# add cross-platforms source files and header files 
list(APPEND GAME_SOURCE
     Classes/common/appdelegate/AppDelegate.cpp
     Classes/scenes/gameplay/GamePlayScene.cpp
     )
list(APPEND GAME_HEADER
     Classes/common/appdelegate/AppDelegate.h
     Classes/scenes/gameplay/GamePlayScene.h
     )

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
            proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
        Classes/common/Definition.h
        Classes/common/appdelegate/AppDelegate.h
        Classes/common/appdelegate/AppDelegate.cpp
        Classes/common/definitionlevels/DefinitionLevel1.h
        Classes/models/core/CoreModel.h
        Classes/models/core/CoreModel.cpp
        Classes/models/levels/core/corelevel/CoreLevel.h
        Classes/models/levels/core/corelevel/CoreLevel.cpp
        Classes/models/levels/core/corelevelframe/CoreLevelFrame.h
        Classes/models/levels/core/corelevelframe/CoreLevelFrame.cpp
        Classes/models/levels/level1/Level1.h
        Classes/models/levels/level1/Level1.cpp
        Classes/models/levels/level1/frames/Level1Frame1.h
        Classes/models/levels/level1/frames/Level1Frame1.cpp
        Classes/models/objects/obstacles/RectagleBarrier.h
        Classes/models/objects/obstacles/RectagleBarrier.cpp
        Classes/models/objects/orther/Enemy.h
        Classes/models/objects/orther/Enemy.cpp
        Classes/models/paths/core/CorePath.h
        Classes/models/paths/core/CorePath.cpp
        Classes/models/paths/circle/CirclePath.h
        Classes/models/paths/circle/CirclePath.cpp
        Classes/models/paths/horizontalline/HorizontalLinePath.h
        Classes/models/paths/horizontalline/HorizontalLinePath.cpp
        Classes/models/paths/square/SquarePath.h
        Classes/models/paths/square/SquarePath.cpp
        Classes/models/paths/triangular/TriangularPath.h
        Classes/models/paths/triangular/TriangularPath.cpp
        Classes/models/paths/verticalline/VerticalLinePath.h
        Classes/models/paths/verticalline/VerticalLinePath.cpp
        Classes/scenes/gameplay/GamePlayScene.h
        Classes/scenes/gameplay/GamePlayScene.cpp
        Classes/scenes/intro/IntroStart.h
        Classes/scenes/intro/IntroStart.cpp
        Classes/scenes/intro/IntroEnd.h
        Classes/scenes/intro/IntroEnd.cpp
        Classes/scenes/ui/gameover/GameOver.h
        Classes/scenes/ui/gameover/GameOver.cpp
        Classes/scenes/ui/menu/MenuScene.h
        Classes/scenes/ui/menu/MenuScene.cpp
        Classes/scenes/ui/splash/SplashScreenScene.h
        Classes/scenes/ui/splash/SplashScreenScene.cpp
        Classes/utils/helper/Helper.h
        Classes/utils/helper/Helper.cpp
        Classes/utils/levels/level1/Level1Helper.h
        Classes/utils/levels/level1/Level1Helper.cpp
        )
if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
        PRIVATE Classes
        PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
        )

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
                )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_RES_DIR}/..)
endif()

if(LINUX OR WINDOWS)
    cocos_copy_res(COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()
