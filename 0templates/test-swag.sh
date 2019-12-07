#!/usr/local/bin/zsh


g++ -std=c++14 -O2 swag.test.cpp && IN="swag-testcase/input" OUT="swag-testcase/output" ./check.sh && rm -f a.out

