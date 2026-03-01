/*Muestra para cada estudiante: nombre completo, carnet, carrera, semestre actual,
promedio general de todas sus notas, cantidad de cursos aprobados (nota >= 61),
cantidad de cursos reprobados (nota < 61) y créditos acumulados. */

#include <iostream>
#include "string"
#include "vector"
#include "fstream"
#include "../include/nota.h"
#include "../include/estudiante.h"
#include "cmath"
#include "../include/curso.h"


void generarReportesRendimiento(vector<Estudiante>listaE, vector<Notas> listaN, vector<Cursos> listaC)  {
    /*Verificamos que las listas no vengan vacias*/
    if (listaE.empty() || listaN.empty() || listaC.empty()){cout << "Alguna de la Lista esta Vacia. "; return;}

    /*ahora como queremos ver cada estudiante con todas un promedio y la cantidad de cursos aprobados
     * y cantidad de cursos reprobados y los creditos lo unico que se relacion entre la nota y el estudiante es el carnet
     */

    ofstream html("rendimiento.html");
    if (!html.is_open()){cout << "Error al crear archivo html. "; return; }
    html << "<!DOCTYPE html>\n";
    html << "<html>\n<head>\n<title>Rendimiento</title>\n</head>\n";

    for (int i=0; i < listaE.size(); i++) {
        vector<double> notasEstudiantes;
        vector<int> codigosCursos;

        for (auto notas : listaN) {
            if (notas.carnet == listaE.at(i).carnet) {
                notasEstudiantes.push_back(notas.nota);
                codigosCursos.push_back(notas.codigoCurso);
            }
        }

        /*una vez cargadas todas las notas de los estudiantes que le pertenece a su carnet
         * vamos a sacar su promedio
         */

        int cursosAprobados = 0;
        int cursosReprobados = 0;
        double suma = 0.0;
        double promedio = 0.0;
        int creditosAcumulados = 0;

        /*la misma cantidad de notas que tengo, tambien tengo la misma cantidad de codigos de cursos */


        for (int j=0; j<notasEstudiantes.size(); j++) {
            suma += notasEstudiantes.at(j); /*sumo mi primera nota ya se 35 o 65 o 100 pero la sumo*/
            if (notasEstudiantes.at(j) >= 61) { /*si es mayor a 61 aprobo y tiene que contener sus creditos acreditarlos*/
                for (int k=0; k<listaC.size(); k++) { /*recorro toda la lista de mi cursos que tengo*/
                    if (listaC.at(k).codigo == codigosCursos.at(j)) { /*y lo comparo con el primer codigo de la primera nota y si existe en los creditos acumulados
                        le sumo los creditos que me da el curso osea relaciono tanto curso - nota */
                        creditosAcumulados += listaC.at(k).creditos;
                    }
                }
                cursosAprobados += 1; // aprobados cantidad total se suman
            }else {
                cursosReprobados += 1; // reprobados cantidad total se suman
            }
        }

        promedio = suma / notasEstudiantes.size();

        html << "<hr>\n";
        html << "<body>\n";
        html << "<p>Nombre del Estudiante: " << listaE.at(i).nombre <<"</p>\n";
        html << "<p>Carnet: " << listaE.at(i).carnet <<"</p>\n";
        html << "<p>Carrera: " << listaE.at(i).carrera <<"</p>\n";
        html << "<p>Semestre: " << listaE.at(i).semestre <<"</p>\n";
        html << "<p>Promedio General: " << promedio <<"</p>\n";
        html << "<p>Cursos Aprobados: " << cursosAprobados <<"</p>\n";
        html << "<p>Cursos Reprobados:  " << cursosReprobados <<"</p>\n";
        html << "<p>Creditos Acumulados:  " << creditosAcumulados <<"</p>\n";
    }

    html << "</body>\n";
    html << "</html>\n";
    /*cerramos el archivo del html*/
    html.close();
    cout << "Generacion HTML Rendimiento Estudiantes Ok " << endl;

}