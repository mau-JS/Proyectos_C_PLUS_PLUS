#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Requerimos obtener el "longest proper prefix" para poder aplicar el algoritmo
vector <int> lps(const string &subcadena){
    vector<int> LPS(subcadena.size(),0);
    //El primer elemento def LPS siempre es cero ya que un palíndromo no puede ser de un solo caracter
    LPS[0] = 0;
    int longitud = 0;
    int i = 1;
    int m = subcadena.size();
    while(i < m){
        //Agregamos un valor a nuestra i por cada caracter de cadena que sea igual
        if (subcadena[i] == subcadena[longitud]){
            longitud++;
            LPS[i] = longitud;
            i++;
        }
        
        else if (longitud != 0){
            longitud = LPS[longitud -1];
        }
        //Caso para cuando no haya palíndromos
        else if (longitud == 0){
            LPS[i]= 0;
            i = i + 1;
        }
    }
    return LPS;
}
void kmp(const string &subcadena, const string &cadena,ofstream &MyFile){
    int i = 0;
    int j = 0;
    int n = cadena.length();
    int m = subcadena.length();
    while (i < n){
        //Sí son iguales los caracteres hacemos i+1, j+1
        if (subcadena[j] == cadena[i]){
            i++;
            j++;
        }
        //Al terminar el recorrido de la subcadena, podemos identificar sí se encontró de la cadena.
        if (j == m){
            MyFile << "True, starts at position "<<i - j<<endl;

            j = lps(subcadena)[j - 1];
            return;
        }
        // En caso de no ser iguales los caracteres, nos apoyamos de nuestro vector lps para saber a donde mover nuestro indice j.
        else if ( i<n && subcadena[j] != cadena[i]){
            if (j > 0) {
                j = lps(subcadena)[j - 1];
            }
            //Caso j = 0 y no coincide un caracter.
            else{
                i++;
            }
        }
    }
     MyFile << "False"<<endl;
}
