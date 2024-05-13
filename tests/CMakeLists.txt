include(FetchContent)

# Tags: https://github.com/abseil/abseil-cpp
# Linkage: target_link_libraries(absl::library_name)
set(NEEDED_absl_VERSION "20240116.2")

find_package(absl ${NEEDED_absl_VERSION} QUIET)

if (NOT absl_FOUND)

    set(BUILD_TESTING OFF)

    FetchContent_Declare(
        absl
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp
        GIT_TAG        ${NEEDED_absl_VERSION}
        GIT_SHALLOW    TRUE
        #PATCH_COMMAND  git apply "${CMAKE_CURRENT_LIST_DIR}/../../patches/abseil-cpp-${NEEDED_absl_VERSION}.patch"
    )

    FetchContent_MakeAvailable(absl)

endif()

# Tags: https://github.com/doctest/doctest/tags
set(NEEDED_DOCTEST_VERSION "2.4.11")

find_package(doctest ${NEEDED_DOCTEST_VERSION} QUIET)

if (NOT doctest_FOUND)

    FetchContent_Declare(
        doctest
        GIT_REPOSITORY "https://github.com/doctest/doctest"
        GIT_TAG        v${NEEDED_DOCTEST_VERSION}
        GIT_SHALLOW    TRUE
    )

    FetchContent_MakeAvailable(doctest)

    # include the doctest module that contains doctest_discover_tests
    list(APPEND CMAKE_MODULE_PATH ${doctest_SOURCE_DIR}/scripts/cmake)

endif()

# this needs to be called for the doctest_discover_tests function to work
include(doctest)

add_executable(testrunner

    main.cpp

    uniform_tests.cpp

)

target_link_libraries(testrunner
    PRIVATE
        doctest::doctest
        absl::random_distributions
        testdrive_abseil::testdrive_abseil
)

doctest_discover_tests(testrunner)
