cmake_minimum_required(VERSION 3.20)
project(RAP)

set(CMAKE_CXX_STANDARD 17)

add_executable(RAP main.cpp src/rap_packer/rap_packer.h src/rap_packer/rap_packer.cpp src/rap_unpacker/rap_unpacker.h src/rap_unpacker/rap_unpacker.cpp src/rap_packer/config_parser/config_parser.h src/rap_packer/config_parser/config_parser.cpp src/rap_packer/rap_info/rap_info.h src/rap_packer/rap_info/header_info.h src/rap_packer/rap_info/date.h)
