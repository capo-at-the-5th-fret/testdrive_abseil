add_library(testdrive_abseil INTERFACE)
add_library(testdrive_abseil::testdrive_abseil ALIAS testdrive_abseil)

target_sources(testdrive_abseil
    INTERFACE
        FILE_SET HEADERS
        FILES
            testdrive_abseil.h
)

target_compile_features(testdrive_abseil INTERFACE cxx_std_23)
