cmake_minimum_required(VERSION 4.3)
project(CLI_contact_manager C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra -pedantic)

add_executable(main
        main.c
        contact_manager.c)
