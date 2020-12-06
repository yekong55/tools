#CMAKE_MINIMUN_REQUIRED(VERSION 2.80)
cmake_minimum_required(VERSION 3.10)


SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

#set include directory
SET(inc ./include)
INCLUDE_DIRECTORIES(${inc})

#the first method of getting source file:
SET(srcDir ./source)
FILE(GLOB srcFile "${srcDir}/*.cpp")

#the second method of getting source file:
#AUX_SOURCE_DIRECTORY(./source srcFile)
ADD_EXECUTABLE(exmaple1 ${srcFile})