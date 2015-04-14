
ADD_BII_TARGETS()

# Rename the output binary
SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES OUTPUT_NAME algorithmscpp)

# Note: Setting the environment variables CXX, CXXFLAGS, or LDFLAGS at this point is not useful.  cmake has already configured these things by the time it gets here

# Compiler flags for only my target
TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PUBLIC "-g" "-O0" "-pedantic-errors" "-fexceptions" "-ftrapv" "-Wall" "-Wextra" "-Werror")

# Environment conditional compiler flags, typically run only on Travis CI
if ($ENV{COVERAGE})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    message("COVERAGE ON")
endif()

if ($ENV{SAN} MATCHES "U")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined,undefined-trap,integer,unsigned-integer-overflow")
    SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES LINK_FLAGS "-g -fsanitize=address")
    message("UNDEFINED SANITIZER ON")
endif()

if ($ENV{SAN} MATCHES "A")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PRIVATE "-fsanitize=address")
    SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES LINK_FLAGS "-g -fsanitize=address")
    message("ADDRESS SANITIZER ON")
endif()

if ($ENV{SAN} MATCHES "M")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PRIVATE "-fPIC" "-fsanitize=memory")
    SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES LINK_FLAGS "-g -fsanitize=memory")
    message("MEMORY SANITIZER ON")
endif()

if ($ENV{SAN} MATCHES "T")
    TARGET_COMPILE_OPTIONS(${BII_src_main_TARGET} PRIVATE "-fsanitize=thread")
    SET_TARGET_PROPERTIES(${BII_src_main_TARGET} PROPERTIES LINK_FLAGS "-g -fsanitize=thread")
    message("THREAD SANITIZER ON")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")  # Make the compile_commands.json file for clang-modernizer

