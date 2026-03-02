/*aqui vamos a colocar las validaciones Lexica*/

/*La logica es esta vamos a leer caracter por caracter si cumple con las condiciones de pertenecer
 * a una letra del alfabeto entonces si al finalizar eso quiere decir que es un string si encuentra un
 * número dentro del string eso quiere decir que es una cadena inválida
 */

#include "string"
#include <iostream>
using namespace std;

/*Validacion Lexica de los archivos INT-STRING*/

string eliminarEspacio(string espacio) {
    string concatenacion;
    for (char es: espacio) {
        if (es != '\n' && es != '\r' && es != '\t' && es != ' ') {concatenacion += es; }//concatenamos solo los dijistos espacio nel
    }
    return concatenacion;
}


bool esStringLexico(string s) {
    if (s.empty()){return false;}
    for (char c : s) {
        if (!isalpha(c)) { //si es diferente a una letra y diferente a un espacio retornamos false
            return false;}
    }
    return true;
}


bool esIntLexico(string digito) {
    if (digito.empty()){return false; }
    for (char d : digito ) {
        if (!isdigit(d)){return false;}
    }
    return true;
}



/*Lexema para identificar Curso*/
bool identificadorCurso(string curso) {
    string cursoCopia;
    string aux;


    if (curso.empty()){return false;}

    /*Logica Cuando venga el nombre del curso le vamos a quitar los espacios para convalidar mas no decir si existe el curso o no
     * lo unico que vamos a valdiar es que despúes de un número no venga un string ejemplo: programacion 1
     * juntamos todos programacion1 la logica sería que despúes de un número no puede venir una letra porque si viene seria algo
     * malo, pero si puede venir otro número y en el paso de la semantica púes va a verificar si ese número es válido
     */

    /*Vamos a quitar los espacios*/
    for (char j:curso) {
        if (j != '\n' && j != '\r' && j != '\t' && j != ' ') {
            cursoCopia += j; }}


    for (char p:cursoCopia) {
        if (isalpha(p)) {
            if (!aux.empty() && isdigit(aux.back())) { //si esta vacio aux ni lo intenta leer porque
                return false;
            }
            aux += p; //sis
            continue;
        }else if (isdigit(p)) {
                aux += p;
                continue;
        }
    }
    return true;
}


/*ahora vamos a validar las notas que sean numero normal que ya lo tenemso pero tambien pueder ser decimal*/

bool esDecimalLexico(string decimal) {
    if (decimal.empty()){return false;}
    bool punto = false; //si ya punto se vuelve true
    for (char dc : decimal) {
        if (isdigit(dc)){continue;}
        if (dc == '.' && !punto) { //si el punto es true es porque ya antes aparecio uno
            punto = true;
            continue; }
        return false;
    }
    if (decimal == "."){return false;} //porque no puede venir un punto por si solo
    return true;
}


bool identificadorCiclo(string ciclo) {
    /*segun el enunciado el ciclo se representa como 2S o 1S
     * Entonces el analizador lexico debera solo validar la estructura osea que venga un numero y luego una letra
     * y la semantica debera que ese numero sea 1 o 2 y la letra "S"
     */

    if (ciclo.empty() || ciclo.length() != 2){return false; }
    if (!isdigit(ciclo[0]) || !isalpha(ciclo[1])) { /*si viene la estructura s1 malo d1 malo si viene 2h no entra
        al condiconal estructura valida entero + letra */
        return false;
    }
    return true;
}

bool identificadorAnio(string anio) {
    if (anio.empty() || anio.length() != 4){return false; }

    if (esIntLexico(anio)) {
        return true;
    }
    return false;
}








