#include <iostream>
#include <cstring>

using namespace std;

class Materia {
private:
    int clave;
    char nombre[50];
    char profesor[50];
    char libroTexto[100];
public:
    // Constructor
    Materia(int clave, const char* nombre, const char* profesor, const char* libroTexto)
    {
        this->clave = clave;
        strcpy(this->nombre, nombre);
        strcpy(this->profesor, profesor);
        strcpy(this->libroTexto, libroTexto);
    }

    // Método para imprimir todos los datos de la materia
    void Imprime()
    {
        cout<<"Clave de la Materia: "<< clave <<endl;
        cout<<"Nombre de la Materia: "<< nombre <<endl;
        cout<<"Profesor Titular: "<< profesor <<endl;
        cout<<"Libro de Texto: "<< libroTexto <<endl;
    }

    // Método para cambiar la clave de la materia
    void CambiarClave(int nuevaClave)
    {
        clave = nuevaClave;
    }

    // Método para cambiar el nombre del profesor que imparte la materia
    void CambiarProfesor(const char nuevoProfesor[])
    {
        strcpy(profesor, nuevoProfesor);
    }

};

int main() {
    // Declarar objetos Programación y BasesDatos usando el constructor
    Materia Programacion(101, "Programacion", "Profesor A", "Libro de Programacion");
    Materia BasesDatos(102, "Bases de Datos", "Profesor B", "Libro de Bases de Datos");

    int opc;

    while (true) {
        // Mostrar el menú y obtener la opción del usuario
        cout<<"------------------------[Menu]----------------------------"<<endl;
        cout<<"1. Cambiar clave de la materia Programacion"<<endl;
        cout<<"2. Cambiar nombre del profesor de la materia Bases de Datos"<<endl;
        cout<<"3. Imprimir datos de la materia Bases de Datos"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<< "Seleccione una opcion: "; cin>>opc;

        system("cls");

        switch (opc)
        {
            case 1:
                int nuevaClave;

                cout << "Ingrese la nueva clave de la materia Programacion: "; cin >> nuevaClave;
                Programacion.CambiarClave(nuevaClave);
                break;

            case 2:
                char nuevoProfesor[50];

                cout<<"Ingrese el nuevo nombre del profesor para la materia Bases de Datos: ";
                cin.ignore();
                cin.getline(nuevoProfesor, sizeof(nuevoProfesor));
                BasesDatos.CambiarProfesor(nuevoProfesor);
                break;

            case 3:
                BasesDatos.Imprime();
                break;

            case 4:
                return 0;

            default:
                cout<<"Opcion no valida. Por favor, seleccione una opcion valida."<<endl;
        }
    }

    return 0;
}


