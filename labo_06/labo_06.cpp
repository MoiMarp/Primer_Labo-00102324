#include <iostream>
#include <string>

using namespace std;

struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

// Función para ingresar los estudiantes

int ingresarEstudiantes(Estudiante *est, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nESTUDIANTE " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, est[i].nombre);

        cout << "Edad: ";
        cin >> est[i].edad;
        cin.ignore();

        cout << "Ingrese las 5 calificaciones:\n";
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> est[i].calificaciones[j];
        }
        cin.ignore();

        cout << "Calle: ";
        getline(cin, est[i].direccion.calle);

        cout << "Numero: ";
        cin >> est[i].direccion.numero;
        cin.ignore();

        cout << "Ciudad: ";
        getline(cin, est[i].direccion.ciudad);
    }
    return 0;
}

// Función para mostrar los estudiantes

int mostrarEstudiantes(Estudiante *est, int n) {
    cout << "\nLISTA DE ESTUDIANTES\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: " << est[i].nombre << endl;
        cout << "Edad: " << est[i].edad << endl;
        cout << "Direccion: " << est[i].direccion.calle << " #"
             << est[i].direccion.numero << ", " << est[i].direccion.ciudad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << est[i].calificaciones[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Función para buscar los estudiantes

int buscarEstudiante(Estudiante *est, int n) {
    string nombreBuscado;
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    getline(cin, nombreBuscado);

    for (int i = 0; i < n; i++) {
        if (est[i].nombre == nombreBuscado) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << est[i].nombre << endl;
            cout << "Edad: " << est[i].edad << endl;
            cout << "Direccion: " << est[i].direccion.calle << " #"
                 << est[i].direccion.numero << ", " << est[i].direccion.ciudad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < 5; j++) {
                cout << est[i].calificaciones[j] << " ";
            }
            cout << endl;
            return i;
        }
    }
    cout << "No se encontró el estudiante." << endl;
    return -1;
}

// Función para modificar los estudiantes

int modificarEstudiante(Estudiante *est, int n) {
    string nombreBuscado;
    cout << "\nIngrese el nombre del estudiante a modificar: ";
    getline(cin, nombreBuscado);

    for (int i = 0; i < n; i++) {
        if (est[i].nombre == nombreBuscado) {
            cout << "\nModificando datos de " << est[i].nombre << "...\n";
            cout << "Nuevo nombre: ";
            getline(cin, est[i].nombre);

            cout << "Nueva edad: ";
            cin >> est[i].edad;
            cin.ignore();

            cout << "Ingrese las nuevas calificaciones:\n";
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> est[i].calificaciones[j];
            }
            cin.ignore();

            cout << "Nueva calle: ";
            getline(cin, est[i].direccion.calle);

            cout << "Nuevo numero: ";
            cin >> est[i].direccion.numero;
            cin.ignore();

            cout << "Nueva ciudad: ";
            getline(cin, est[i].direccion.ciudad);

            cout << "Estudiante modificado correctamente.\n";
            return 0;
        }
    }
    cout << "No se encontró el estudiante." << endl;
    return -1;
}

int main() {
    int n, opcion, pos;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    cin.ignore();

    Estudiante *estudiantes = new Estudiante[n];

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Ingresar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Modificar estudiante\n";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            ingresarEstudiantes(estudiantes, n);
        } else if (opcion == 2) {
            mostrarEstudiantes(estudiantes, n);
        } else if (opcion == 3) {
            buscarEstudiante(estudiantes, n);
        } else if (opcion == 4) {
            modificarEstudiante(estudiantes, n);
        }

    } while (opcion != 5);

    delete[] estudiantes;
    return 0;
}
