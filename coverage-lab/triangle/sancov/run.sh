#!/bin/bash

clang -g -fsanitize=address -fsanitize-coverage=trace-pc-guard -o triangle triangle.c
ASAN_OPTIONS=coverage=1 ./triangle
sancov -symbolize triangle.*.sancov triangle
