FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update

RUN apt-get install nano ncurses-bin make git zlib1g-dev libssl-dev gperf cmake g++ ninja-build openssl clang-10 libc++-dev libc++abi-dev  -y

RUN mkdir /app
RUN mkdir /app/build-folder

WORKDIR /app/build-folder

CMD ./build-all.sh



