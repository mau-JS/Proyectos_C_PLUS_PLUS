//Entradas
//Número de casos (pruebas distintas a realizar)
//Línea en blanco
//Cantidad de trabajos
//Tiempo y costo de cada trabajo

//Salidas -> Casos separados deberán separarse con una línea en blanco.
//Secuencia de trabajos con penalización mínima.

//Penalización por día -> Calculada como penalización/día.
//Priorizamos mínima penalización.

//Nombre: Mauricio Juárez Sánchez
//Matrícula: A01660336

//Complejidad O(n^2)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//Función encargada del algoritmo completo.
void resuelveProblema(int numero_trabajos,vector <pair <int, int>> par,vector <double> ratio, vector<double>::iterator it,vector <int> resultado){

    //En este for, leemos cada uno de los datos de tiempo y costo por trabajo acorde a cada caso.

  for (int i = 0; i < numero_trabajos; i++){
        int tiempoT;
        int costoT;
        cin >> tiempoT >> costoT;
        par.push_back(make_pair(tiempoT, costoT));//Vector que guarda los pares de tiempo y costo por trabajo
    }
    //Guardamos el ratio de pago/día para compararlos y tomar decisiones acorde a ello.
    for (int i = 0; i < numero_trabajos; i++){
        ratio.push_back((double)par[i].second/par[i].first);
    }


    //Realiza un ciclo mientras exista un valor en el par 
    while(par.size() > 0){
         //Con esta función obtenemos el máximo de un vector;
    double max = *max_element(ratio.begin(), ratio.end());
    //Obteniendo el iterador que indica donde se encuentra el ratio máximo
    it = std::find(ratio.begin(),ratio.end(),max);
    //Guardando la posición en un índice
    int indice = it - ratio.begin();
    //Guardando la posición en un vector resultado
    resultado.push_back(indice + 1);
    //Inicializando el indice en cero para que no intervenga en demás operaciones.
    ratio[indice] = 0;
    //Borrando los valores ya agregados a resultados para evitar redundancia.
    par.erase(par.begin() + indice);
    }
        //Imprimiendo resultado por caso
    for(int i = 0; i<resultado.size();i++){
        cout << resultado[i];
        if(i < resultado.size() - 1){
            cout << " ";
        }
    }



   

}


int main(){
    int casos; //Entero

    //Leyendo la cantidad de casos.
    cin >> casos;

    for(int i = 0; i < casos ; i++){

     int numero_trabajos;//Es por cada caso
    vector <pair <int, int>> par; //Es por cada caso
    vector <double> ratio; //Es por cada caso
    vector<double>::iterator it; //es por cada caso
    vector <int> resultado;//Es por cada caso
    cin >> numero_trabajos; //Leyendo cantidad de trabajos por caso
    //Aplicando la funcion que resuelve el problema.
    resuelveProblema(numero_trabajos,par,ratio,it,resultado);
     if (i < casos - 1){
        //Imprimiendo saltos de línea para mantener formato solicitado.
        cout << endl;
        cout << endl;
    } 

    }

    cout << endl;




    return 0;
}