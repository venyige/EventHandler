set(TARGET_NAME caeEvent)

add_library(${TARGET_NAME} 
  Event.cpp
)

target_include_directories(${TARGET_NAME} 
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
