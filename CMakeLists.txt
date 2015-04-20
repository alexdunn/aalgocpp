cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)

project(algorithmscpp CXX)
set(EXE_NAME algorithmscpp)

aux_source_directory("${PROJECT_SOURCE_DIR}/src" SOURCES)
aux_source_directory("${PROJECT_SOURCE_DIR}/tests" TESTS)
set(SOURCES "${SOURCES};${TESTS}") # I want to also compile all unit tests into the binary

# Headers
include_directories ("${PROJECT_SOURCE_DIR}/src")
include_directories ("${PROJECT_SOURCE_DIR}/deps/gtest-1.7.0/include")

add_executable(${EXE_NAME} ${SOURCES})
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/gtest-1.7.0")
target_link_libraries(${EXE_NAME} gtest)

# Compiler flags for only my target
TARGET_COMPILE_OPTIONS(${EXE_NAME} PUBLIC "-g" "-O0" "-pedantic-errors" "-fexceptions" "-ftrapv" "-Wall" "-Wextra" "-Werror")

# Environment conditional compiler flags, typically run only on Travis CI
if ($ENV{COVERAGE})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    message("COVERAGE ON")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")  # Make the compile_commands.json file for clang-modernizer

