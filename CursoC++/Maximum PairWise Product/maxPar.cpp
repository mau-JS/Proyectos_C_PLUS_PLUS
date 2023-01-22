#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long cantidad;
    long long numero;
    long long mayor1 = 0;
    long long mayor2 = 0;
    long long indice_mayor;
    long long indice_mayor2;
    vector <long long> vect;
    cin >> cantidad;
    for(int i = 0; i < cantidad; i++){
        cin >> numero;
        vect.push_back(numero);
    }
    for(
        int i = 0; i < cantidad; i++){
            if (vect[i] > mayor1){
                mayor1 = vect[i];
                indice_mayor = i;
            }
    }
    vect[indice_mayor] = 0;

    for(
        int i = 0; i < cantidad; i++){
            if (vect[i] > mayor2){
                mayor2 = vect[i];
                indice_mayor2 = i;
            }
    }
    cout << mayor1 * mayor2;
    return 0;
}
