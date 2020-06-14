if (NOT EXISTS ${CMAKE_SOURCE_DIR}/libs/qt/src)
    make_directory(${CMAKE_SOURCE_DIR}/libs/qt/src)
endif()
if (NOT EXISTS ${CMAKE_SOURCE_DIR}/libs/qt/bin/)
    file(
            DOWNLOAD
            http://download.qt.io/official_releases/qt/5.15/5.15.0/single/qt-everywhere-src-5.15.0.tar.xz ${CMAKE_SOURCE_DIR}/libs/qt/src/qt-everywhere-src.tar.xz
            STATUS
            status
            LOG
            log
    )
    list(GET status 0 status_code)
    list(GET status 1 status_string)
    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "error downloading qt-everywhere-src: ${status_string}" "${log}")
    endif()

    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xf ${CMAKE_SOURCE_DIR}/libs/qt/src/qt-everywhere-src.tar.xz WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs/qt/src)
    file(REMOVE ${CMAKE_SOURCE_DIR}/lib/qt/src/qt-everywhere-src.tar.xz)
    execute_process(COMMAND ./configure -opensource -confirm-license -release -static -nomake tests -nomake examples -skip qtwebengine WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs/qt/src//qt-everywhere-src-5.15.0)
endif()
