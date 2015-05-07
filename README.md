[![Build Status](https://travis-ci.org/xanderdunn/aalgocpp.svg?branch=coverity_scan)](https://travis-ci.org/xanderdunn/aalgocpp)
[![Coverage Status](https://coveralls.io/repos/alexdunn/aalgocpp/badge.svg)](https://coveralls.io/r/alexdunn/aalgocpp)

## About
This is a collection of algorithms written in C++14.  Many of the algorithms are from the textbook *The Algorithm Design Manual*.

## Build
- Install cmake with `brew install cmake`
- From the repository's root directory: `./build.sh`
- The output binary will be at build/algorithmscpp

## Test
Because this is simply a collection of algorithm implementations, executing the main binary `bin/algorithmscpp` will execute all the unit tests, presenting the results as it goes.

## Tools
This project makes use of many tools to ensure code quality.  Because most of them have been integrated into the continuous integration system, this list is intended to keep a list of them all so that it be periodically ensured that they are all still doing their job:

### Working Automatically
- Travis CI = Continuous integration of all commits pushed to branches master and coverity_scan. The Travis CI build badge can be seen in this README on the project's GitHub page.
- Coveralls = Code run coverage.  This ensures that everything is being covered in the unit tests.
- Clang's address sanitizer = Causes the program to crash if any memory errors such as out of bounds heap access, use-after-free, etc. This will cause a build failure.
- Clang's leak sanitizer = Causes the program to crash if any memory leaks are found during execution.  This will cause a build failure.
- Clang's thread sanitizer = Prints a warning message if potential races are found
- Clang's undefined sanitizers and unsigned integer overflow = Catch undefined behavior

### Working Manually
- clang-tidy = Clang's lint tool that also runs all of the clang static analyzer's checkers. This can be run by executing the lint_and_analyze.sh script in the project's root directory.
- flaw-finder = static analysis tool that focuses on security.  This can be run by executing the lint_and_analyze.sh script in the project's root directory.
- clang-modernize = Ensure that new C++11 functionality is being used where possible.  I have to run this manually on my source files.

### Planned
- Memory Sanitizer = Build libc++ with -fsanitize=memory and link against that
- Coverity Scan = Code static analysis.
- OCLint static analyzer
- splint static analyzer
- hfcca code complexity analyzer
- pmd static analyzer and code duplication finder
- Add some performance measurements
- Facebook's flint
- [Undefined Behavior Canaries](https://github.com/regehr/ub-canaries)
