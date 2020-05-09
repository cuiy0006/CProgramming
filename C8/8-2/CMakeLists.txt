ADD_LIBRARY( Regular STATIC
             _fillbuf_regular.cc )

ADD_LIBRARY( Rewrite STATIC
             _fillbuf_rewrite.cc )

add_executable(test_exec_speed_regular test_exec_speed_regular.cc _fillbuf_regular_run.cc)

target_link_libraries(test_exec_speed_regular Regular)

add_executable(test_exec_speed_rewrite test_exec_speed_rewrite.cc _fillbuf_rewrite_run.cc)

target_link_libraries(test_exec_speed_rewrite Rewrite)