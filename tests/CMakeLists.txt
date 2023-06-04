FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2)
FetchContent_MakeAvailable(catch)

add_executable(testlib tests.cpp test_brick_breaker.hpp)
target_compile_features(testlib PRIVATE cxx_std_17)
target_link_libraries(testlib PRIVATE ${PROJECT_NAME}_lib Catch2::Catch2WithMain)
add_test(NAME testlibtest COMMAND testlib) # Command can be a target
