#include <iostream>
#include "string"
#include "include/lectorArchivos.h"
#include "vector"
#include "include/curso.h"
#include "include/nota.h"
#include "include/estudiante.h"
#include "include/generalesCursos.h"
#include "include/rendimientoEstudiantes.h"
#include "include/mejoresEstudiantes.h"
#include "include/CursosMasReprobacion.h"
#include "include/analisisCarrera.h"

using namespace std;



int main() {
    /*almacenamiento para los vectores*/
    vector <Estudiante> listaEstudiantes;
    vector<Cursos> listaCursos;
    vector <Notas> listaNotas;

    int opc;
    while (true) {
        cout << "======================================"<<  endl;
        cout << " SISTEMA DE ANALISIS ACADEMICO     "   <<   endl;
        cout << "=====================================" <<   endl;
        cout << "1. Cargar Archivos Estudiantes                   " << endl;
        cout << "2. Cargar Archivos Cursos                        " << endl;
        cout << "3. Cargar Archivos Notas                         " << endl;
        cout << "4. Generar Reporte: Estadísticas por Curso       " << endl;
        cout << "5. Generar Reporte: Rendimiento por Estudiante   " << endl;
        cout << "6. Generar Reporte: Top 10 Mejores Estudiantes   " << endl;
        cout << "7. Generar Reporte: Cursos con Mayor Reprobacion " << endl;
        cout << "8. Generar Reporte: Analisis por Carrera         " << endl;
        cout << "9. Salir                                         " << endl;
        cout << "Seleccione una opcion:                           " << endl;
        cin >> opc;

        if (cin.fail()) {
            cout << "Ingreso una Opcion Invalida !" << endl;
            cin.clear(); /*limpia el estado error*/
            cin.ignore(1000, '\n'); /*borra lo del buffer*/
            continue;
        }

        if (opc == 1) {
            string nameArch = "../data/estudiantes.lfp";
            listaEstudiantes = cargarEstudiante(nameArch, listaEstudiantes);
            imprimirPantalla(listaEstudiantes);


        }else if (opc == 2) {
            string nameCursos = "../data/cursos.lfp";
            listaCursos = cargarCursos(nameCursos, listaCursos);
            imprimirPantalla(listaCursos);


        }else if (opc == 3) {
            string nameNotas = "../data/notas.lfp";
            listaNotas = cargarNotas(nameNotas, listaNotas);
            imprimirPantalla(listaNotas);
        }else if (opc == 4) {
            generarReporteCursos(listaCursos, listaNotas);
        }else if (opc == 5) {
            generarReportesRendimiento(listaEstudiantes, listaNotas, listaCursos);
        }else if (opc == 6) {
            generarReporteMejoresEstudiantes(listaEstudiantes, listaNotas);
        }else if (opc == 7) {
            generarReportesMasReprobados(listaNotas, listaCursos);
        }else if (opc == 8) {
            generarReportesAnalisisCarrera(listaEstudiantes, listaNotas, listaCursos);
        }else if (opc == 9) {
            cout << "Gracias por Utilizar El Programa Lenguajes Formales De La Rosa" << endl;
            break;
        }
    }


    return 0;
}