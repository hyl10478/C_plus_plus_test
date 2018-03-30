cmake_minimum_required(VERSION 3.8)
project(Pro1)

include_directories(
        ${PROJECT_SOURCE_DIR}/ClassTest
        ${PROJECT_SOURCE_DIR}/include/util)
set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        main.cpp
        include/util/loop.h
        src/util/loop.cpp
        SystemTimeTest/TimeTest.cpp
        SystemTimeTest/TimeTest.h
        C_Plus_Plus_Basic/BasicTest.cpp
        C_Plus_Plus_Basic/BasicTest.h
        ClassTest/Person.cpp
        ClassTest/Person.h
        ClassTest/Male.cpp
        ClassTest/Male.h
        ClassTest/Female.cpp
        ClassTest/Female.h
        MultiThread/ThreadTest.cpp
        MultiThread/ThreadTest.h
        FileDirectory/FileOrDirectory.cpp
        FileDirectory/FileOrDirectory.h
        ExternTest/global.cpp
        ExternTest/global.h
        ExternTest/extern_test.cpp
        ExternTest/extern_test.h
        ExternTest/function.cpp
        ExternTest/function.h
        ClassTest/Account.cpp
        ClassTest/Account.h
        Design_Pattern/Singleton.cpp
        Design_Pattern/Singleton.h
        Design_Pattern/Product.cpp
        Design_Pattern/Product.h
        Design_Pattern/Factory.cpp
        Design_Pattern/Factory.h
        ClassTest/gree.cpp
        ClassTest/gree.h)

add_executable(Pro1 ${SOURCE_FILES})



