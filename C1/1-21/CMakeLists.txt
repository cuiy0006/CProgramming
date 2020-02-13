add_executable(entab entab.cc src/getline.cc src/printline.cc)

target_include_directories(entab PRIVATE
                           include/
                           )
