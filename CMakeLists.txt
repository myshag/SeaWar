cmake_minimum_required(VERSION 3.5)

project(SeaWar LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES SeaWar_ru_RU.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        boardgamescene.cpp
        boardgamescene.h
        mainwindow.h
        mainwindow.ui
        startgamedialog.cpp
        startgamedialog.h
        startgamedialog.ui
        Observer/Observer.cpp
        Observer/Observer.h
        Controllers/GameController.cpp
        Controllers/GameController.h
        Controllers/BoardController.cpp
        Controllers/BoardController.h
        Models/BoardModel.cpp
        Models/BoardModel.h
        Models/GameModel.cpp
        Models/GameModel.h
        Models/Ship.cpp
        Models/Ship.h
        shipitem.cpp
        shipitem.h
        gameview.cpp
        gameview.h

        ${TS_FILES}
)

list (APPEND RESOURCES resources/resources.qrc)
qt5_add_resources (RCC_SOURCES ${RESOURCES})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SeaWar
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(SeaWar SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(SeaWar
            ${RCC_SOURCES}
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(SeaWar PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
