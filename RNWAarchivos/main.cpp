#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main() {

    /*
    Ejemplo 1 Basico:

    - Como crear un archivo de formato txt, Escribir en el y leer su contenido
    
    */ 


    //Inicializar la entrada de texto
    string entradaTexto;
    string linea;

        cout << "Ingresa el texto" << endl;
        getline(cin, entradaTexto);


    //1. Crear un objeto MiArchivo  
    fstream MiArchivo;

    /*2. Abrir el archivo 
    
        2.1 Llamar Al objeto Miarchivo
        2.2 Utilizar el metodo "open"
            2.2.1 open: dependiendo del modo creara y abrira un archivo
            en lectura, sobreescritura y escritura
        */
    MiArchivo.open("Archivo1.txt", ios::out); /// ios::out especifica que el modo salida

    /*3. Comprobar que se abrio correctamente el archivo
    */

    if (MiArchivo.is_open())
    {
        MiArchivo << entradaTexto << endl;
        //Cerrar Archivo
        MiArchivo.close();

    }

    //Lectura
    
    //Abre el Archivo en modo Lectura o input
    MiArchivo.open("Archivo1.txt",ios::in);


    //Comprueba que el archivo esta abierto
    if (MiArchivo.is_open()){

        cout <<  "El contenido del archivo es: \n";
        //Lee el cada linea dentro del archivo ya que no se sabe cuantas lineas tendra el archivo no se usa for
        while (getline(MiArchivo, linea)) { // Obtener cada linea del archivo en linea 
            cout << linea << endl;
        }
        //Cierra el archivo
        MiArchivo.close();
    }

    return 0;
} 