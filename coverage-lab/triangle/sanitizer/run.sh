#!/bin/bash

clang -fsanitize=address -c trace-pc.c
clang -g -fsanitize=address -fsanitize-coverage=trace-pc-guard -o triangle triangle.c trace-pc.o
ASAN_OPTIONS='' ./triangle

