set(TARGET_NAME keyEvent)

add_executable(${TARGET_NAME} 
  KeyEventListener.cpp
  Main.cpp
)
#include_directories(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(${TARGET_NAME} caeEvent)
