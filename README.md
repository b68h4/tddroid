# tddroid
## TDLib Android Easy Build Project
### [Precompiled Releases](https://github.com/bsggr78/tddroid/releases)

## **Requirements:**
   [TDLib Build Documentation](https://tdlib.github.io/td/build.html) open site, select language / os and follow the instructions **(not run a build commands, follow only    requirements instructions)**.
   ### [Important] Clone the Latest TDLib Source Code to tdlib-src
``` 
git clone https://github.com/tdlib/td tdlib-src
```

## **Building:**

- ### _1- Docker_:
``` 
Install Docker Your Computer.
Enter the project folder.

docker build --name tddroid -t .
Build the image

docker run -it --name tdbuild -v projectfolder:/app tddroid
Change `projectfolder` to project folder path (Example: /root/tddroid) and run command.
Finally building was started!
Can find the compiled files in `output` folder.
```  
- ### _2- Normal_:
  #### Enter the [build-folder](/build-folder) and follow the instructions.

### Supported Architectures:
- armeabi-v7a (arm)
- arm64-v8a (aarch64)
- x86
- x86_64
### Supported Platforms/Programming Languages:
- Android/All Mobile Programming Languages

### Notes:
- Files compiled in this project may not work in Android/Java applications [See](https://github.com/tdlib/td/issues/77#issuecomment-640719893).
- Compilation requires a high power device. Requires over 4 Gb ram. If you have less than 4 Gb ram, check out the tdlib compilation documentation.
- If you find a problem in the project, be sure to report it from the issue section.
### Changelog:
      v1.7.1:
      - The project has been redesigned. 
      - Docker support added.
      - More readable document.
      - Updated to v1.7.1
      - Deleted Tdsharp (Not required)
### Used Projects
> [egramtel/tdsharp - Official TDLib .NET Library](https://github.com/egramtel/tdsharp)

> [tdlib/td - Official TDLib Library](https://github.com/tdlib/td)

> [KDAB/androidopenssl - Replaced Precompiled Openssl libraries thanks](https://github.com/KDAB/android_openssl)

> [levlam/Prebuilt Build Scripts](https://github.com/tdlib/td/issues/77#issuecomment-640719893)



## Telegram Channel: [Coderator](https://t.me/coderator)
