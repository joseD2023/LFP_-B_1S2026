
#ifndef PRACTICA_UNICA_CURSO_H
#define PRACTICA_UNICA_CURSO_H

#include <iostream>
#include "string"
using namespace std;


/*
 * Cada Archivo va a tener lexemas diferentes y para eso debemos usar tokens diferentes para
 * cada archivo no categoria porque ya conocemos dicha categoria
 */

struct Cursos {
    string codigo; //numero entero
    string nombre;
    string creditos; //numero entero de 1-8
    string semestre; // 1-10
    string carrera; //carrera que pertenece el curso
};


#endif //PRACTICA_UNICA_CURSO_H