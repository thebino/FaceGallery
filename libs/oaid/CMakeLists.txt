cmake_minimum_required(VERSION 3.0)

project(oaid)

add_library(oaid STATIC
		./src/comm_lib.cpp
		./src/mtcnn.cpp
		./src/tensorflow_mtcnn.cpp
		./src/utils.cpp
		)

find_package( OpenCV REQUIRED )

include_directories(${CMAKE_SOURCE_DIR}/include ${TENSORFLOW_LIB} ${OpenCV_INCLUDE_DIRS})
