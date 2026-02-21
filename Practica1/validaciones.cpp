/*Vamos a trabajar con la Logica de las validaciones segun nuestro
 * struct y lo que realmente dependamos
 */

#include "include/validaciones.h"
#include "string"
#include <iostream>
using namespace std;

bool validacionCarnet(string carnet) {
    if (carnet.length() != 9) {
        return false;
    } //como es diferente a la cantidad del numero autorizado del carnet no es valido

    //ahora vamos a comprobar que el caracter solo contenga digitos dentro de su extension
    for(char digito: carnet ) {
        if (!isdigit(digito)) { //si en la cadena existe por lo menos una letra entonces no es valido el carnet
            return false;
        }
    }
    return true;
}


bool nombreValido(string nombre) {
    /*Vamos a trabajar con la validacion del Nombre podemos verificar que si tiene
     * un dígito que no pertenezca al alfabeto entonces mandamos error para el funcionamiento
     */
    string noSimbolos = " @_-/<>+=#$%&/().,"; //no acepta estos caracteres en el nombre
    if (nombre.empty()) {
        return false;
    }
    for (char n : nombre) {
        for (int i=0; i<noSimbolos.length(); i++) {
            if (n == noSimbolos[i] || isdigit(n)) {
                return false;
            }
        }
    }
    return true;
}

bool apellidoValido(string apellido) {

    string noSimbolos = "@_-/<>+=#$%&/().,";
    if (apellido.empty()) {
        return false;
    }
    for (char a : apellido) {
        for (int i=0; i<noSimbolos.length(); i++) {
            if (a == noSimbolos[i] || isdigit(a)) {
                return false;
            }
        }
    }
    return true;
}


bool carreraValidaUsac(string carrera) {
    string carrerasValidas[] = {"Sistemas","Industrial", "Civil", "Ambiental", "Quimica"};
    bool encontradoCarrera = false;

    /*Tenemos un problema sobre usar mayusculas o minisiculas entonces carreras admitidas seria tipo
     * que al inicio tenga Mayusculas
     */
    if (carrera.empty() || !nombreValido(carrera)) {return false; } //si viene una respuesta falsa de un nombre valido va a regresa que la carrera no es valida
    for (string c : carrerasValidas) {
        if (c == carrera) {encontradoCarrera = true;}
    }
    if (encontradoCarrera) {return true; }
    return false;
}




bool esSemestreValido(string semestre) {
    /*La validacion del semestre es que sea un numero mayo a 0 y no pase del 10 ya que solo existe 5 años para una ingenieria
     * bueno eso va a depender mucho verdad, pero como estandar
     */
    if (semestre.empty()){return false;} //viene vacio el texto o lo que sea
    //vamos a verificar que sea un digito y no una letra
    for (char d : semestre) {
        if (!isdigit(d)) {
            return false;
        }
    }
    int noSemestre = stoi(semestre); //convertimos de string a int
    if (noSemestre <= 0 || noSemestre > 10) {
        return false;
    }
    return true;
}


/*Ahora vamos con la validaciones de los curso para su funcionamiento es decir la parte semantica*/

bool validacionNombreCurso(string nombreCurso) {


}

bool validacionCodigoCurso(string codigoCurso) {

}

bool validacionCreditos(string creditos) {

}

bool validacionSemestre(string semestre) {

}

bool validacionCarrera(string carrera) {

}



