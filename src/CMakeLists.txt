project(main)

add_subdirectory(hello)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(faceGallery PRIVATE hello_lib)
