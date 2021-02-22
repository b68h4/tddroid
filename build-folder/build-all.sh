#!/bin/sh

mkdir -p build_native
cd build_native
cmake .. || exit 1
cmake --build . --target prepare_cross_compiling || exit 1
cd ..

ANDROID_SDK_ROOT=../ndk ABI="x86" ./build.sh || exit 1
ANDROID_SDK_ROOT=../ndk ABI="x86_64" ./build.sh || exit 1
ANDROID_SDK_ROOT=../ndk ABI="armeabi-v7a" ./build.sh || exit 1
ANDROID_SDK_ROOT=../ndk ABI="arm64-v8a" ./build.sh || exit 1


echo "Building Completed!"
