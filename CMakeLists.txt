cmake_minimum_required(VERSION 3.20)
project(RAP)

set(CMAKE_CXX_STANDARD 17)

add_executable(RAP main.cpp
        src/rap_packer/rap_packer.h
        src/rap_packer/rap_packer.cpp
        src/rap/header/header.h
        src/rap/date.h
        src/rap/ura_code_section/ura_code_section.h
        src/rap/padding_bit.h)