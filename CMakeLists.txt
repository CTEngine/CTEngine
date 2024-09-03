cmake_minimum_required(VERSION 3.5.0)
project(HomemadeHero VERSION 0.1.0 LANGUAGES C CXX)
add_executable(HomemadeHero main.cpp)

target_link_libraries(HomemadeHero PRIVATE gdi32)