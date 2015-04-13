cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)
project(algorithmscpp)

#------------------------------------------------------------------------------
# Required CPM Setup - no need to modify - See: https://github.com/iauns/cpm
#------------------------------------------------------------------------------
set(CPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpm-packages" CACHE TYPE STRING)
find_package(Git)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "CPM requires Git.")
endif()
if (NOT EXISTS ${CPM_DIR}/CPM.cmake)
  message(STATUS "Cloning repo (https://github.com/iauns/cpm)")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" clone https://github.com/iauns/cpm ${CPM_DIR}
    RESULT_VARIABLE error_code
    OUTPUT_QUIET ERROR_QUIET)
  if(error_code)
    message(FATAL_ERROR "CPM failed to get the hash for HEAD")
  endif()
endif()
include(${CPM_DIR}/CPM.cmake)

#------------------------------------------------------------------------------
# CPM Modules
#------------------------------------------------------------------------------

# ++ MODULE: OpenGL platform
CPM_AddModule("cpm-google-test"
  GIT_REPOSITORY "https://github.com/iauns/cpm-google-test"
  GIT_TAG "1.0.2")

CPM_Finish()

#-----------------------------------------------------------------------
# Setup source
#-----------------------------------------------------------------------

set (Sources src/main.cpp src/sorting.cpp)

#-----------------------------------------------------------------------
# Compile Settings
#-----------------------------------------------------------------------

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")  # Make the compile_commands.json file for YouCompleteMe
set(CMAKE_CXX_FLAGS_INIT "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

#-----------------------------------------------------------------------
# Setup executable
#-----------------------------------------------------------------------
set(EXE_NAME algorithmscpp)
add_executable(${EXE_NAME} ${Sources})
target_link_libraries(${EXE_NAME} ${CPM_LIBRARIES})

