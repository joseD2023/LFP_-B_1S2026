cmake_minimum_required(VERSION 4.1)
project(Practica_Unica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica_Unica main.cpp
        include/estudiante.h
        include/validaciones.h
        include/lectorArchivos.h
        validaciones.cpp
        include/curso.h
        include/nota.h
        lectorArchivos.cpp
        include/validacionLexica.h
        validacionLexica.cpp
        reportes/generalesCursos.cpp
        include/generalesCursos.h
        reportes/generalesCursos.cpp
        reportes/rendimientoEstudiantes.cpp
        include/rendimientoEstudiantes.h
        reportes/mejoresEstudiantes.cpp
        include/mejoresEstudiantes.h
        reportes/CursosMasReprobacion.cpp
        include/CursosMasReprobacion.h
        reportes/analisisCarrera.cpp
        include/analisisCarrera.h)
