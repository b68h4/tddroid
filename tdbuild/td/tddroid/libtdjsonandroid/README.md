Build Command
ANDROID_SDK_ROOT=../../../ndk-bundle **SSL_ABI=arm** ABI=armeabi-v7a ./build.sh

ABI LIST --> SSL_ABI LIST:
- x86 --> x86
- x86_64 --> x86_64
- arm  
  - armeabi-v7a --> arm
  - arm64-v8a --> arm64
Example:
If ABI=arm64-v8a Then 
SSL_ABI=arm64
If ABI=armeabi-v7a Then
SSL_ABI=arm

ANDROID_SDK_ROOT=../../../ndk-bundle 

../../../ndk-bundle If you want to use another bundle you can change the path


Precompile Folder: build-x86 build-x86_64 build-armeabi-v7a build-arm64-v8a
