cmake_minimum_required(VERSION 2.8)

#取一个工程名称
PROJECT (COMPRESS_DECOMPRESS_TOOL)

SET(SRC ./source)
SET(INC ./include)
AUX_SOURCE_DIRECTORY(${SRC} SRC_LIST)

INCLUDE_DIRECTORIES( ${INC} /home/yekong/boost_1_70_0)

LINK_DIRECTORIES(/home/yekong/boost_1_70_0/stage/lib)


ADD_EXECUTABLE(compress_decompress_ltool ${SRC_LIST})