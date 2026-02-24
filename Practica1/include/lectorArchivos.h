/*
 * aqui vamos a declarar el funcionamiento de la lectura de los archivo txt.
 * y asi no perdernos para saber en que parte del codigo se encuentran
 *
 */

#ifndef PRACTICA_UNICA_LECTORARCHIVOS_H
#define PRACTICA_UNICA_LECTORARCHIVOS_H
#include <iostream>
#include "string"
#include "estudiante.h"
#include "curso.h"
#include "nota.h"
#include "vector"
using namespace std;

/*Declaracion del Funcionamiento de leer archivos*/

vector<Estudiante> cargarEstudiante(string nombreArchivo1, vector <Estudiante> listaEstudiantes);
vector<Cursos> cargarCursos(string nombreArchivo2, vector<Cursos> listaCursos);
vector <Notas> cargarNotas(string nombreArchivo3, vector <Notas> listaNotas);

void imprimirPantalla(vector<Estudiante> lista);
void imprimirPantalla(vector<Cursos> lista);
void imprimirPantalla(vector<Notas> lista) ;

#endif //PRACTICA_UNICA_LECTORARCHIVOS_H