/*Vamos a trabajar con la Logica de las validaciones segun nuestro
 * struct y lo que realmente dependamos
 */

#include "include/validaciones.h"
#include "string"
#include "algorithm"
#include "cctype"
#include <iostream>
#include "vector"
#include "fstream"
using namespace std;


/*Vamos a trabajar en las validaciones de los Cursos vamos hacer una funcion que leea un archivo con los cursos
 * y los compare con los que vienen para validar
 */

vector<string> lectorCursosArchivo(string nombreArchivo) {
    vector<string> cursos;
    string linea;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){return cursos;} /*una lista vacia*/

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            cursos.push_back(linea);
        }
    }
    archivo.close();
    return cursos;
}


/*Validaciones Semantica del archivo estudiante.lfp*/
bool validacionCarnet(string carnet) {
    if (carnet.length() != 9) {
        cout << "   | Error: Carnet Invalido | = " << carnet <<  endl;
        return false;
        cout << "Error longitud Carnet " << endl;
    } //como es diferente a la cantidad del numero autorizado del carnet no es valido
    return true;
}


bool nombreValido(string nombre) {
    if (nombre.length() > 3){return true;}
    cout << "   | Error: Nombre Invalido | =  " << nombre <<  endl;
    return false;
}

bool apellidoValido(string apellido) {
    if (apellido.length() > 3){return true;}
    cout << "   | Error: Apellido Invalido | = " << apellido <<  endl;
    return false;;
}


bool carreraValidaUsac(string carrera) {
    //vamos a transformar la palabra para que admita sin importar si es mayusculas o minuscula

    vector<string> carrerasValida = lectorCursosArchivo("../data/carreras.lfp");
    bool encontradoCarrera = false;

    if (carrera.empty()) {return false; } //si viene una respuesta falsa de un nombre valido va a regresa que la carrera no es valida

    for (int i=0; i < carrerasValida.size(); i++) {
        string carreraBusqueda = carrera;
        string carreraArchivo = carrerasValida.at(i);
        transform(carreraBusqueda.begin(), carreraBusqueda.end(), carreraBusqueda.begin(), ::tolower);
        transform(carreraArchivo.begin(), carreraArchivo.end(), carreraArchivo.begin(), ::tolower);

        if (carreraArchivo == carreraBusqueda){encontradoCarrera = true; }
    }

    if (encontradoCarrera) {return true; }
    cout << endl;
    cout << "   | Error: Carrera Invalida | =  " << carrera <<  endl;
    return false;
}




bool esSemestreValido(string semestre) {
    /*La validacion del semestre es que sea un numero mayo a 0 y no pase del 10 ya que solo existe 5 años para una ingenieria
     * bueno eso va a depender mucho verdad, pero como estandar
     */
    int noSemestre = stoi(semestre); //convertimos de string a int
    if (noSemestre <= 0 || noSemestre > 10) { cout << "   | Error: Semestre Invalido | =  " << semestre << endl; return false;}
    return true;
}


/*Validaciones Semantica del archivo curso.lfp*/
bool validacionNombreCurso(string nombreCurso) {
    /*ahora en la validacion del nombre del curso debemos validar que el numero del curso osea ya sea
     * base de datos 1 o base de datos 2 pero no debe existir una base de datos 1000
     * asi que vamos a delimitar ese nombre
     */
    string numeracionCurso;

    if (nombreCurso.length() > 4) {
        for (char nc : nombreCurso) {
            if (isdigit(nc)) {
                numeracionCurso += nc; }}

        if (numeracionCurso.empty()) {
            return true; //porque si no consiguio un numero es decir que el nombre esta bien pero no cuenta con numeracion
        }

        if (!numeracionCurso.empty()) {
            int numeroValido = stoi(numeracionCurso);
            if (numeroValido <= 0 || numeroValido > 5) {
                cout << "   | Error: Nombre Curso Invalido | =  " << nombreCurso <<  endl;
                return false;
            }
            return true;
        }

    }
}




bool validacionCodigoCurso(string codigoCurso) {
    if (codigoCurso.length() != 3){ cout << "   | Error: Nombre Curso Invalido | =  " << codigoCurso <<endl;return false; }
    return true;
}

bool validacionCreditos(string creditos) {
    int creditosNum = stoi(creditos);
    if (creditosNum <= 0 || creditosNum >8){cout << "   | Error: Creditos Invalidos | =  " << creditos << endl; return false; }
    return true;
}


/*Validaciones Semantica del archivo notas.lfp*/
bool validacionNota(string nota) {
    double valorNota = stod(nota);
    if (valorNota < 0.0 || valorNota >100.0){return false;}return true;
}

bool validacionCiclo(string ciclo) {
    return (ciclo[0] == '1' || ciclo[0] == '2') && (ciclo[1] == 'S' || ciclo[1] == 's');
}





