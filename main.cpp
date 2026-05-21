#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estudiante {
private:
    string cedula;
    string nombre;
    string apellido;
    double promedio;
    bool aprobado;

public:
    Estudiante() {
        cedula = "";
        nombre = "";
        apellido = "";
        promedio = 0;
        aprobado = false;
    }

    void setCedula(string c) {
        cedula = c;
    }

    void setNombre(string n) {
        nombre = n;
    }

    void setApellido(string a) {
        apellido = a;
    }

    void calcularPromedio(double n1, double n2, double n3) {
        promedio = (n1 + n2 + n3) / 3;
    }

    void determinarAprobacion() {
        aprobado = (promedio >= 7);
    }

    string getCedula() {
        return cedula;
    }

    string getNombre() {
        return nombre;
    }

    string getApellido() {
        return apellido;
    }

    double getPromedio() {
        return promedio;
    }

    bool getAprobado() {
        return aprobado;
    }

    void mostrar() {
        cout << "Cedula: " << cedula << endl;
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Estado: " << (aprobado ? "Aprobado" : "Reprobado") << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    vector<Estudiante> estudiantes;

    int n = 5;
    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < n; i++) {
        Estudiante e;

        string cedula, nombre, apellido;
        double n1, n2, n3;

        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Cedula: ";
        cin >> cedula;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Apellido: ";
        cin >> apellido;

        do {
            cout << "Nota 1 (0-10): ";
            cin >> n1;
        } while (n1 < 0 || n1 > 10);

        do {
            cout << "Nota 2 (0-10): ";
            cin >> n2;
        } while (n2 < 0 || n2 > 10);

        do {
            cout << "Nota 3 (0-10): ";
            cin >> n3;
        } while (n3 < 0 || n3 > 10);

        e.setCedula(cedula);
        e.setNombre(nombre);
        e.setApellido(apellido);

        e.calcularPromedio(n1, n2, n3);
        e.determinarAprobacion();

        if (e.getAprobado()) {
            aprobados++;
        } else {
            reprobados++;
        }

        estudiantes.push_back(e);
    }

    cout << "\nLISTADO DE ESTUDIANTES\n";

    for (int i = 0; i < estudiantes.size(); i++) {
        estudiantes[i].mostrar();
    }

    cout << "\nTotal aprobados: " << aprobados << endl;
    cout << "Total reprobados: " << reprobados << endl;

    return 0;
}
