//Obtener la mínima cantidad de monedas requeridas para dar cambio con denominaciones de 1,5,10
#include <iostream>
#include <vector>
using namespace std;





int main(){
    int cantidad;
    int monedas = 0;
    cin >> cantidad;

    while(cantidad > 0){

        if ((cantidad - 10) >= 0){
            cantidad -= 10;
            monedas++;
            continue;
        }

        if ((cantidad - 5) > 0){
                cantidad -= 5;
                monedas++;
                continue;
        }
        
        else{
            if((cantidad - 1) >= 0){
                cantidad -= 1;
                monedas++;
            }
        }
    }

    cout << monedas;

    return 0;
}