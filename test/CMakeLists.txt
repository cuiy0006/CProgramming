# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()


# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test_all 
                test_all.cpp
                ../util/util.cc
                ../C2/2-3/htoi.cc
                ../C2/2-4/squeeze.cc
                ../C2/2-5/any.cc
                ../C2/2-6/setbits.cc
                ../C2/2-7/invert.cc
                ../C2/2-8/rightrot.cc
                ../C2/2-9/bitcount.cc
                ../C2/2-10/lower.cc
                ../C3/3-1/binsearch.cc
                ../C3/3-2/escape.cc
                ../C3/3-3/expand.cc
                ../C3/3-4/itoa.cc
                ../C3/3-5/itob.cc
                ../C3/3-6/itoa_width.cc
                ../C4/4-1/strrindex.cc
                ../C4/4-2/atof.cc
                ../C4/4-12/itoa_recursive.cc
                ../C4/4-13/reverse_recursive.cc
                ../C5/5-3/strcat_p.cc
                ../C5/5-4/strend.cc
                ../C5/5-5/str_op.cc
                ../C5/5-6/atoi_p.cc
                ../C5/5-6/itoa_p.cc
                ../C5/5-6/reverse_p.cc
                ../C5/5-6/itob_p.cc
                ../C5/5-6/itoa_width_p.cc
                ../C5/5-6/strindex_p.cc)
target_include_directories(test_all PUBLIC
                           ../util/
                           )
target_link_libraries(test_all gtest_main)
add_test(NAME test_all COMMAND test_all)