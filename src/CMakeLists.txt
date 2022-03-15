add_library(gsa ba.c)

add_executable(ba_test ba_test.c)
target_link_libraries(ba_test gsa)
add_test(ba_test ba_test)
