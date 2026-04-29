#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream MiArchivo3("nombres.txt"); //Declarar objeto en modo solo lectura

    string nombres[9];  //Arreglo definido al conocer el numero de nombres
    string linea;       //Variable temporal para guardar el nombres y pasarlo al arreglo
    int contador = 0;   //Contador para leer Hasta nueve lineas

    if (MiArchivo3.is_open()) {

        //Mientras sea lea las lineas del archivo y el contador sea menor a 9
        while (getline(MiArchivo3, linea) && contador < 9) { 
            nombres[contador] = linea; //Contador asigna el nombre a un indice del arreglo
            contador++; //Incremento
        }

        MiArchivo3.close(); //Cierra el archivo

        cout << "---\n";
        for (int i = 0; i < 9; i++) {
            cout << nombres[i] << endl;
        }

    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return 0;
}