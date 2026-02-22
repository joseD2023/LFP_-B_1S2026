
#ifndef PRACTICA_UNICA_NOTA_H
#define PRACTICA_UNICA_NOTA_H

#include <iostream>
#include "string"
using namespace std;

struct Notas {
    int carnet;
    int codigoCurso;
    double nota; // 0 - 100
    string ciclo; // 1S - 2S
    int anio; // año en que se cursó número entero
};


#endif //PRACTICA_UNICA_NOTA_H