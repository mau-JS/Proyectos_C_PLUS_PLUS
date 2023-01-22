#include <iostream>
#include <string>

using namespace std;
void palindromo(const string &cadena) {
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
   if(longitud - 1 >= indice){
      cout <<"The longest common subsecuence " << indice << " y termina en el indice "<< (indice + longitud - 1);
      
   }
   else{
      cout << "No existe palindromo en el texto.";
   }

   
}
int main()
{
    string s = "forgeeksskeegfor";
    palindromo(s);
    return 0;
}