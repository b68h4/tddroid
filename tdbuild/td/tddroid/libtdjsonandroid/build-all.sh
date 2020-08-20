#!/bin/sh
ANDROID_SDK_ROOT=../../../ndk-bundle SSL_ABI="x86" ABI="x86" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle SSL_ABI="x86_64" ABI="x86_64" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle SSL_ABI="arm" ABI="armeabi-v7a" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle SSL_ABI="arm64" ABI="arm64-v8a" ./build.sh || exit 1
