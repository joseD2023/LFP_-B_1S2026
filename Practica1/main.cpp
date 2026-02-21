#include <iostream>
#include "string"
#include "include/lectorArchivos.h"
using namespace std;



int main() {
    string nameArch = "../data/estudiantes.lfp";
    cargarEstudiante(nameArch);
    return 0;
}