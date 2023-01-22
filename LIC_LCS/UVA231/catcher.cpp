#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int resuelve(vector<int> &secuencia){
    //Inicializando vector con caso base
    vector <int> LIS(secuencia.size(),1);
    //Este for obtiene el LIS de cada valor de la secuencia
    for(int i = secuencia.size()-2; i >= 0; i--){
        //Este for compara cada LIS individual con los ya calculados previos
        for(int j = i + 1; j <secuencia.size(); j++){
            if (secuencia[i] <= secuencia[j]){
                LIS[i] = max(LIS[i],1 + LIS[j]);
            }
        }
    }
    //Obtenemos la cantidad máxima de misiles posibles a detener.
    return *max_element(LIS.begin(), LIS.end());
}
int main(){
    vector <int> secuencia;
    int altura;
    int conteo = 0;
    while(cin >> altura, altura != -1){
        secuencia.clear();
        secuencia.push_back(altura);
           while(cin >> altura, altura != -1){
            secuencia.push_back(altura);
        }
        if (conteo == 0){
            cout << "";
        }
        else{
            cout << endl;
        }
    
    //Invirtiendo el orden para encontra la secuencia creciente más larga para saber cuanto es la cantidad máxima de misiles
    reverse(secuencia.begin(),secuencia.end());
    conteo++;
    cout <<"Test #"<<conteo<<":"<<endl;
    cout <<"  maximum possible interceptions: "<< resuelve(secuencia)<<endl;
    
    //Iniciando desde la derecha
    }
          
     
    return 0;
}