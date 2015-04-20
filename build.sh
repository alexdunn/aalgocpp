./get_deps.sh

if [ ! -d build ]; then
    mkdir build
fi
cd build

# If you get false positives due to errors in dependencies: http://clang.llvm.org/docs/SanitizerSpecialCaseList.html
# More information here: https://docs.python.org/devguide/clang.html
# Address Sanitizer
if [ "$SAN" = "UA" ]; then
    echo "UNDEFINED AND ADDRESS SANITIZERS ON"
    export ASAN_OPTIONS="detect_leaks=1" # Enable leak sanitizer
    export CXXFLAGS="-fsanitize=address,undefined,undefined-trap,integer,unsigned-integer-overflow"
fi

# TODO: Get this working by following https://code.google.com/p/memory-sanitizer/wiki/LibcxxHowTo
if [ "$SAN" = "M" ]; then
    echo "MEMORY SANITIZER ON"
    export CXXFLAGS="-fPIC -g -fsanitize=memory"
fi

if [ "$SAN" = "T" ]; then
    echo "THREAD SANITIZER ON"
    export CXXFLAGS="-g -fsanitize=thread"
fi

export CXXFLAGS="${CXXFLAGS} -std=c++14 -stdlib=libc++"
cmake ..
make -- VERBOSE=1
