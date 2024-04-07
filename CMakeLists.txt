cmake_minimum_required(VERSION 3.16)

project(MediaProV2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMediaProV2
    main.cpp
    Images.qrc
)

qt_add_qml_module(appMediaProV2
    URI MediaProV2
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES
        QML_FILES
        RESOURCES Images.qrc
        SOURCES someclass.h someclass.cpp
        RESOURCES SideBar.qml
        QML_FILES
        QML_FILES BottomBar1.qml
        QML_FILES LibraryScreen.qml
        QML_FILES PlayingScreen.qml
        QML_FILES QueueScreen.qml
        QML_FILES RulesScreen.qml
        QML_FILES SettingsScreen.qml
        QML_FILES TagsScreen.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMediaProV2 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMediaProV2
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMediaProV2
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appMediaProV2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
