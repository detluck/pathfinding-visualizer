cmake_minimum_required(VERSION 3.16)

project(Pathfinding-visualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# automatic moc for qt classes
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# find qt packages
find_package(Qt6 REQUIRED COMPONENTS Quick)

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
qt_add_executable(appPathfindingVisualizer
    ${PROJECT_SOURCES}
)

# define qml
qt_add_qml_module(appPathfindingVisualizer
    URI Pathfinding.App
    VERSION 1.0
    QML_FILES 
        ui/main.qml
        ui/ControlPanel.qml
        ui/PathGrid.qml
        ui/GridTile.qml
)

target_link_libraries(appPathfindingVisualizer PRIVATE Qt6::Quick Qt6::Qml)

# Optimierung für Deployment (Optional)
set_target_properties(appPathfindingVisualizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.pathfinding.project
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS appPathfindingVisualizer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)