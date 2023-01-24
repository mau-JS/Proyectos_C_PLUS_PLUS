#include <iostream>
#include <string>
#include <utility>
using namespace std;
pair<int,int> palindromo(const string &cadena) {
   int tamanio_cadena = cadena.size();
   int indice  = 0;
    int longitud = 0;

   for (int i = 1; i < tamanio_cadena; i++) {
       int izquierda = i - 1, derecha = i;
       //s[izquierda] y s[derecha] compara sí es que se sigue cumpliendo la condición de que son palíndromos
       //Caso en el que es par
       while(izquierda >= 0 && derecha < tamanio_cadena && cadena[izquierda] == cadena[derecha]) {
           if(derecha - izquierda + 1 > longitud) {
               indice = izquierda;
               longitud = derecha - izquierda + 1;
           }
           izquierda--;
           derecha++;
       }

       izquierda = i - 1;
       derecha = i + 1;
       
       //Caso en el que es impar
       while(izquierda >= 0 && derecha < tamanio_cadena && cadena[izquierda] == cadena[derecha]) {
           if(derecha - izquierda + 1 > longitud) {
               indice = izquierda;
               longitud = derecha - izquierda + 1;
           }
           izquierda--;
           derecha++;
       }
   }
   pair<int,int> salida {indice , indice + longitud};
   return salida;
}
