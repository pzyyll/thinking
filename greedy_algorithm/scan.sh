#!/usr/bin/env sh
# 一个简单的自动扫描当前目录下的 cpp 并生成一个 CMakeLists.txt 文件的脚步

CMAKE_FILE="CMakeLists.txt"
PWD_BASE_NAME=$(basename `pwd`)

Scan() {
    echo "cmake_minimum_required(VERSION 3.6)"
    echo "project($PWD_BASE_NAME)"
    echo "set(CMAKE_CXX_STANDARD 14)"
    echo ""

    for cpp in ./*.cpp; do
        bname=${cpp##*/}
        bname=${bname%%.*}
        echo "add_executable(${bname} ${cpp})"
    done
}

Scan > $CMAKE_FILE
