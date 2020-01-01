add_executable(f_to_c_function f_to_c_function.cc src/f_to_c.cc)

target_include_directories(f_to_c_function PRIVATE
                           include/
                           )
