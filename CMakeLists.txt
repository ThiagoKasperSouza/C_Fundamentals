project(C_Fundamentals C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Fundamentals main.c
        src/imc.c)

target_link_libraries(C_Fundamentals PRIVATE m)