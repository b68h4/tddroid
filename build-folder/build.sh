#!/bin/sh

mkdir -p build-$ABI
cd build-$ABI
cmake .. -DCMAKE_TOOLCHAIN_FILE=${ANDROID_SDK_ROOT}/build/cmake/android.toolchain.cmake  -DCMAKE_BUILD_TYPE=MinSizeRel -GNinja -DANDROID_ABI=${ABI} || exit 1
cmake --build . || exit 1
cd ..

mkdir -p ../output/$ABI/
cp build-$ABI/libtd*.so* ../output/$ABI/
