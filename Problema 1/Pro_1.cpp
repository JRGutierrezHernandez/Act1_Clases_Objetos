#include <iostream>
#include <cstring>

using namespace std;

class Empleado {

private:
    int claveEmpleado;
    char nombre[50];
    char domicilio[100];
    float sueldo;
    char reportaA[50];

public:
    // Constructor
    Empleado(int claveEmpleado, const char* nombre, const char* domicilio, float sueldo, const char* reportaA) {
        this->claveEmpleado = claveEmpleado;
        strcpy(this->nombre, nombre);
        strcpy(this->domicilio, domicilio);
        this->sueldo = sueldo;
        strcpy(this->reportaA, reportaA);
    }

    // Método para imprimir los datos del empleado
    void Imprime() {
        cout<<"Clave del Empleado: "<< claveEmpleado <<endl;
        cout<<"Nombre: "<< nombre <<endl;
        cout<<"Domicilio: "<< domicilio <<endl;
        cout<<"Sueldo: "<< sueldo <<endl;
        cout<<"Reporta a: "<< reportaA <<endl;
    }

    // Método para cambiar el domicilio del empleado
    void CambiaDomic(char nuevoDomicilio[])
    {
        strcpy(domicilio, nuevoDomicilio);
    }

    // Método para cambiar la persona a quien reporta el empleado
    void CambiaReportaA(char nuevaPersona[])
    {
        strcpy(reportaA, nuevaPersona);
    }

    // Método para actualizar el sueldo del empleado
    void ActualSueldo(float porcentajeIncremento)
    {
        sueldo += sueldo * (porcentajeIncremento / 100.0);
    }


};

int main(){
    // Declarar objetos JefePlanta y JefePersonal
    Empleado JefePlanta(1, "Jefe de Planta", "Calle A, Ciudad A", 50000.0, "");
    Empleado JefePersonal(2, "Jefe de Personal", "Calle B, Ciudad B", 55000.0, "");

    int opc;

    while(true){
        // Mostrar el menú y obtener la opción del usuario
        cout<<"------------------[Menu]------------------------------"<<endl;
        cout<<"1. Cambiar domicilio de un empleado"<<endl;
        cout<<"2. Actualizar sueldo de un empleado"<<endl;
        cout<<"3. Imprimir datos de un empleado"<<endl;
        cout<<"4. Cambiar la persona a quien reporta un empleado"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Seleccione una opcion: "; cin>>opc;
        cout<<"------------------------------------------------------"<<endl;
        system("cls");

        switch(opc){
            case 1:
                int claveDomicilio;
                char nuevoDomicilio[100];

                cout<<"Ingrese la clave del empleado: "; cin>>claveDomicilio;

                if(claveDomicilio == 1)
                {
                    cout << "Ingrese el nuevo domicilio: "; cin.ignore();
                    cin.getline(nuevoDomicilio, sizeof(nuevoDomicilio));
                    JefePlanta.CambiaDomic(nuevoDomicilio);
                }
                else if(claveDomicilio == 2)
                {
                    cout << "Ingrese el nuevo domicilio: ";
                    cin.ignore();
                    cin.getline(nuevoDomicilio, sizeof(nuevoDomicilio));
                    JefePersonal.CambiaDomic(nuevoDomicilio);
                }
                else
                {
                    cout<<"Clave de empleado no valida."<<endl;
                }

                system("pause");
                system("cls");

                break;

            case 2:
                int claveSueldo;
                float porcentajeIncremento;

                cout<<"Ingrese la clave del empleado: "; cin >> claveSueldo;

                if (claveSueldo == 1)
                {
                    cout << "Ingrese el porcentaje de incremento del sueldo: ";
                    cin >> porcentajeIncremento;
                    JefePlanta.ActualSueldo(porcentajeIncremento);
                }
                else if (claveSueldo == 2)
                {
                    cout << "Ingrese el porcentaje de incremento del sueldo: ";
                    cin >> porcentajeIncremento;
                    JefePersonal.ActualSueldo(porcentajeIncremento);
                }
                else
                {
                    cout << "Clave de empleado no valida." << endl;
                }

                system("pause");
                system("cls");
                break;

            case 3:
                int claveImprimir;

                cout<<"Ingrese la clave del empleado: ";cin>> claveImprimir;
                system("cls");

                if (claveImprimir == 1)
                {
                    JefePlanta.Imprime();
                }
                else if (claveImprimir == 2)
                {
                    JefePersonal.Imprime();
                }
                else
                {
                    cout<<"Clave de empleado no valida."<<endl;
                }

                system("pause");
                system("cls");
                break;

            case 4:
                int claveReportaA;
                char nuevaPersona[50];

                cout<<"Ingrese la clave del empleado: "; cin >> claveReportaA;

                cout<<"Ingrese el nombre de la nueva persona a quien reporta: ";
                cin.ignore();
                cin.getline(nuevaPersona, sizeof(nuevaPersona));

                if (claveReportaA == 1)
                {
                    JefePlanta.CambiaReportaA(nuevaPersona);
                }
                else if (claveReportaA == 2)
                {
                    JefePersonal.CambiaReportaA(nuevaPersona);
                }
                else
                {
                    cout<<"Clave de empleado no valida."<< endl;
                }

                system("pause");
                system("cls");
                break;

            case 5:
                return 0;

            default:
                cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
        }
    }

    return 0;
}
