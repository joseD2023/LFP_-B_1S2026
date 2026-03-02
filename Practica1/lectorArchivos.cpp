/*Aquí debemos hacer la logica del sistema para el funcionamiento
 * del sistema de la lectura de Datos
 */


#include "include/lectorArchivos.h" //importamos nuestra cabecera para hacer funcionar nuestro archivo

#include <algorithm>

#include "include/validaciones.h" //importamos las validaciones como parte de la semantica del compilador
#include "include/curso.h"
#include "include/estudiante.h"
#include "include/validacionLexica.h"
#include "include/nota.h"
#include <iostream>
#include "string"
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;


void imprimirPantalla(vector<Estudiante> lista) {
    cout << endl;
    cout << "======================================================" << endl;
    cout << "MOSTRAR ESTUDIANTES                                   " << endl;
    cout << "======================================================" << endl;
    for (int i=0; i < lista.size(); i++) {
        cout << "Carnet:" << lista[i].carnet << endl ;
        cout << "Nombre: " <<  lista[i].nombre <<  endl;
        cout << "Apellido: " <<  lista[i].apellido <<  endl;
        cout << "Carrera: " <<  lista[i].carrera << endl;
        cout <<  "Semestre: " <<  lista[i].semestre <<  endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void imprimirPantalla(vector<Cursos> lista) {
    cout << endl;
    cout << "======================================================" << endl;
    cout << "MOSTRAR CURSOS                                   " << endl;
    cout << "======================================================" << endl;
    for (int i=0; i < lista.size(); i++) {
        cout << "Codigo Curso:" << lista[i].codigo << endl ;
        cout << "Nombre Curso: " <<  lista[i].nombre <<  endl;
        cout << "Creditos Curso: " <<  lista[i].creditos <<  endl;
        cout << "Carrera: " <<  lista[i].carrera << endl;
        cout <<  "Semestre: " <<  lista[i].semestre <<  endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void imprimirPantalla(vector<Notas> lista) {
    cout << endl;
    cout << "======================================================" << endl;
    cout << "MOSTRAR NOTAS                                         " << endl;
    cout << "======================================================" << endl;
    for (int i=0; i < lista.size(); i++) {
        cout << "Carnet Curso:" << lista[i].carnet << endl ;
        cout << "Codigo Curso: " <<  lista[i].codigoCurso <<  endl;
        cout << "Nota Curso: " <<  lista[i].nota <<  endl;
        cout << "Ciclo: " <<  lista[i].ciclo << endl;
        cout <<  "Anio: " <<  lista[i].anio <<  endl;
        cout << "-----------------------------------------------" << endl;
    }
}




/*ahora mismo lo que hicimos fue convalidar las cadenas para que el analisis lexico lo pueda identificar y pueda funcionar
 * nuestra estructura
 * Analisis INT,STRING,STRING,STRING,INT
 */

vector<Estudiante> cargarEstudiante(string nombreArchivo1, vector <Estudiante> listaEstudiantes) {
    Estudiante datoEstudiantil;
    bool sinFallas = false;
    //Declaramos un vector de struct
    //vector <Estudiante> listaEstudiantes; //creamos un vector de solo estructura de Estudiante

    ifstream archivo(nombreArchivo1); //pasamos el archivo de cursos
    if (!archivo.is_open()) {
        cout << " Alerta !. No se pudo abrir el archivo de Cursos " << endl;
        return listaEstudiantes;
    }

    string carnet, nombre, apellido, carrera, semestre;
    cout << "======================================================" << endl;
    cout << "SISTEMA DE CARGA ESTUDIANTES                        " << endl;
    cout << "======================================================" << endl;

    while (getline(archivo, carnet, ',')) {

        getline(archivo, nombre, ',' );
        getline(archivo, apellido, ',');
        getline(archivo, carrera, ',');
        getline(archivo, semestre);

        semestre = eliminarEspacio(semestre); //quitamos obviamente los espacios

        /*Observacion para que funcione nuestro compilador el analizador lexico deberia de separar correctamente
         * carnet, nombre, apellido, carrera, semestre si el orden no viniera de esa forma entonces
         * automaticamente el programa deberia de rechazarlo
         */

        cout << "------------------------------------------------------" << endl;
        cout << "Procesando Estudiante                                 "<<endl;
        cout << "------------------------------------------------------" << endl;

        if (!esIntLexico(carnet)) {cout << "   | Error: Carnet Invalido | =  " << carnet <<endl;}
        if (!esStringLexico(nombre)){cout << "   | Error: Nombre Invalido | = "<< nombre << endl;}
        if (!esStringLexico(apellido)) {cout << "   | Error: Apellido Invalido | = " << apellido <<endl;}
        if (!esStringLexico(carrera)) {cout << "   | Error: Carrera Invalida | =  " << carrera << endl;}
        if (!esIntLexico(semestre)) {cout << "   | Error: Semestre Invalido | =  " << semestre << endl;}

        if (!esIntLexico(carnet) || !esStringLexico(nombre) || !esStringLexico(apellido) || !esStringLexico(carrera) || !esIntLexico(semestre)) {
            sinFallas = true;
            cout << "   [LEXICO] FALLIDO:  "  << carnet << nombre << apellido << carrera << semestre <<  endl;
        }else {
            cout << "   [LEXICO] OK " << endl;
        }


        //Orden sintactico ya está impuesto por como viene el archivo
        if (!sinFallas) {
            //Condicion Semantico
            if (validacionCarnet(carnet)  && nombreValido(nombre)  && apellidoValido(apellido) && carreraValidaUsac(carrera) && esSemestreValido(semestre)) {
                datoEstudiantil.carnet = stoi(carnet); //pasarlo a numero luego
                datoEstudiantil.nombre = nombre;
                datoEstudiantil.apellido = apellido;
                datoEstudiantil.semestre = stoi(semestre);
                datoEstudiantil.carrera = carrera;
                listaEstudiantes.push_back(datoEstudiantil);

                cout << "   [SEMANTICO] OK " << endl;
                cout << ">>> Estudiante agregado Exitosamente  " << endl;
                //return listaEstudiantes;

            }else {
                cout << ">>> Registro Rechazado " << endl;
            }
        }
        sinFallas = false;
    }
    return listaEstudiantes;
}


/*Lo que podemos reutilizar es Carrera Semestre para las validaciones del archivo*/

vector<Cursos> cargarCursos(string nombreArchivo2,  vector<Cursos> listaCursos) {
    //vector<Cursos> listaCursos;
    Cursos cursosUsac;
    bool sinFallas = false;

    ifstream archivo(nombreArchivo2); //aqui vamos a cargar archivo de los cursos

    if (!archivo.is_open()) {
        cout << " Alerta !. No se pudo abrir el archivo de Cursos "  <<  endl;
        return listaCursos; /* sin hay un error se envia una lista vacia*/
    }

    //necesitamos importar las validaciones de los tokens de estudiantes
    //entonces declaramos dichos tokens para que convaliden la estructura
    string codigoCurso,nombreCurso,creditosCurso,semestre,carrera;

    while (getline(archivo, codigoCurso, ',')) {
        getline(archivo, nombreCurso, ',');
        getline(archivo, creditosCurso, ',');
        getline(archivo, semestre, ',');
        getline(archivo, carrera);

        /*vamos a eliminar los espacios que pudieran venir en la ultíma línea*/
        //nombreCurso = eliminarEspacio(nombreCurso);
        carrera = eliminarEspacio(carrera);


        cout << "------------------------------------------------------" << endl;
        cout << "Procesando Cursos                                     "<<endl;
        cout << "------------------------------------------------------" << endl;

        /*Vamos a trabajar con las validaciones del componente Lexico
         * entero - texto - entero - INT - STRING
         */

        if (!esIntLexico(codigoCurso)) {cout << "   | Error: Codigo Curso Invalido | =  " << codigoCurso <<endl;}
        if (!identificadorCurso(nombreCurso)){cout << "   | Error: Nombre Curso Invalido | = "<< nombreCurso << endl;}
        if (!esIntLexico(creditosCurso)) {cout << "   | Error: Cretidos Invalido | = " << creditosCurso <<endl;}
        if (!esStringLexico(carrera)) {cout << "   | Error: Carrera Invalida | =  " << carrera << endl;}
        if (!esIntLexico(semestre)) {cout << "   | Error: Semestre Invalido | =  " << semestre << endl;}


        if (!esIntLexico(codigoCurso) || !identificadorCurso(nombreCurso) || !esIntLexico(creditosCurso) || !esIntLexico(semestre) || !esStringLexico(carrera)) {
            sinFallas = true;
            cout << "   [LEXICO] FALLIDO:  "  << codigoCurso << nombreCurso << creditosCurso << semestre << carrera <<  endl;
        }else {
            cout << "   [LEXICO] OK " << endl;
        }

        if (!sinFallas) {
            if (validacionCodigoCurso(codigoCurso) && validacionNombreCurso(nombreCurso) && validacionCreditos(creditosCurso) && esSemestreValido(semestre) && carreraValidaUsac(carrera)) {
                cursosUsac.codigo = stoi(codigoCurso);
                cursosUsac.nombre = nombreCurso;
                cursosUsac.creditos = stoi(creditosCurso);
                cursosUsac.semestre = stoi(semestre);
                cursosUsac.carrera = carrera;
                listaCursos.push_back(cursosUsac);
                cout << "   [SEMANTICO] OK " << endl;
                cout << ">>> Curso agregado Exitosamente  " << endl;
            }else {
                cout << ">>> Registro Rechazado " << endl;}}

        sinFallas = false;
    }
    return listaCursos;
}



/*Ahora vamso a cargar el archivo de notas.lfp y leerlos correctamente*/
vector <Notas> cargarNotas(string nombreArchivo3, vector <Notas> listaNotas) {
    //vector <Notas> listaNotas;
    Notas n;
    bool sinFallas = false;

    ifstream archivo(nombreArchivo3);

    if (!archivo.is_open()) {
        cout << " Alerta !. No se pudo abrir el archivo de Cursos "  <<  endl;
        return listaNotas;
    }

    string carnet, codigoCurso, nota, ciclo, anio;

    while (getline(archivo, carnet, ',')) {
        getline(archivo, codigoCurso, ','  );
        getline(archivo, nota, ',');
        getline(archivo,ciclo,',');
        getline(archivo, anio);

        /*eliminamos los espacios de la ultíma parte otra vez*/
        anio = eliminarEspacio(anio);

        cout << "------------------------------------------------------" << endl;
        cout << "Procesando Notas                                      "<<endl;
        cout << "------------------------------------------------------" << endl;

        if (!esIntLexico(carnet)) {cout << "   | Error: Carnet Invalido | =  " << carnet <<endl;}
        if(!esIntLexico(codigoCurso)) {cout << "   | Error: Codigo Curso Invalido | =  " << codigoCurso <<endl;}
        if (!esDecimalLexico(nota)){cout << "   | Error: Nota Invalida | =  " << nota <<endl;}
        if (!identificadorCiclo(ciclo)){cout << "   | Error: Ciclo Invalido | =  " << ciclo <<endl;}
        if (!identificadorAnio(anio)){cout << "   | Error: Anio Invalido | =  " << anio <<endl;}

        if (!esIntLexico(carnet) || !esIntLexico(codigoCurso) || !esDecimalLexico(nota) || !identificadorCiclo(ciclo) || !identificadorAnio(anio)) {
            sinFallas = true;
            cout << "   [LEXICO] FALLIDO:  "  << carnet << codigoCurso << nota << ciclo << anio <<  endl;
        }else {
            cout << "   [LEXICO] OK " << endl;
        }

        if (!sinFallas) {
            /*vamos con la semantica para lo de notas */
            if (validacionCarnet(carnet) && validacionCodigoCurso(codigoCurso) && validacionNota(nota) && validacionCiclo(ciclo)) {
                n.carnet = stoi(carnet);
                n.codigoCurso = stoi(codigoCurso);
                n.nota = stod(nota);
                n.ciclo = ciclo;
                n.anio = stoi(anio);
                listaNotas.push_back(n);
                cout << "   [SEMANTICO] OK " << endl;
                cout << ">>> Curso agregado Exitosamente  " << endl;
            }else {
                cout << ">>> Registro Rechazado " << endl;}}
        sinFallas = false;
    }
    return listaNotas;
}





















