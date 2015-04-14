[![Build Status](https://travis-ci.org/alexdunn/algorithmscpp.svg?branch=master)](https://travis-ci.org/alexdunn/algorithmscpp)
[![Coverage Status](https://coveralls.io/repos/alexdunn/algorithmscpp/badge.svg)](https://coveralls.io/r/alexdunn/algorithmscpp)
### Build
- Install cmake with `brew install cmake`
- Install the package manager bii with `brew cask install biicode`
- From the repository's root directory: `bii init -L` to initialize the package manager
- And finally configure and build: `CXX=clang++-3.6 CXXFLAGS="-std=c++14 -stdlib=libc++" bii build`

You can clean the build products with `bii clean`

### Run Tests
Because this is simply a collection of algorithm implementations, executing the main binary `bin/algorithmscpp` will execute all the unit tests, presenting the results as it goes.

