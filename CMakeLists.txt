cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(FaceGallery VERSION 0.0.1
				 	LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")


include_directories( ./include ./src ./libs/oaid/include )


add_executable( FaceGallery ./src/main.cpp)


add_subdirectory(./libs/tensorflow)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libtensorflow/include)

find_package( OpenCV REQUIRED )
message(STATUS "OpenCV library:")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_subdirectory(./libs/oaid)


target_link_libraries( ${PROJECT_NAME} oaid ${TENSORFLOW_LIB} ${OpenCV_LIBS})
