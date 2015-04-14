
ADD_BII_TARGETS()

# Rename the output binary
SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES OUTPUT_NAME algorithmscpp)

# Build environment settings for C++ to apply to all my targets as well as third party packages
SET(ENV{CXX} usr/local/bin/clang++-3.6)
SET(ENV{CXXFLAGS} "-std=c++14 -stdlib=libc++")

#TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++14" "-stdlib=libc++")

# Compiler flags for only my target
TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-pedantic-errors" "-fexceptions" "-ftrapv" "-Wall" "-Wextra" "-Werror")

# Environment conditional compiler flags, typically run only on Travis CI
if ($ENV{TRAVIS})
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-fsanitize=undefined,undefined-trap,integer" "-fno-omit-frame-pointer")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-g" "-O0" "--coverage")
endif()

if ($ENV{SAN} MATCHES "A")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-fsanitize=address")
    message("ADDRESS SANITIZER ON")
endif()

if ($ENV{MSAN} MATCHES "M")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-fsanitize=memory")
    message("MEMORY SANITIZER ON")
endif()

if ($ENV{TSAN} MATCHES "T")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-fsanitize=thread")
    message("THREAD SANITIZER ON")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")  # Make the compile_commands.json file for clang-modernizer

