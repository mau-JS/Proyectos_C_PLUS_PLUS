#include<iostream>
#include <string>
#include <vector>

using namespace std;



int LCS(const string &cadena1, const string &cadena2) 
{
    //Primero, creamos una matriz creada con el tamaño de la cadenas.
    //Los renglones se conforman por la cadena 2, las columnas por la cadena 1

    int matriz [cadena2.length() + 1][cadena1.length() + 1];
      //Recorrido y llenado de matriz
    for (int renglon = 0; renglon <= cadena2.length(); renglon++) {
        for (int columna = 0; columna <= cadena1.length(); columna++) {
          //Renglón y columna auxiliar
          if (renglon == 0 || columna == 0) {
            matriz[renglon][columna] = 0;
          } 
          //Caso donde los caracteres coindicen
          else if (cadena2[renglon - 1] == cadena1[columna - 1]) {
            matriz[renglon][columna] = matriz[renglon - 1][columna - 1] + 1;
          } 
          //Caso donde los caracteres no coinciden y obtenemos el máximo del valor de la cuadrícula superior e izquierda.
          else {
            matriz[renglon][columna] = max(matriz[renglon - 1][columna], matriz[renglon][columna - 1]);
          }
        }
      }
      //El valor final del recorrido vendrá con el tamaño de la secuencia más larga.
      return matriz[cadena2.length()][cadena1.length()];
}
