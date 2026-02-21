/*Aqui vamos a trabajar con las validaciones de los tokens
 * eso quiere decir que solo vamos a declarar lo que vamos a usar en cada tokens
 *
 *
 */
#ifndef PRACTICA_UNICA_VALIDACIONES_H
#define PRACTICA_UNICA_VALIDACIONES_H
#include <iostream>
using namespace std;



/*Funcionamiento del Tokens del Archivo estudiante.lfp*/

bool validacionCarnet(string carnet);
bool nombreValido(string nombre);
bool apellidoValido(string apellido);
bool carreraValidaUsac(string carrera);
bool esSemestreValido(string semestre);


/*Funcionamiento del Tokens del Archivo curso.lfp*/
bool validacionNombreCurso(string nombreCurso);
bool validacionCodigoCurso(string codigoCurso);
bool validacionCreditos(string creditos);
bool validacionSemestre(string semestre);
bool validacionCarrera(string carrera);


/*Funcionamiento del Tokens del Archivo notas.lfp*/




#endif //PRACTICA_UNICA_VALIDACIONES_H