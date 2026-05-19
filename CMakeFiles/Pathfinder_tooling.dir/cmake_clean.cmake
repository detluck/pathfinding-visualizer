file(REMOVE_RECURSE
  "Pathfinding/Main.qml"
  "Pathfinding/ui/assets/fonts/JetBrainsMono-Bold.ttf"
  "Pathfinding/ui/assets/fonts/JetBrainsMono-Regular.ttf"
  "Pathfinding/ui/assets/svgs/clean.svg"
  "Pathfinding/ui/assets/svgs/dark.svg"
  "Pathfinding/ui/assets/svgs/delete.svg"
  "Pathfinding/ui/assets/svgs/endNode.svg"
  "Pathfinding/ui/assets/svgs/error.svg"
  "Pathfinding/ui/assets/svgs/light.svg"
  "Pathfinding/ui/assets/svgs/pause.svg"
  "Pathfinding/ui/assets/svgs/start.svg"
  "Pathfinding/ui/assets/svgs/startNode.svg"
  "Pathfinding/ui/assets/svgs/status.svg"
  "Pathfinding/ui/assets/svgs/terminate.svg"
  "Pathfinding/ui/assets/svgs/wall.svg"
  "Pathfinding/ui/assets/svgs/warning.svg"
  "Pathfinding/ui/assets/svgs/weight.svg"
  "Pathfinding/ui/components/AlgoSelector.qml"
  "Pathfinding/ui/components/ControlPanel.qml"
  "Pathfinding/ui/components/GridTile.qml"
  "Pathfinding/ui/components/PathGrid.qml"
  "Pathfinding/ui/components/SpeedSlider.qml"
  "Pathfinding/ui/components/StatusBar.qml"
  "Pathfinding/ui/components/StyledButton.qml"
  "Pathfinding/ui/components/StyledIcon.qml"
  "Pathfinding/ui/components/StyledSlider.qml"
  "Pathfinding/ui/components/StyledText.qml"
  "Pathfinding/ui/components/Toaster.qml"
  "Pathfinding/ui/components/WeightButton.qml"
  "Pathfinding/ui/theme/Theme.qml"
  "Pathfinding/ui/theme/qmldir"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Pathfinder_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
