find_package(GTest REQUIRED)

add_executable(google_test test.cpp)
target_link_libraries(google_test GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(google_test)