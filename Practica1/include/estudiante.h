/*
 * Aqui vamos a declarar todo lo que vamos a necesitar
 * en el main solo declaraciones mas no la logica para la estructura de tokens
 */
#ifndef PRACTICA_UNICA_ESTUDIANTE_H
#define PRACTICA_UNICA_ESTUDIANTE_H

#include <iostream>
#include "string"
using namespace std;

/* AQUÍ SERÍA COMO EL ANALISIS LEXICO PORQUE YA TENEMOS EL PATRON DEFINIDO SIMULADAMENTE
 * vamos a usar Struct tipo tokens
 * Recordemos que aquí ya está predefinido el tipo de categoria del tokens no es necesario
 * que el lenguaje lo reconozca asi que es más facil aún para ordenarlos
 */
struct Estudiante {
    string carnet;
    string nombre;
    string apellido;
    string carrera;
    string semestre; // 1-10
};

#endif //PRACTICA_UNICA_ESTUDIANTE_H