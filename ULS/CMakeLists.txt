cmake_minimum_required(VERSION 3.17)
project(ULS C)

set(CMAKE_C_STANDARD 11)
include_directories(inc)

add_executable(ULS main.c src/base/init_ls.c inc/uls.h src/helpers/print_base.c src/utils/count_in_dir.c src/utils/malloc_array.c src/utils/malloc_request.c)
