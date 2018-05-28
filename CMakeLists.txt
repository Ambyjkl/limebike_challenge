cmake_minimum_required(VERSION 2.6)
project(limebike_challenge)

add_executable(limebike_challenge main.cpp)

install(TARGETS limebike_challenge RUNTIME DESTINATION bin)
