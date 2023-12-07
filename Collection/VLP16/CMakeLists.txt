cmake_minimum_required(VERSION 3.10)

project(VLP16)

# Add the path to Google Test
find_package(GTest REQUIRED)

# Source files
set(SOURCES
    main/App.cpp
    main/Packet.cpp
    main/Parser.cpp
    main/Point.cpp
    main/Stream.cpp
)

# Header files
set(HEADERS
    main/App.h
    main/Packet.h
    main/Parser.h
    main/Point.h
    main/Stream.h
)


# Create a library from the common source files
add_library(VLP16Library STATIC ${SOURCES} ${HEADERS})

# Create the main executable for your project
add_executable(VLP16Executable main/main.cpp)

# Link the main executable with the library
target_link_libraries(VLP16Executable PRIVATE VLP16Library)

# Create the test executable
add_executable(VLP16Tests tests/test_main.cpp ${TEST_SOURCES})

# Link the test executable with Google Test and the library
target_link_libraries(VLP16Tests PRIVATE VLP16Library GTest::gtest GTest::gtest_main)

# Automatically discover and include all test source files
file(GLOB TEST_SOURCES tests/*.cpp)

# Create a test executable for each test source file
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} PRIVATE VLP16Library GTest::gtest GTest::gtest_main -Dgtest_disable_pthreads=OFF -g3 -O0 -Wall -DDEBUG -fcheck=all -fbacktrace)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# Add the 'main' directory to include directories
target_include_directories(VLP16Library PUBLIC main)


# Optionally, enable testing
enable_testing()

# Add a test for each test executable
add_test(NAME VLP16Tests COMMAND VLP16Tests)