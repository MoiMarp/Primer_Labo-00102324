#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Lee todos los enteros de un archivo y los guarda en nums.
bool leerArchivo(const string &filename, vector<int> &nums) {
    nums.clear();
    ifstream in(filename);
    if (!in.is_open()) return false;
    int x;
    while (in >> x) nums.push_back(x);
    in.close();
    return true;
}

// Clasifica los numeros en pares e impares y los guarda en dos archivos distintos.
void clasificarNumeros(const vector<int> &nums, const string &paresFile, const string &imparesFile) {
    ofstream pares(paresFile);
    ofstream impares(imparesFile);

    for (int n : nums) {
        if (n % 2 == 0) pares << n << endl;
        else impares << n << endl;
    }

    pares.close();
    impares.close();
}

//Muestra en pantalla el contenido de un archivo (una linea por numero).
void mostrarArchivo(const string &filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "No se pudo abrir " << filename << " (posible que no exista)." << endl;
        return;
    }
    cout << "Contenido de " << filename << ":" << endl;
    int x;
    bool hay = false;
    while (in >> x) {
        cout << x << " ";
        hay = true;
    }
    if (!hay) cout << "(vacío)";
    cout << endl << "------------------------" << endl;
    in.close();
}


//sobrescribe el archivo con los numeros ordenados y muestra despues.
void ordenarArchivo(const string &filename) {
    vector<int> nums;
    if (!leerArchivo(filename, nums)) {
        cout << "No se pudo leer " << filename << " (archivo no encontrado)." << endl;
        return;
    }

    cout << "--- Antes de ordenar ---" << endl;
    if (nums.empty()) {
        cout << filename << " esta vacio." << endl;
    } else {
        for (int v : nums) cout << v << " ";
        cout << endl;
    }

    int n = (int)nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    //Escribe de vuelta al archivo
    ofstream out(filename);
    for (int v : nums) out << v << endl;
    out.close();

    cout << "--- Despues de ordenar ---" << endl;
    if (nums.empty()) cout << filename << " esta vacio." << endl;
    else {
        for (int v : nums) cout << v << " ";
        cout << endl;
    }
    cout << "========================" << endl;
}

int main() {
    const string datosFile = "datos.txt";
    const string paresFile = "pares.txt";
    const string imparesFile = "impares.txt";

    //Leer datos.txt
    vector<int> datos;
    if (!leerArchivo(datosFile, datos)) {
        cout << "No se pudo abrir " << datosFile << ". Crea el archivo con varios enteros, uno por linea." << endl;
        return 1;
    }

    //Clasifica los pares e impares en archivos distintos
    clasificarNumeros(datos, paresFile, imparesFile);
    cout << "Clasificacion completada. Archivos generados: " << paresFile << ", " << imparesFile << endl << endl;

    //Muestra contenido antes de ordenar 
    mostrarArchivo(paresFile);
    mostrarArchivo(imparesFile);

    //Ordena cada archivo antes y después
    ordenarArchivo(paresFile);
    ordenarArchivo(imparesFile);

    //Muestra resultados finales
    cout << "Resultados finales:" << endl;
    mostrarArchivo(paresFile);
    mostrarArchivo(imparesFile);

    return 0;
}
