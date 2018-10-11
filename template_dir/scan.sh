#!/bin/sh
# 自动扫描当前目录下的 cpp 并生成一个 CMakeLists.txt 文件

CMAKE_FILE="CMakeLists.txt"
PWD_BASE_NAME=$(basename `pwd`)
COMMON_CMD="cmake_minimum_required(VERSION 3.9)\nproject($PWD_BASE_NAME)\nset(CMAKE_CXX_STANDARD 14)\n"

Scan() {
    echo $COMMON_CMD

    for cpp in ./*.cpp; do
        bname=${cpp##*/}
        bname=${bname%%.*}
        echo "add_executable(${bname} ${cpp})"
    done
}

Scan > $CMAKE_FILE
