#!/usr/bin/env bash

# This runs all checks that are available to clang-tidy, which is a superset of the checks that are run by clang's static analyzer

set -e

cd src
for filename in ./*; do
    echo -e '\x1B[0;34m'
    echo -e "\n\n=== clang-tidy $filename"
    echo -e '\x1B[0m'
    clang-tidy-3.6 -p ../build/ -checks='*' "$filename"
    #cppcheck "$filename"
    echo -e '\x1B[0;34m'
    echo -e "\n\n=== flawfinder $filename"
    echo -e '\x1B[0;31m'
    flawfinder -Q -D --omittime --quiet "$filename"
    echo -e '\x1B[0m'
done
cd ..

