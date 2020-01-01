add_executable(print_no_trailing_space print_no_trailing_space.cc 
    src/getline.cc 
    src/printline.cc
    src/remove_trailing_space.cc)

target_include_directories(print_no_trailing_space PRIVATE
                           include/
                           )
