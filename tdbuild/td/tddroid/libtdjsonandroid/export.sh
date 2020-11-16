#!/bin/sh

mkdir -p build_native
cd build_native
cmake .. || exit 1
cmake --build . --target prepare_cross_compiling || exit 1
cd ..

./build-all.sh || exit 1

rm -rf tdlib_export
mkdir -p tdlib_export/tdlib
echo libs | xargs tar -c | tar -C tdlib_export/tdlib -xv
