#include<iostream>
#include <string>
#include <vector>
using namespace std;



int LCS(const string &cadena1, const string &cadena2) 
{
    //Primero, creamos una matriz creada con el tamaño de la cadenas.
    //Los renglones se conforman por la cadena 2, las columnas por la cadena 1

    int matriz [cadena2.length() + 1][cadena1.length() + 1];

    for (int renglon = 0; renglon <= cadena2.length(); renglon++) {
        for (int columna = 0; columna <= cadena1.length(); columna++) {

          if (renglon == 0 || columna == 0) {
            matriz[renglon][columna] = 0;
          } 
          else if (cadena2[renglon - 1] == cadena1[columna - 1]) {
            matriz[renglon][columna] = matriz[renglon - 1][columna - 1] + 1;
          } 
          else {
            matriz[renglon][columna] = max(matriz[renglon - 1][columna], matriz[renglon][columna - 1]);
          }
        }
      }
  
      return matriz[cadena2.length()][cadena1.length()];
}


int main(){
    string cadena = "abcde";
    string cadena2 = "ace";
    cout <<"The longest common subsecuence between"<<" is "<<LCS(cadena,cadena2)<<" characters long.";
    return 0;
}