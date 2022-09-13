macro(set_standard_project_settings interface language_version)
    SET(CMAKE_CXX_STANDARD ${language_version})
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    if (ENABLE_COVERAGE)
        if (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
            target_compile_options(${interface} INTERFACE -O0 -g3 -fprofile-instr-generate -fcoverage-mapping -fPIC --coverage -fno-inline)
        elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            target_compile_options(${interface} INTERFACE -O0 -g3 -fprofile-arcs -ftest-coverage -fPIC --coverage -fno-inline -fno-inline-small-functions -fno-default-inline)
        endif ()
        target_link_libraries(${interface} INTERFACE --coverage)
    endif ()

    if (ENABLE_OUTPUT_DIR)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${XRN_${XRN_BIN_NAME}_OUTPUT_DIR})
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${XRN_${XRN_BIN_NAME}_OUTPUT_DIR})
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${XRN_${XRN_BIN_NAME}_OUTPUT_DIR})
    endif ()

    # Set a default build type if none was specified
    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "Built type set to RelWithDebInfo (default option)")
        set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
        # Set the possible values of build type for cmake
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif ()

    # Generate a compile_commands.json to make it easier to work with clang based tools
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    # Enable IterpPocedural Optimization (LTO: Link Time Optimization) if needed
    if (ENABLE_IPO)
        include(ProcessorCount)
        ProcessorCount(XRN_${XRN_BIN_NAME}_NPROC)
        if (NOT XRN_${XRN_BIN_NAME}_NPROC EQUAL 0)
            set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_JOBS ${XRN_${XRN_BIN_NAME}_NPROC})
        endif ()

        include(CheckIPOSupported)
        check_ipo_supported(RESULT isIpoSupported OUTPUT output)
        if (isIpoSupported)
            message(STATUS "IPO enabled (${XRN_${XRN_BIN_NAME}_NPROC} procs)")
            set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
        else ()
            message(WARNING "IPO is not supported: ${output}")
        endif ()
    endif ()
endmacro()
