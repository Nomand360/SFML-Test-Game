cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME SFML_Avion)
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file( GLOB_RECURSE sources ${SOURCE_DIR}/*.cpp)
file( GLOB_RECURSE headers ${SOURCE_DIR}/*.h)


find_package(SFML COMPONENTS graphics audio network system window REQUIRED)

add_executable(${PROJECT_NAME}
    ${sources}
    ${headers}
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)
