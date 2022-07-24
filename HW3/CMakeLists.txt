cmake_minimum_required(VERSION 3.11)

project(play)

add_executable(play
main.cpp
schet.cpp
rand.cpp
schet.h
rand.h
)

target_compile_features(play PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(play PUBLIC  /W4 /WX)
else()
    target_compile_options(play PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
