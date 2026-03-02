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
#include <list>
#include <map>
#include "algorithm"
#include "string"
#include "vector"
#include "fstream"
#include "../include/nota.h"
#include "../include/estudiante.h"
#include "cmath"
#include "../include/curso.h"


vector<string> lectorCarreras(string nombreArchivo) {
    vector<string> carreras;
    string linea;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){return carreras;} /*una lista vacia*/

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            carreras.push_back(linea);
        }
    }
    archivo.close();
    return carreras;
}


void generarReportesAnalisisCarrera(vector<Estudiante>listaE, vector<Notas> listaN, vector<Cursos> listaC) {

    vector<string> listaCarreras = lectorCarreras("../data/carreras.lfp");
    if (listaCarreras.empty()){cout << "Lista Carrera Vacia"; return;}
    if (listaE.empty() || listaN.empty() || listaC.empty()){cout << "Alguna de las lista esta vacia"; return; }
    ofstream html("ReportesAnalisisCarrera.html");
    if (!html.is_open()){cout << "Error al Crear el archivo html "; return; }
    html << "<!DOCTYPE html>\n";
    html << "<html>\n<head>\n<title>Analisis Carrera</title>\n</head>\n";

    for (int i = 0; i < listaCarreras.size(); i++) {
        vector<int> carnets;

        // Filtrar estudiantes de la carrera (comparación insensible a mayúsculas)
        for (int j = 0; j < listaE.size(); j++) {
            string carreraArchivo = listaCarreras[i];
            string carreraEstudiante = listaE[j].carrera;

            transform(carreraArchivo.begin(), carreraArchivo.end(), carreraArchivo.begin(), ::tolower);
            transform(carreraEstudiante.begin(), carreraEstudiante.end(), carreraEstudiante.begin(), ::tolower);

            if (carreraArchivo == carreraEstudiante) {
                carnets.push_back(listaE[j].carnet);
            }
        }

        /*Ahora vamos con las notas*/
        vector<double> notas;
        for (int k=0; k<carnets.size(); k++) {
            for (int h=0; h<listaN.size(); h++) {
                if (carnets.at(k) ==listaN.at(h).carnet) {
                    notas.push_back(listaN.at(h).nota); }
            }
        }


        /*calcular promedio*/
        /*como dice el enunciado que el promedio de la carrera entonces debemso tomar en cuenta
         * a los estudiantes que estan en la carrera pero llevaron un curso pero no lo cursaron es decir
         * estan asigandos pero lo dejaron
         */

        double suma = 0.0;
        for (int p=0; p<carnets.size(); p++) {
            double sumaNotasEstudiantes = 0.0;
            int contadorNotas =0;
            for (int r=0; r<listaN.size(); r++) {
                if (listaN.at(r).carnet == carnets.at(p)) {
                    sumaNotasEstudiantes += listaN.at(r).nota;
                    contadorNotas++;
                }
            }

            if (contadorNotas > 0) {
                /*promedio de la nota de ese estudiante es decir de un estudiante */
                suma += sumaNotasEstudiantes / contadorNotas;
            }else {
                /*si el estudiante no tiene nota*/
                suma += 0;
            }
        }

        /*Ahora vamos a sacar el promedio General de los estudiantes */

        double promedio = 0.0;

        if (!carnets.empty()) {
            promedio = suma / carnets.size();
        }else {
            promedio = 0.0;
        }



        /*Contar estudiantes por Semestre */
        map<int, int> estudiantePorSemestre;
        for (int c =0; c < carnets.size(); c++) {
            for (int a = 0; a < listaE.size(); a++) {
                if (carnets.at(c) == listaE.at(a).carnet) {
                    estudiantePorSemestre[listaE.at(a).semestre]++;
                    break;
                }
            }
        }

        /*Contar los cursos total de la carrera*/

        int totalCursos = 0;
        for (int total = 0; total < listaC.size() ; total++) {

            string carreraCurso = listaC.at(total).carrera;
            string carreraArchivo = listaCarreras.at(i);

            transform(carreraCurso.begin(), carreraCurso.end(), carreraCurso.begin(), ::tolower);
            transform(carreraArchivo.begin(), carreraArchivo.end(), carreraArchivo.begin(), ::tolower);

            if (carreraCurso== carreraArchivo) {
                totalCursos++; }
        }


        html << "<table border='1' cellpadding='5' cellspacing='0'>\n";

        html << "<tr><th colspan='2'>Reporte Analisis Carrera</th></tr>\n";

        html << "<tr><td><strong>Carrera</strong></td><td>"
             << listaCarreras.at(i) << "</td></tr>\n";

        html << "<tr><td><strong>Total estudiantes</strong></td><td>"
             << carnets.size() << "</td></tr>\n";

        html << "<tr><td><strong>Promedio general</strong></td><td>"
             << promedio << "</td></tr>\n";

        html << "<tr><td><strong>Cursos disponibles</strong></td><td>"
             << totalCursos << "</td></tr>\n";

        html << "<tr><th colspan='2'>Estudiantes por semestre</th></tr>\n";

        for (auto &e : estudiantePorSemestre) {
            html << "<tr><td>Semestre " << e.first << "</td><td>"
                 << e.second << " estudiantes</td></tr>\n";
        }

        html << "</table>\n<hr>\n";
        }

    html << "</body>\n";
    html << "</html>\n";
    html.close();
    cout << "Reporte generado correctamente.\n";
}