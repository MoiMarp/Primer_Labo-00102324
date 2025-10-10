#include <iostream>
using namespace std;

int main() {
    
    int num;

    cout << "Ingrese un numero entero: "; 
    cin >>  num;

    cout << "\nTabla de  Multiplicar del " << num <<":\n";
    for (int i=1; i<=10; i++){

        cout << num << " x " << i << " = " << num * i << endl;
    }
    
}