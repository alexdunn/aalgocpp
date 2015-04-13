cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project(algorithmscpp)

message($ENV{TRAVIS_JOB_ID})

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
# Coverals
#------------------------------------------------------------------------------
# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)
include(Coveralls)

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

aux_source_directory("${PROJECT_SOURCE_DIR}/src" SOURCES)
set(COVERAGE_SRCS "${SOURCES}")
aux_source_directory("${PROJECT_SOURCE_DIR}/tests" TESTS) # I want to compile only the srcs for coveralls
set(SOURCES "${SOURCES};${TESTS}") # I want to also compile all unit tests into the binary

include_directories ("${PROJECT_SOURCE_DIR}/src")

# Create the coveralls target.
coveralls_setup(
    "${COVERAGE_SRCS}" # The source files.
    ON                 # If we should upload.
    "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake") # (Optional) Alternate project cmake module path.

#-----------------------------------------------------------------------
# Compile Settings
#-----------------------------------------------------------------------

#set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")  # Make the compile_commands.json file for YouCompleteMe
set(CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --coverage") # Generate code coverage data

#-----------------------------------------------------------------------
# Setup executable
#-----------------------------------------------------------------------
set(EXE_NAME algorithmscpp)
add_executable(${EXE_NAME} ${SOURCES})
target_link_libraries(${EXE_NAME} ${CPM_LIBRARIES})

