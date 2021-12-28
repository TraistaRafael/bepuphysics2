include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
    bepuphysics2_tests
    Fix64Tests.cpp
    Vector2Tests.cpp
    Vector3Tests.cpp
    BoundingBoxTests.cpp
)

target_link_libraries(
    bepuphysics2_tests
    bepuphysics2
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(bepuphysics2_tests)