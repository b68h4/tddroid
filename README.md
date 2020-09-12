# tddroid
## TDLib and TDSharp Build Project

## NOTES: Please Reread Usage and Reclone Project
> Use in Your Xamarin Projects or Other Arm Platforms.

> It Was Built To Compile TDLib Easily And Without The Worries Of Addiction.

## [PreCompile Releases](https://github.com/bsglinux16/tddroid/releases)

#### Working Platforms
- x86
- x86_64
- arm
  - armeabi-v7a
  - arm64-v8a

#### Working Languages
 - I think it works in all languages :))
 - Excluding Java (Not Working Java Use JNI and Java Build Files [Comment](https://github.com/tdlib/td/issues/77#issuecomment-640719893))

**[Build Folder](tdbuild/td/tddroid/libtdjsonandroid)**

## Changes (v1.6.7 / 2)
- egramtel / tdsharp Linux Bindings Edited and Adapt LibTdJsonAndroid (tdbuild)
  - Interop.cs Fixed
- Ndk-Bundle r21 Included in Project (Easy Compile)
  - Android Sdk Root Added to build-all.sh File
- OpenSsl-1.1.1g Builds Collected and Added
- Build.sh Build-All.sh Created Successfully Running
- **SSL_ABI Added Fixed SSL Paths and NDK Paths**
## Used Projects
> [egramtel/tdsharp - Official TDLib .NET Library](https://github.com/egramtel/tdsharp)

> [tdlib/td - Official TDLib Library](https://github.com/tdlib/td)

> [KDAB/androidopenssl - Extracted PreCompile OpenSsl .so Files Thanks](https://github.com/KDAB/android_openssl)

> [levlam Prebuilt Build Archives](https://github.com/tdlib/td/issues/77#issuecomment-640719893)
## Usage

- Enter the tdbuild/td/tddroid/libtdjsonandroid Folder
  - Run export.sh And Build All Architecture
  
  <s>- Run **ANDROID_SDK_ROOT=../../../ndk-bundle ABI="the platform you want to use" SSL_ABI="ABI's equivalent to SSL_ABI" ./build.sh** </s>
  
  - **If You Don't Run the export.sh File Build.sh or Build-All.sh by itself won't work**
  - **ABI's equivalent to SSL_ABI Available Here --> [Readme 2](https://github.com/bsglinux16/tddroid/blob/master/tdbuild/td/tddroid/libtdjsonandroid/README.md)**
  
- When the build is finished go to the build- "platform-ABI" folder
  - Include the libtdjsonandroid.so File in Your .NET Project

- Open tdsharp/Tdlib.sln Visual Studio and Build the Project
  - Uninstall the TDLib Package You Downloaded From Nuget and Import the TDLib.dll-TDLib.Api.Dll Files You Just Compiled

- Write Telegram App and build .NET Project

- Finally, put the file libtdjsonandroid.so suitable for the platform on which the application will run into the Debug folder.

### Oh my God It is working on Android and other Arm Platforms! 😳🙂
### Tested on Xamarin x86 and armeabi-v7a Platforms - Successfuly Working!

#### If You Have a Problem, Be Sure to Report to Issue Section
#### Note: I Recommend Compiling On The Server Because It Uses High Processor Power While Compiling.

> Telegram Groups [tr]: [KodWare](https://t.me/kodware) [OverClick](https://t.me/overclickofficial) 
