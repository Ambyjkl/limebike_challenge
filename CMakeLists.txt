cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 17)
project(limebike_challenge)

add_executable(limebike_challenge ItemCounter.cpp Ride.cpp main.cpp)

install(TARGETS limebike_challenge RUNTIME DESTINATION bin)
