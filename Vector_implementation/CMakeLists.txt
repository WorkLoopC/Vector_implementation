cmake_minimum_required(VERSION 3.28)
project(Vector_implementation)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_FILES})
add_custom_target(run
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
)