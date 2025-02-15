cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(GameOfLifeLib STATIC
    src/library/GameOfLife.cpp
)

target_include_directories(GameOfLifeLib PUBLIC src/library)

add_executable(GameOfLife src/main.cpp)

target_link_libraries(GameOfLife PRIVATE GameOfLifeLib)

project(TestDemoVersion)

add_library(TestDemoVersionLib STATIC
    src/library/GameOfLife.cpp
)

target_include_directories(TestDemoVersionLib PUBLIC src/library)

add_executable(TestDemoVersion Tests/testDemoVersion.cpp)

target_link_libraries(TestDemoVersion PRIVATE TestDemoVersionLib)

project(Tes1)

include(FetchContent)
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(gtest)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

configure_file(${CMAKE_SOURCE_DIR}/Tests/Test1.txt ${CMAKE_BINARY_DIR}/Debug/Test1.txt COPYONLY)

add_executable(Test1 
    Tests/tests.cpp

    src/library/GameOfLife.cpp
)

target_include_directories(Test1 PUBLIC src/library)

target_link_libraries(Test1
    gtest 
)

enable_testing()
add_test(NAME Test1 COMMAND Test)
