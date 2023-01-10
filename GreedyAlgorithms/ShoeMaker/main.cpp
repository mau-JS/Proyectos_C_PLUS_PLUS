//Entradas
//Número de casos (pruebas distintas a realizar)
//Línea en blanco
//Cantidad de trabajos
//Tiempo y costo de cada trabajo

//Salidas -> Casos separados deberán separarse con una línea en blanco.
//Secuencia de trabajos con penalización mínima.

//Penalización por día -> pago/día
//Priorizamos penalización por día penalización/días, luego menor cantidad de días.

//2 7 1 5 3 4 6 8

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void resuelveProblema(int numero_trabajos,vector <pair <int, int>> par,vector <double> ratio, vector<double>::iterator it,vector <int> resultado){

  for (int i = 0; i < numero_trabajos; i++){
        int tiempoT;
        int costoT;
        cin >> tiempoT >> costoT;
        par.push_back(make_pair(tiempoT, costoT));
    }

    for (int i = 0; i < numero_trabajos; i++){
        ratio.push_back((double)par[i].second/par[i].first);
    }



    while(par.size() > 0){
         //Con esta función obtenemos el máximo de un vector;
    double max = *max_element(ratio.begin(), ratio.end());
    //cout << max;
    it = std::find(ratio.begin(),ratio.end(),max);
    int indice = it - ratio.begin();
    resultado.push_back(indice + 1);
    ratio[indice] = 0;
    par.erase(par.begin() + indice);
    }

    for(int i = 0; i<resultado.size();i++){
        cout << resultado[i];
        if(i < resultado.size() - 1){
            cout << " ";
        }
    }



   

}


int main(){
    int casos; //Entero


    cin >> casos;

    for(int i = 0; i < casos ; i++){

     int numero_trabajos;//Es por cada caso
    vector <pair <int, int>> par; //Es por cada caso
    vector <double> ratio; //Es por cada caso
    vector<double>::iterator it; //es por cada caso
    vector <int> resultado;//Es por cada caso
    cin >> numero_trabajos;
    resuelveProblema(numero_trabajos,par,ratio,it,resultado);
     if (i < casos - 1){
        cout << endl;
        cout << endl;
    } 

    }

    cout << endl;




    return 0;
}