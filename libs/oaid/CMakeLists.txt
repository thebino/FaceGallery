cmake_minimum_required(VERSION 3.0)

project(oaid)

add_library(oaid STATIC
		./src/comm_lib.cpp
		./src/mtcnn.cpp
		./src/tensorflow_mtcnn.cpp
		./src/utils.cpp
		)

find_package( OpenCV REQUIRED )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libtensorflow/include)
include_directories(${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
