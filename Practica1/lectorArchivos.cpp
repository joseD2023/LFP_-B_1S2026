/*Aquí debemos hacer la logica del sistema para el funcionamiento
 * del sistema de la lectura de Datos
 */


#include "include/lectorArchivos.h" //importamos nuestra cabecera para hacer funcionar nuestro archivo

#include <algorithm>

#include "include/validaciones.h" //importamos las validaciones como parte de la semantica del compilador
#include "include/curso.h"
#include "include/estudiante.h"
#include <iostream>
#include "string"
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

void imprimirPantalla(vector<Estudiante> lista) {
    for (int i=0; i < lista.size(); i++) {
        cout << "Carnet:" << lista[i].carnet << endl ;
        cout << "Nombre: " <<  lista[i].nombre <<  endl;
        cout << "Apellido: " <<  lista[i].apellido <<  endl;
        cout << "Carrera: " <<  lista[i].carrera << endl;
        cout <<  "Semestre: " <<  lista[i].semestre <<  endl;
        cout << "-----------------------------------------------" << endl;
    }
}


/*La logica es esta vamos a leer caracter por caracter si cumple con las condiciones de pertenecer
 * a una letra del alfabeto entonces si al finalizar eso quiere decir que es un string si encuentra un
 * número dentro del string eso quiere decir que es una cadena inválida
 */

bool esStringLexico(string s) {
    if (s.empty()){return false;}
    for (char c : s) {
        if (!isalpha(c) && c != ' ') { //si es diferente a una letra y diferente a un espacio retornamos false
            return false;}
    }
    return true;
}

bool esIntLexico(string s) {
    if (s.empty()){return false; }
    for (char d : s ) {
        if (!isdigit(d) && d != ' '){return false;}
    }
    return true;
}


/*ahora mismo lo que hicimos fue convalidar las cadenas para que el analisis lexico lo pueda identificar y pueda funcionar
 * nuestra estructura
 * Analisis INT,STRING,STRING,STRING,INT
 */

void cargarEstudiante(string nombreArchivo1) {

    Estudiante datoEstudiantil;
    //Declaramos un vector de struct
    vector <Estudiante> listaEstudiantes; //creamos un vector de solo estructura de Estudiante


    ifstream archivo(nombreArchivo1); //pasamos el archivo de cursos
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de Cursos " << endl;
        return;
    }

    string carnet, nombre, apellido, carrera, semestre;
    cout << "\n Lista de Cursos de los Alumnos " << endl;
    cout << "--------------------------------------" << endl;

    while (getline(archivo, carnet, ',')) {

        getline(archivo, nombre, ',' );
        getline(archivo, apellido, ',');
        getline(archivo, carrera, ',');
        getline(archivo, semestre);

        /*Observacion para que funcione nuestro compilador el analizador lexico deberia de separar correctamente
         * carnet, nombre, apellido, carrera, semestre si el orden no viniera de esa forma entonces
         * automaticamente el programa deberia de rechazarlo
         */

        if (!esIntLexico(carnet) || !esStringLexico(nombre) || !esStringLexico(apellido) || !esStringLexico(carrera) || !esIntLexico(semestre)) {
            cout << "Error Lexico la Estructura del archivo" << endl;
        }

        //Orden sintactico ya esta impuesto por como viene el archivo

        if (!archivo.fail()) {
            /*si todo cumple y no falla entonces podemos guardarlo en nuestra structura pero esto es la
            * carga mas no la validaciones entonces debemos validar que todo venga correctamente.
            * Para eso hacemos las validaciones
            */

            //Condicion Semantico

            if (validacionCarnet(carnet)  && nombreValido(nombre)  && apellidoValido(apellido) && carreraValidaUsac(carrera) && esSemestreValido(semestre)) {
                datoEstudiantil.carnet = carnet;
                datoEstudiantil.nombre = nombre;
                datoEstudiantil.apellido = apellido;
                datoEstudiantil.semestre = semestre;
                datoEstudiantil.carrera = carrera;
                listaEstudiantes.push_back(datoEstudiantil);
                cout << "Estudiante Agregados Exitosamente... " <<  endl;
                cout << endl;
                }
            }
    }

    //ahora para mostrar lo que cargamos
    imprimirPantalla(listaEstudiantes);
}









void cargarCursos(string nombreArchivo2) {

    ifstream archivo(nombreArchivo2); //aqui vamos a cargar archivo de los cursos

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de Estudiantes " <<  endl;
        return;
    }

    //necesitamos importar las validaciones de los tokens de estudiantes
    //entonces declaramos dichos tokens para que convaliden la estructura
    string codigoCurso;
    string nombreCurso;
    string creditosCurso;
    string semestre;
    string carrera;



}
