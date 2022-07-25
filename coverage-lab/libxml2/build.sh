#!/bin/bash

set -x

export CXXFLAGS="-O0 --coverage"
export CFLAGS="-O0 --coverage"
export CXX="g++"
export CC="gcc"

rm -rf target
cp -rf libxml target
(cd target && ./autogen.sh && CCLD="$CXX $CXXFLAGS" ./configure --disable-shared && make)
