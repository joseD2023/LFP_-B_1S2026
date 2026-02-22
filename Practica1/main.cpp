#include <iostream>
#include "string"
#include "include/lectorArchivos.h"
using namespace std;



int main() {
    string nameArch = "../data/estudiantes.lfp";
    string nameCursos = "../data/cursos.lfp";
    string nameNotas = "../data/notas.lfp";
    //cargarEstudiante(nameArch);
    //cargarCursos(nameCursos);
    cargarNotas(nameNotas);
    return 0;
}