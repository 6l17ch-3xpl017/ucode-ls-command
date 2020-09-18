cmake_minimum_required(VERSION 3.16)
project(ULS C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(libmx/inc)

file(GLOB_RECURSE SRC RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "inc/*.h")
file(GLOB_RECURSE LIB RELATIVE ${CMAKE_SOURCE_DIR} "libmx/src/*.c")
file(GLOB_RECURSE LIB_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "libmx/inc/*.h")


#add_executable(ULS main.c src/base/init_ls.c inc/uls.h src/helpers/print_base.c src/utils/count_in_dir.c src/utils/malloc_char_array.c src/utils/malloc_request.c src/helpers/is_dir.c src/helpers/is_file.c src/utils/linear_search.c src/utils/cutter.c src/helpers/check_args.c src/helpers/check_flags.c src/base/init_main.c inc/structures.h inc/includes.h inc/prototypes.h src/base/init_flags.c)
add_executable(ULS main.c ${SRC} ${LIB} ${HEADERS} ${LIB_HEADERS} src/base/init_files.c)
#target_link_libraries(ULS -lacl)