//
// Created by josev on 21/02/2026.
//

#ifndef PRACTICA_UNICA_VALIDACIONLEXICA_H
#define PRACTICA_UNICA_VALIDACIONLEXICA_H
#include "string"
#include <iostream>
using namespace std;

/*Validaciones Lexicas Cabeceras
 * Cabecera de Estudiante
 */

string eliminarEspacio(string espacio);
bool esStringLexico(string s);
bool esIntLexico(string digito);


/*
 * Cabecera Cursos
 */

bool identificadorCurso(string curso);

/*
 * Cabecera Notas
 */

bool esDecimalLexico(string decimal);
bool identificadorCiclo(string ciclo);
bool identificadorAnio(string anio);




#endif //PRACTICA_UNICA_VALIDACIONLEXICA_H