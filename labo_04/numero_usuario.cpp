#include <iostream>

using namespace std;

int main(){

   int num, i = 1;
  
    cout << "Ingrese un numero: ";
    cin >> num;
    cout << " " << num << endl;
  
   do
   {   
    cout << i << endl;
    i++;
   } while (i <= num);

   return 0;
   
}