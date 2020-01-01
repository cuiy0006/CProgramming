add_executable(print_len_lt_80 print_len_lt_80.cc src/getline.cc src/printline.cc)

target_include_directories(print_len_lt_80 PRIVATE
                           include/
                           )
