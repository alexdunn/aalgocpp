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

