/*Vamos a visualizar los mejores estudiantes del los archivos
 */


/*Vamos a hacer el funcionamiento De:
* Lista ordenada de los 10 estudiantes con mejor promedio general, mostrando:
posición, carnet, nombre completo, carrera, semestre y promedio.

-tomar en cuenta la lista de los estudiantes debemos tomar su promedio de cada uno
-la lista de las notas ya que ahi se encuentra sus notas y debemos sumarla y sacar su promedio de cada estudiante
 */

#include <iostream>
#include "vector"
#include "../include/nota.h"
#include "../include/estudiante.h"
#include "fstream"
#include "string"


struct Promedios {
 Estudiante studens;
 double promedio;
};

void generarReporteMejoresEstudiantes(vector<Estudiante> listaE, vector<Notas> listaN) {

 vector<Promedios> listasPromedios;
 Promedios p;

 if (listaE.empty() || listaN.empty()){cout << "Verificar si las listas No esten Vacias!!"; return;}

 /*creamos el archivo html*/
 ofstream html("mejoresEstudiantes.html");
 if (!html.is_open()){cout << "Error al Crear el Archivo Html !"; return;}


 html << "<!DOCTYPE html>\n";
 html << "<html lang='es'>\n";
 html << "<head>\n";
 html << "  <meta charset='UTF-8'>\n";
 html << "  <title>cursos</title>\n";
 html << "</head>\n";
 html << "<body>\n";
 html << "<h1>🏆 Top 10 Mejores Estudiantes</h1>\n";
 html << "<hr>\n";


 /*Comienza la logica del sistema de como vamos a ir obteniendo los mejores*/

 for (int i=0; i < listaE.size(); i++) {
  vector <double> notasEstudiantes;
  for (int j=0; j<listaN.size(); j++) {
   if (listaN.at(j).carnet == listaE.at(i).carnet) {
    notasEstudiantes.push_back(listaN.at(j).nota);
   }
  }
  double promedio = 0.0;
  double suma = 0.0;
  for (int j=0; j < notasEstudiantes.size(); j++) {
   suma += notasEstudiantes.at(j);
  }

  if (!notasEstudiantes.empty()) { /*Esto me ayudara a evitar dividir entre cero */
   promedio = suma / notasEstudiantes.size();
   p.studens = listaE.at(i); //aqui guardamos los datos del estudiante
   p.promedio = promedio;
   listasPromedios.push_back(p); /*Guardamos la informacion del promedio junto al estudiante*/

  }else {promedio = 0.0;}
 }

 /*Ordenamiento de Burbuja */
 for (int l=0; l<listasPromedios.size()-1; l++) {
  for (int h=0; h< listasPromedios.size()-l-1; h++) {
   if (listasPromedios.at(h).promedio < listasPromedios.at(h+1).promedio) {
    swap(listasPromedios.at(h), listasPromedios.at(h+1));
   }
  }
 }


 /*limite para leer los  10 estudiantes*/
 string medallas[] = {"🥇", "🥈", "🥉"};

 int limite = min(10, (int)listasPromedios.size());
 string colcocarMedalla;
 cout << "Top Mejores Estudiantes" << endl;

 for (int t = 0; t < limite ; t++) {
  if (t < 3) {colcocarMedalla = medallas[t];}

  html << "<table border='1' cellpadding='5' cellspacing='0' "
        "style='border-collapse:collapse; margin-bottom:25px;'>\n";
  html << "<tr><th colspan='2'>Reporte Mejores Estudiantes</th></tr>\n";
  html << "<tr><td>Posicion Estudiante: </td><td>" << t + 1 << colcocarMedalla  << "</td></tr>\n";
  html << "<tr><td>Nombre Estudiante: </td><td>" << listasPromedios.at(t).studens.nombre  << "</td></tr>\n";
  html << "<tr><td>Carnet Estudiante: </td><td>"  << listasPromedios.at(t).studens.carnet  << "</td></tr>\n";
  html << "<tr><td>Carrera Estudiante: </td><td>" << listasPromedios.at(t).studens.carrera  << "</td></tr>\n";
  html << "<tr><td>Semestre Estudiante: </td><td>" << listasPromedios.at(t).studens.semestre  << "</td></tr>\n";
  html << "<tr><td>Promedio Estudiante: </td><td>" << listasPromedios.at(t).promedio  << "</td></tr>\n";
  html << "</table>\n<hr>\n";

  colcocarMedalla = " ";
  html << "<hr>\n";
 }
 html << "</body>\n";
 html << "</html>\n";
 html.close();
 cout << "Generacion HTML Mejores Estudiantes Ok " << endl;

}