#!/usr/bin/env bash

# This runs all checks that are available to clang-tidy, which is a superset of the checks that are run by clang's static analyzer

set -e

cd src
for filename in ./*; do
    # clang-tidy
    echo -e '\x1B[0;34m'
    echo -e "=== clang-tidy $filename"
    echo -e '\x1B[0m'
    clang-tidy-3.6 -p ../build/ -checks='*' "$filename"

    # clang-modernize
    echo -e '\x1B[0;34m'
    echo -e "\n=== clang-modernize $filename"
    echo -e '\x1B[0m'
    clang-modernize-3.6 -risk=risky -final-syntax-check -p=../build/ "$filename"

    # flawfinder
    echo -e '\x1B[0;34m'
    echo -e "\n=== flawfinder $filename"
    echo -e '\x1B[0;31m'
    flawfinder -Q -D --omittime --quiet "$filename"
    echo -e '\x1B[0m'
done
cd ..

