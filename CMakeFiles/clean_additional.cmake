# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Pathfinder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Pathfinder_autogen.dir\\ParseCache.txt"
  "Pathfinder_autogen"
  )
endif()
