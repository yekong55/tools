cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE "DEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")


#取一个工程名称
PROJECT (COMPRESS_DECOMPRESS_TOOL)

SET(SRC ./source)
SET(INC ./include)
SET(LIBRARIES_PATH /home/yekong/boost_1_70_0/stage/lib)
AUX_SOURCE_DIRECTORY(${SRC} SRC_LIST)

INCLUDE_DIRECTORIES( ${INC} /home/yekong/boost_1_70_0)

ADD_EXECUTABLE(compress_decompress_ltool ${SRC_LIST})

TARGET_LINK_LIBRARIES(compress_decompress_ltool ${LIBRARIES_PATH}/libboost_filesystem.so ${LIBRARIES_PATH}/libboost_iostreams.so)

#FIND_LIBRARY(BOOST_LIBRARIES /home/yekong/boost_1_70_0/stage/lib)


#LINK_DIRECTORIES(/home/yekong/boost_1_70_0/stage/lib)

























