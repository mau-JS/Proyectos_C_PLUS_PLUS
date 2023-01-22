//Nombre: Mauricio Juárez Sánchez
//Matrícula:A01660336
//Complejidad del algoritmo: O(nm) -> donde n corresponde al ciclo for dentro de la función cálculo
//y m corresponde al número de casos.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int calculo(int n, vector<int> &resultado,vector<int> &primer,vector<int> &segundo,vector<int> &tercero){
        //Este caso es para cuando el usuario decide ingresar cero como entrada.
    if(n == 0){
        return 1;
    }
    //Con esta condición verificamos sí ya ha sido calculado previamente un valor. En caso de existir, al usuario se le despliega 
    //el cálculo previo.
    if(resultado[n] != -1){
        return resultado[n];
    }
    //De no existir el cálculo, aplicamos el bottom -up approach donde evaluamos cada una de las operaciones aplicadas y 
    //almacenamos los resultados
    else{
    //Este for aplica el bottom up approach por iteración.
    for(int i = 1; i <= n; i++){

        if(primer[i] == -1){
            primer[i] = (int) (i - sqrt(i));
        }
        if(segundo[i] == -1){
            segundo[i] = (int)(log(i));
        }
        if(tercero[i] == -1){
            tercero[i] = (int)(i * pow(sin(i),2));
        }
        //Finalmente, ocupamos los valores calculados para obtener el resultado final
        resultado[i] = (resultado[primer[i]] + resultado[segundo[i]] + resultado[tercero[i]])% 1000000;
    }
    //Devolvemos el resultado final al usuario
    return resultado[n];
    }




}

int main(){
    //Inicializamos todos los vectores en -1 con un espacio definido, el espacio se reserva para poder aplicar el algoritmo 
    //con las restricciones dadas por el problema.
    vector <int> resultado(1000000, -1);
    vector <int> primer(1000000,-1);
    vector <int> segundo(1000000,-1);
    vector <int> tercero(1000000,-1);
    int valor;
    //Caso base
    resultado[0] = 1;
    //Lectura de los datos ingresados por el usuario. Sí se ingresa -1, el programa termina su ejecución.
    while(true){
        cin >> valor;
        if(valor == -1){
            break;
        }
        else{
            cout << calculo(valor, resultado,primer,segundo,tercero) <<endl;
        }
    }
    return 0;
}