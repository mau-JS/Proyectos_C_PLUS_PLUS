/*Nombre: Mauricio Juárez Sánchez
Matrícula: A01660336

Análisis y diseño de algoritmos avanzados
Problema A de "Divide and Conquer"
*/
//Complejidad de algoritmo: O(log(n)) -> A cada iteración, se reduce progresivamente el rango de búsqueda hasta cumplir una condición base
//Input -> 6 enteros en una sola línea -> p,q,r,s,t,u
// X -> Puede tomar cualquier valor entre 0 <= x <= 1+

//librerías requeridas
#include <cmath> 
#include <iostream>
#include <iomanip> //Librería utilizada para utilizar precision y fixed en la impresión.

//constante para utilizar exponencial
const double CONSTANTE_EULER = std::exp(1.0);

using namespace std;
//Esta función evalua los valores de p,q,rs,t,u dados por el usuario en la ecuación original.
double eval(double x, double p, double q, double r, double s, double t, double u){
    return p*pow(CONSTANTE_EULER, -x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
}


//Aplicamos búsqueda binaria mediante recursión.
void binarySearch(double p, double q, double r, double s, double t, double u, double low, double high){
    //Obtenemos el valor medio para subsecuentemente comparar y evaluar
    double mid = (low + high) / 2;

    //Verificamos si el valor medio evaluado corresponde a la raíz, este es nuestro caso base para la recursión aplicada.
    if(abs(eval(mid,p,q,r,s,t,u)) < 0.0000001){
        //Imprimimos el resultado con formato solicitado
            cout << fixed <<setprecision(4)<<mid<<endl;
            return;
        }
    //Evaluamos sí existe la raíz en los intervalos ingresados
    if(eval(low,p,q,r,s,t,u) * eval(mid,p,q,r,s,t,u) <= 0){
        //De cumplirse la condición, se reduce el rango de búsqueda
        binarySearch(p,q,r,s,t,u,low,mid);
    }
    else{
        /*De no cumplirse, se recorre en sentido contrario a la dirección previa ya que el valor de raíz ya no esta presente en el recorrido previo*/
        binarySearch(p,q,r,s,t,u,mid,high);
    }

}
int main(int argc, char *argv[])
{
    double p,q,r,s,t,u;
    //Leemos continuamente valores hasta que se termine el input del programa.
    while(cin >> p >> q >> r >> s >> t >> u){
        //Verificamos sí inicialmente existe o no una raíz en el intervalo,de no existir, se despliega un mensaje.
        if(eval(0,p,q,r,s,t,u) * eval(1,p,q,r,s,t,u) > 0){
        cout << "No solution"<<endl;
        }

        else{
            //De existir una solución llamamos a la función de búsqueda
        binarySearch(p,q,r,s,t,u,0,1);
        }
    }
    return 0;
}