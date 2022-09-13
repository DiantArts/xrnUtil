# A fuzz test runs until it finds an error. This particular one is going to rely on libFuzzer.

# =========================================================================
# setup executable
# =========================================================================

set(XRN_FUZZ_BIN xrnFuzzTests)
file(GLOB_RECURSE XRN_SOURCES *.cpp *.cxx)
add_executable(${XRN_FUZZ_BIN} ${XRN_SOURCES})

# idk yet
target_compile_options(${XRN_FUZZ_BIN} PRIVATE -fsanitize=fuzzer,undefined,address)

# Allow short runs during automated testing to see if something new breaks (Default of 10 seconds)
set(FUZZ_RUNTIME 10 CACHE STRING "Number of seconds to run fuzz tests during ctest run")



# =========================================================================
# link dependencies
# =========================================================================

target_link_libraries(
    ${XRN_FUZZ_BIN}
    PRIVATE
        ${XRN_BIN_NAME}_project_options
        ${XRN_BIN_NAME}_project_warnings
        # ${Boost_LIBRARIES}
        fmt::fmt
        # Qt5::Widgets
        # Qt5::Core
        -coverage
        -fsanitize=fuzzer,undefined,address
)

add_test(NAME fuzz_tester_run COMMAND ${XRN_FUZZ_BIN} -max_total_time=${FUZZ_RUNTIME})
