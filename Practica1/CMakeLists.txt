cmake_minimum_required(VERSION 4.1)
project(Practica_Unica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica_Unica main.cpp
        include/estudiante.h
        include/validaciones.h
        include/generadorReportes.h
        include/lectorArchivos.h
        validaciones.cpp
        include/curso.h
        include/nota.h
        lectorArchivos.cpp
        generadorReportes.cpp)
