#!/bin/bash

export MACOSX_DEPLOYMENT_TARGET=10.14
export LLVM_COMPILER=clang
export CC=wllvm
export LD=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld

make -f fuelsys.mk

extract-bc --linker $LD ../fuelsys
