/*Para cada carrera muestra: nombre de la carrera, cantidad total de estudiantes,
promedio general de la carrera, cantidad de cursos disponibles y distribución de
estudiantes por semestre. */


/*Lo que tenemos que entender es que es la cantidad total de estudiantes que pertenecen
 * a esa carrera (Sistemas, Civil, Industrial...)
 * Como saber: estudiantes tiene notas - la nota codigo curso - curso a una carrera asociada
 *
 * Promedio General de la Carrera: Es el promedio General de toda la carrera es decir todos los estudiantes
 * que por lo menos llevan un curso de sistemas ese se ira sumando y al final haremos un promedio por la carrera
 * y sus propios cursos. Digamos sistema tiene 10 notas y el promedio seria sumar las 10 notas y dividirlo entre 10
 *
 * La cantidad de Cursos Disponibles: son la cantidad de Cursos por carrera digamso Sistemas tiene 4 cursos esos son
 * los cursos disponibles para esa carrera..
 *
 * Cantidad de Estudiantes por Semestre: digamos para sistemas el 1S tuvieron 3 estudiantes por todos sus cursos
 * 2S tuvieron 23 estudiante en sistemas y asi sucesivamente con las demas carreras
 */

#include <iostream>
#include "string"
#include "vector"
#include "fstream"
#include "../include/nota.h"
#include "../include/estudiante.h"
#include "cmath"
#include "../include/curso.h"

struct Carreras {
    int carnet;
    string carrera;
    int semestre;
};


void generarReportesAnalisisCarrera(vector<Estudiante>listaE, vector<Notas> listaN, vector<Cursos> listaC) {
    vector<Carreras> listaCarreras;
    Carreras c;

    if (listaE.empty() || listaN.empty() || listaC.empty()){cout << "Alguna de las lista esta vacia"; return; }
    ofstream html("ReportesAnalisisCarrera.html");
    if (html.is_open()){cout << "Error al Crear el archivo html "; return; }

    /*Recorrer todos los cursos y compararlos con que estudiantes se encuentran en ellos*/

    for (int i=0; i<listaC.size(); i++) {
        vector<int> carnetEstudiantes;
        for (int j=0; j<listaE.size(); j++) {
            if (listaC.at(i).carrera == listaE.at(j).carrera) {
                c.carnet = listaE.at(j).carnet;
                c.carrera = listaE.at(j).carrera;
                c.semestre = listaE.at(j).semestre;
                listaCarreras.push_back(c);
            }
        }








    }


}