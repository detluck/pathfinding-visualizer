cmake_minimum_required(VERSION 3.16)

project(PathfindingVisualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatisches MOC / UIC / RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Qml Gui Svg)

qt_policy(SET QTP0001 NEW)

set(PROJECT_SOURCES
    main.cpp
    cpp/core/pathfinding.h cpp/core/pathfinding.cpp
    cpp/core/cursorhelper.h cpp/core/cursorhelper.cpp
    cpp/model/gridmodel.h cpp/model/gridmodel.cpp
    cpp/model/node.h
    cpp/algorithms/ialgorithm.h
    cpp/algorithms/astar.h cpp/algorithms/astar.cpp
    cpp/algorithms/dijkstra.h cpp/algorithms/dijkstra.cpp
    cpp/algorithms/algorithmType.h
)

qt_add_executable(app MACOSX_BUNDLE
    ${PROJECT_SOURCES}
)

# QML Modul
qt_add_qml_module(app
    URI Pathfinding
    VERSION 1.0
    QML_FILES
        Main.qml
        ui/components/ControlPanel.qml
        ui/components/PathGrid.qml
        ui/components/GridTile.qml
        ui/components/StyledButton.qml
        ui/components/StyledSlider.qml
        ui/components/AlgoSelector.qml
        ui/components/StyledText.qml
        ui/components/StyledRect.qml
        ui/components/SpeedSlider.qml
        ui/theme/Theme.qml
    RESOURCES
        ui/theme/qmldir
        ui/assets/svgs/startNode.svg
        ui/assets/svgs/endNode.svg
        ui/assets/svgs/clean.svg
        ui/assets/svgs/pause.svg
        ui/assets/svgs/start.svg
        ui/assets/svgs/terminate.svg
        ui/assets/svgs/delete.svg
        ui/assets/svgs/wall.svg
)

# Link Qt Bibliotheken
target_link_libraries(app PRIVATE Qt6::Quick Qt6::Qml Qt6::Gui Qt6::Svg)

# Plattform-spezifische Einstellungen (blendet auf Windows die Terminal-Konsole aus)
set_target_properties(app PROPERTIES
    WIN32_EXECUTABLE TRUE
)

if(NOT EMSCRIPTEN)
    qt_generate_deploy_qml_app_script(
        TARGET app
        OUTPUT_SCRIPT deploy_qml_script
    )
    install(SCRIPT ${deploy_qml_script})
endif()

qt_finalize_executable(app)