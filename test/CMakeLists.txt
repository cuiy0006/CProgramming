# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test_all 
                test_all.cpp 
                ../C2/2-3/htoi.cc
                ../C2/2-4/squeeze.cc
                ../C2/2-5/any.cc
                ../C2/2-6/setbits.cc
                ../C2/2-7/invert.cc
                ../C2/2-8/rightrot.cc
                ../C2/2-9/bitcount.cc
                ../C2/2-10/lower.cc)
target_link_libraries(test_all gtest_main)
add_test(NAME test_all COMMAND test_all)