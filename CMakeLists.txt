cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(FaceGallery VERSION 0.0.1
				 	LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
	set(CMAKE_VERBOSE_MAKEFILE ON)
	add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wno-unused-parameter)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	add_compile_options(/W4 /WX)
	if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.11)
		add_compile_options(/permissive-)
	endif()
endif()


include_directories( ./include ./src ./libs/oaid/include )


add_executable( FaceGallery ./src/main.cpp)


add_subdirectory(./libs/tensorflow)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libtensorflow/include)
find_library(TENSORFLOW_LIB tensorflow HINT ${CMAKE_CURRENT_SOURCE_DIR}/libtensorflow/lib)

find_package( OpenCV REQUIRED )
message(STATUS "OpenCV library:")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_subdirectory(./libs/oaid)


target_link_libraries( ${PROJECT_NAME} oaid ${TENSORFLOW_LIB} ${OpenCV_LIBS})
