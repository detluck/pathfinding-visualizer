cmake_minimum_required(VERSION 3.16)

project(PathfindingVisualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# automatic moc for qt classes
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# find qt packages
find_package(Qt6 REQUIRED COMPONENTS Gui Quick Svg)

# standard Qt project settings
qt_standard_project_setup()

# define cpp files
set(PROJECT_SOURCES
    main.cpp
    cpp/pathfinding.h
    cpp/pathfinding.cpp
    cpp/gridmodel.h
    cpp/gridmodel.cpp
    cpp/algorithms/ialgorithm.h
    cpp/algorithms/astar.h
    cpp/algorithms/astar.cpp
    cpp/algorithms/dijkstra.cpp
    cpp/algorithms/dijkstra.h
)

# make executable
qt_add_executable(app
    ${PROJECT_SOURCES}
)

# define qml
qt_add_qml_module(app
    URI Pathfinding
    VERSION 1.0
    QML_FILES 
    ui/Main.qml
    ui/components/ControlPanel.qml
    ui/components/PathGrid.qml
    ui/components/GridTile.qml
    ui/components/StyledButton.qml
    ui/components/StyledSlider.qml
    ui/components/AlgoSelector.qml
    ui/components/StyledText.qml
    ui/theme/Theme.qml
    RESOURCES
        ui/theme/qmldir
        ui/assets/svgs/startNode.svg
        ui/assets/svgs/endNode.svg
        ui/assets/svgs/clean.svg
        ui/assets/svgs/pause.svg
        ui/assets/svgs/start.svg
        ui/assets/svgs/terminate.svg
        ui/assets/svgs/deleate.svg
        ui/assets/svgs/wall.svg
        QML_FILES ui/components/StyledRect.qml
        SOURCES cpp/cursorhelper.h cpp/cursorhelper.cpp
        SOURCES cpp/gridmodel.h cpp/gridmodel.cpp
        SOURCES cpp/algorithmType.h
        SOURCES cpp/algorithms/IAlgorithm.h
)

target_link_libraries(app PRIVATE Qt6::Quick Qt6::Qml Qt6::Svg)

set_target_properties(app PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.pathfinding.project
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS app
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
