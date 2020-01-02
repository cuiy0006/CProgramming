add_executable(detab detab.cc src/getline.cc src/printline.cc)

target_include_directories(detab PRIVATE
                           include/
                           )
