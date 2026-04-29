#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Estructura para almacenar datos
struct Estudiante {
    string nombre;
    float nota;
};

int main() {
    vector<Estudiante> estudiantes;
    int n;

    cout << "Cuantos estudiantes desea ingresar?: ";
    cin >> n;
    cin.ignore();  // limpiar buffer

    // Ingreso de datos por consola
    for (int i = 0; i < n; i++) {
        Estudiante e;

        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Ingrese el nombre: ";
        getline(cin, e.nombre);

        cout << "Ingrese la nota: ";
        cin >> e.nota;
        cin.ignore();

        estudiantes.push_back(e);
    }

    // Crear y abrir el archivo en modo escritura
    ofstream archivo("estudiantes.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < estudiantes.size(); i++) {
            archivo << estudiantes[i].nombre << " "
                    << estudiantes[i].nota << endl;
        }

        archivo.close();
        cout << "\nDatos guardados en el archivo correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return 0;
}
