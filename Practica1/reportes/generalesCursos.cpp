/*aqui vamos a trabajar con los reportes de Estadisticas Generales por curso
* Muestra para cada curso: nombre del curso, cantidad de estudiantes que lo han
cursado, nota promedio, nota máxima, nota mínima, desviación estándar y mediana
de las calificaciones.
 */

#include <iostream>
#include "vector"
#include "string"
#include "../include/curso.h"
#include "../include/nota.h"
#include "cmath"
#include "fstream"
#include <algorithm>
using namespace std;


void generarReporteCursos(vector<Cursos> listaC, vector <Notas> listaN) {
    ofstream html("EstadisticasGeneralesCurso.html");


    if (!html.is_open()){cout << "Error al Crear el Archivo Html."; return; }

    if (listaC.empty() || listaN.empty()) {cout << "No se Encuentran Cursos en la Lista";return;
    }

    html << "<!DOCTYPE html>\n";
    html << "<html lang='es'>\n";
    html << "<head>\n";
    html << "  <meta charset='UTF-8'>\n";
    html << "  <title>Cursos</title>\n";
    html << "</head>\n";
    html << "<body>\n";
    html << "<h1> Estadisticas Generales por Curso </h1>\n";
    html << "<hr>\n";

    /*Nombre del curso y la cantidad de estudiantes necesitamos dos listas*/

    for (int i=0; i<listaC.size(); i++) {
        vector <double> temporal;
       for (auto notas : listaN) {
           if (notas.codigoCurso == listaC[i].codigo) { //validamos si pertenece
               temporal.push_back(notas.nota);
           } /*recopila la informacion de los estudiantes que estan en los cursos para luego guardarlos */
       }

        /*una vez saliendo del recorrido de la primera pasada si queremos decir asi podemmos trabajar con la media moda y cantidad max
         */

        if (temporal.empty()){continue; }

        double suma = 0;
        double notaMax = temporal[0]; //aqui vamos a tener la nota con mas punteo
        double notaMin = temporal[0]; //aqui vamos a tener la nota con menos punteo

        /*cabe resaltar que temporal[0] estamos diciendo que la primera nota es la mas alta y la mas baja hasta
         *que encontremos dentro del siguiente for la nota verdadera que le corresponde */

        for (double note : temporal) {
            suma += note;
            if (note > notaMax) {
                notaMax = note;
            }else if (note < notaMin) {
                notaMin = note;
            }
        }

        /*Promedio*/
        double promedio = suma / temporal.size(); //tenemos el promedio
        double mediana;
        double desviacionEstandar = 0;
        sort(temporal.begin(), temporal.end()); /*Ordenamos antes de encontrar la mediana*/


        /*aqui vamos a calcular la desviacion y la mediana de este reporte
         * la media la vamos a trabajar con datos cuantativos simples
         * cual es la logica de la mediana se se ordena todo los datos de menor a mayor
         * 1. impar: si el numero de datos es impar, la mediana es el valor justo en el medio
         * 2. par: si el numero de datos es par la mediana es el promedio de los dos valores centrales
         */

        if (temporal.size() % 2 != 0) {
            /*si es impar entonces simplemente lo dividimos entre dos la longitud*/
            mediana = temporal[temporal.size()/2]; //conseguimos la posicion y nos va a retornar el numero
        }else {
            //ahora por si es par aquí cambia las cosas
            int posicion1 = temporal.size()/2;
            int posicion2 = temporal.size()/2 - 1;
            mediana = (temporal[posicion1] + temporal[posicion2]) / 2.0;
        }

        /*vamos a calcular la desviacion para ello necesitamos la media o promedio y despues calculamos la varianza sacamos
         * lo que es raiz para la desviacion
         */

        for (int i=0; i<temporal.size(); i++) {
            desviacionEstandar += pow( temporal[i] - promedio, 2); //vamos sumando cada uno de la desviacion y quitandole el promedio y elevando al cuadrado
        }
        desviacionEstandar = sqrt(desviacionEstandar / temporal.size() );

        /*vamos a crear nuestro archivo html para mostrar los datos
         * vamos a escribir contendio en el html
         */
        html << "<table border='1' cellpadding='5' cellspacing='0'>\n";
        html << "<tr><td>Nombre del Curso</td><td>" << listaC.at(i).nombre <<"</td></tr>\n";
        html << "<tr><td>Cantidad de Estudiantes</td><td>" << temporal.size() << "</td></tr>\n";
        html << "<tr><td>Promedio</td><td>" << promedio << "</td></tr>\n";
        html << "<tr><td>Nota Maxima</td><td>" << notaMax << "</td></tr>\n";
        html << "<tr><td>Nota Minima</td><td>" << notaMin << "</td></tr>\n";
        html << "<tr><td>Mediana</td><td>" << mediana << "</td></tr>\n";
        html << "<tr><td>Desviacion Estandar</td><td>" << desviacionEstandar << "</td></tr>\n";
        html << "</table>\n";
        html << "<hr>\n";

    }
    html << "</body>\n";
    html << "</html>\n";
    /*cerramos el archivo del html*/
    html.close();
    cout << "Reporte generado correctamente Estadisticas Generales por Curso ." << endl;
}