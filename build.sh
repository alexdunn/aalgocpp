if [ ! -d deps ]; then
    mkdir deps
fi
cd deps
if [ ! -f gtest-1.7.0.zip ]; then
    wget https://googletest.googlecode.com/files/gtest-1.7.0.zip
fi
if [ ! -d gtest-1.7.0 ]; then
    unzip ./gtest-1.7.0.zip
fi

cd ..
mkdir build
cd build

# If it becomes a problem that you're sanitizing dependency libraries as well: http://clang.llvm.org/docs/SanitizerSpecialCaseList.html
# Address Sanitizer
if [ "$SAN" = "UA" ]; then
    echo "UNDEFINED AND ADDRESS SANITIZERS ON"
    export ASAN_OPTIONS="detect_leaks=1" # Enable leak sanitizer
    export CXXFLAGS="-fsanitize=address,undefined,undefined-trap,integer,unsigned-integer-overflow"
fi

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
