if(UNIX AND NOT APPLE)
    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow)
        make_directory(${CMAKE_BINARY_DIR}/libtensorflow)
    endif()

    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow/lib/libtensorflow.so)
        file(
                DOWNLOAD
                https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-linux-x86_64-1.15.0.tar.gz ${CMAKE_BINARY_DIR}/libtensorflow/linux.tar.gz
                STATUS
                status
                LOG
                log
        )
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            message(FATAL_ERROR "error downloading tensorflow lib: ${status_string}" "${log}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_BINARY_DIR}/libtensorflow/linux.tar.gz WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libtensorflow)
        file(REMOVE ${CMAKE_BINARY_DIR}/libtensorflow/linux.tar.gz)
    endif()

elseif(APPLE)
    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow)
        make_directory(${CMAKE_BINARY_DIR}/libtensorflow)
    endif()
    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow/lib/libtensorflow.so)
        file(
                DOWNLOAD
                https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-darwin-x86_64-1.15.0.tar.gz ${CMAKE_BINARY_DIR}/libtensorflow/darwin.tar.gz
                STATUS
                status
                LOG
                log
        )
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            message(FATAL_ERROR "error downloading tensorflow lib: ${status_string}" "${log}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_BINARY_DIR}/libtensorflow/darwin.tar.gz WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libtensorflow)
        file(REMOVE ${CMAKE_BINARY_DIR}/libtensorflow/darwin.tar.gz)
    endif()

elseif(WIN32)
    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow)
        make_directory(${CMAKE_BINARY_DIR}/libtensorflow)
    endif()

    if (NOT EXISTS ${CMAKE_BINARY_DIR}/libtensorflow/lib/tensorflow.dll)
        file(
                DOWNLOAD
                https://storage.googleapis.com/tensorflow/libtensorflow/libtensorflow-cpu-windows-x86_64-1.15.0.zip ${CMAKE_BINARY_DIR}/libtensorflow/windows.zip
                STATUS
                status
                LOG
                log
        )
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            message(FATAL_ERROR "error downloading tensorflow lib: ${status_string}" "${log}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_BINARY_DIR}/libtensorflow/windows.zip WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libtensorflow)
        file(REMOVE ${CMAKE_BINARY_DIR}/libtensorflow/windows.zip)
    endif()

    configure_file(${CMAKE_BINARY_DIR}/libtensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/libtensorflow.dll COPYONLY)
    configure_file(${CMAKE_BINARY_DIR}/libtensorflow/lib/tensorflow.dll ${CMAKE_CURRENT_BINARY_DIR}/libtensorflow/test/tensorflow.dll COPYONLY)
endif()
