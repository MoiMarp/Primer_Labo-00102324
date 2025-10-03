#include <iostream>

using namespace std;

int main(){

    int edad = 25;


    //Si la persona esta en el rango de edad de 5-10

    if (edad >= 5 && edad <= 14)
    {
        //si esta en el rango de 5 a 14 años entonces mostrara el siguiente mensaje
        cout << "El precio de su boleto es de $12.99" <<endl;
    }
    
    else if (edad >= 15 && edad <= 26)
    {
        //si esta en el rango de 15 a 26 años entonces mostrara el siguiente mensaje
        cout << "El precio de su boleto es de $15.99" <<endl;
    }

    else
    {
        //si no esta en el rango de 5 a 26 años entonces mostrara el siguiente mensaje
        cout << "El precio de su boleto es de $22.99" <<endl;
    }
    
    return 0;

}