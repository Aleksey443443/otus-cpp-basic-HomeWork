cmake_minimum_required(VERSION 3.11)

project(play)

add_executable(play
main.cpp
schet.cpp
rand.cpp
schet.h
rand.h
inout.cpp
inout.h
)

target_compile_features(play PUBLIC cxx_std_17)


