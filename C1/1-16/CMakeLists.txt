add_executable(print_len_and_text print_len_and_text.cc src/getline.cc src/printline.cc)

target_include_directories(print_len_and_text PRIVATE
                           include/
                           )
