cmake_minimum_required(VERSION 3.28)
project(probability
    VERSION 1.0.0
    DESCRIPTION "Float probability compression"
    LANGUAGES CXX)

message(STATUS "Michał Czyż (c) 2024")
message(STATUS "GNU GPL 3")


add_executable(probability src/compress.cpp)

