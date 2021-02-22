## Building

Architecture List:
- armeabi-v7a
- arm64-v8a
- x86
- x86_64

Envirionment Variables:
- ANDROID_SDK_ROOT : Setting the Android NDK path ('../ndk' is built-in Android NDK).
- ABI : Setting the Architecture.

#### If you are going to compile all architectures ./build-all.sh.


#### If you are going to compile a single architecture:
- ANDROID_SDK_ROOT=../ndk ABI=selectedarchitecture ./build.sh
