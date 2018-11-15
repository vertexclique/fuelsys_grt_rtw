#!/bin/bash

set -e

echo "Setting up whole bitcode segment compiler..."

export MACOSX_DEPLOYMENT_TARGET=10.14
export LLVM_COMPILER=clang
export CC=wllvm

make -f fuelsys.mk

echo "Assembling single bitcode..."

extract-bc ../fuelsys

echo "Assembled!"
