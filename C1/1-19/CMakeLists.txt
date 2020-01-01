add_executable(print_reverse print_reverse.cc src/getline.cc src/printline.cc src/reverseline.cc)

target_include_directories(print_reverse PRIVATE
                           include/
                           )
