add_executable(google_test test.cpp)
target_link_libraries(google_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(google_test)