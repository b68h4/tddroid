#!/bin/sh

mkdir -p build-$ABI
cd build-$ABI
cmake .. -DCMAKE_TOOLCHAIN_FILE=${ANDROID_SDK_ROOT}/build/cmake/android.toolchain.cmake -DOPENSSL_INCLUDE_DIR=../third_party/crypto/$SSL_ABI/include -DOPENSSL_ROOT_DIR=../third_party/crypto/$SSL_ABI  -DCMAKE_BUILD_TYPE=MinSizeRel -GNinja -DANDROID_ABI=${ABI} || exit 1
cmake --build . || exit 1
cd ..

mkdir -p libs/$ABI/
cp build-$ABI/libtd*.so* libs/$ABI/
