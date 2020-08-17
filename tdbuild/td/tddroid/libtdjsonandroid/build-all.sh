#!/bin/sh
ANDROID_SDK_ROOT=../../../ndk-bundle ABI="x86" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle ABI="x86_64" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle ABI="armeabi-v7a" ./build.sh || exit 1
ANDROID_SDK_ROOT=../../../ndk-bundle ABI="arm64-v8a" ./build.sh || exit 1
