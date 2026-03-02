/*Muestra los cursos ordenados por porcentaje de reprobación (de mayor a menor),
indicando: código, nombre del curso, total de estudiantes, cantidad de aprobados,
cantidad de reprobados y porcentaje de reprobación. */

#include <iostream>
#include "string"
#include "vector"
#include "fstream"
#include "../include/nota.h"
#include "../include/curso.h"

struct CursoReprobados {
    Cursos c;
    double media;
    int repro;
    int aproba;
    int cantidad;
};

void generarReportesMasReprobados(vector<Notas> listaN, vector<Cursos> listaC) {
    vector<CursoReprobados> listaCursosReprobados;
    CursoReprobados cr;

    if (listaN.empty() || listaC.empty()){cout << "Alguna de la Lista esta Vacia. "; return;}

    ofstream html("CursosMasReprobados.html");
    if (!html.is_open()){cout << "El archivo Html No se pudo Crear"; return; }


    /*Logica del Reporte: debemo recorrer todos los cursos y tomar las notas de ese curso para luego
     * tener un porcentaje de esos cursos de reprobacion teniendo en cuenta que debemos mostrar tambien
     * la cantidad de estudiantes reprobados y aprobados (codigo curso y nombre curso )
     */


    html << "<!DOCTYPE html>\n";
    html << "<html lang='es'>\n";
    html << "<head>\n";
    html << "  <meta charset='UTF-8'>\n";
    html << "  <title>Cursos</title>\n";
    html << "</head>\n";
    html << "<body>\n";
    html << "<h1> Cursos Mas Reprobados </h1>\n";
    html << "<hr>\n";

    for (int i=0; i<listaC.size(); i++) {
        int aprobados = 0;
        int reprobados =0 ;
        int cantidadEstudiantes = 0;

        for (int j=0; j<listaN.size(); j++) {
            if (listaC.at(i).codigo == listaN.at(j).codigoCurso) {
                if (listaN.at(j).nota >= 61) {
                    aprobados += 1;
                    cantidadEstudiantes += 1;
                }else {
                    reprobados += 1;
                    cantidadEstudiantes += 1;}
            }
        }

        double porcentaje = 0.0;

        if (cantidadEstudiantes > 0 ) {
            porcentaje = (double)reprobados / cantidadEstudiantes * 100; /*Sacamos el porcentaje double*/

            /*Ahora debemos de Guardar esos Datos para luego Ordenarlos*/
            cr.c = listaC.at(i);
            cr.media = porcentaje;
            cr.aproba = aprobados;
            cr.repro = reprobados;
            cr.cantidad = cantidadEstudiantes;
            listaCursosReprobados.push_back(cr);
        }


    }


    /*Usamos el metodo burbuja para ordenar del mayor al menor*/
    for (int t=0; t < listaCursosReprobados.size(); t++) {
        for (int p = 0; p < listaCursosReprobados.size()-t-1; p++) {
            if (listaCursosReprobados.at(p).media < listaCursosReprobados.at(p+1).media) {
                swap(listaCursosReprobados.at(p), listaCursosReprobados.at(p+1));
            }
        }
    }

    /*Vamos a recorrer el Curso para listarlo y mostrar los datos*/

    for (int s=0; s < listaCursosReprobados.size(); s++) {
        if (listaCursosReprobados.at(s).repro > 0 ) {
            html << "<table border='1' cellpadding='5' cellspacing='0' "
                    "style='border-collapse:collapse; margin-bottom:25px;'>\n";
            html << "<tr><th colspan='2'>Curso</th></tr>\n";
            html << "<tr><td>Código del Curso</td><td>" << listaCursosReprobados.at(s).c.codigo << "</td></tr>\n";
            html << "<tr><td>Nombre del Curso</td><td>" << listaCursosReprobados.at(s).c.nombre << "</td></tr>\n";
            html << "<tr><td>Total de Estudiantes</td><td>" << listaCursosReprobados.at(s).cantidad << "</td></tr>\n";
            html << "<tr><td>Cantidad de Aprobados</td><td>" << listaCursosReprobados.at(s).aproba << "</td></tr>\n";
            html << "<tr><td>Cantidad de Reprobados</td><td>" << listaCursosReprobados.at(s).repro << "</td></tr>\n";
            html << "<tr><td>Porcentaje de Reprobación</td><td>" << listaCursosReprobados.at(s).media << "%</td></tr>\n";
            html << "</table>\n<hr>\n";
        }
    }
    html << "</body>\n";
    html << "</html>\n";
    html.close();
    cout << "Generacion HTML Cursos Mas Reprobados Ok " << endl;
}