set(TARGET_NAME keyEvent)

add_executable(${TARGET_NAME} 
  KeyEventListener.cpp
  Main.cpp
)
target_link_libraries(${TARGET_NAME} caeEvent)
