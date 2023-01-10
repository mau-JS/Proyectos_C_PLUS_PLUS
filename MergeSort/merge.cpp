//Primero realizamos merge, al recibir 2 listas.
#include <iostream>
#include <vector>
using namespace std;
void merge(const vector <int> &a,const vector <int> &b){
    // i -> recorrido de lista a
    //j -> recorrido de lista b
    //k -> recorrido de lista resultante c
    vector <int> c;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < a.size() && j < b.size()){

         if (a[i] < b[j]){
        c.push_back(a[i]);
        i++;

    }

    else{
        c.push_back(b[j]);
        j++;

    }
    }

    
    //Aquí agregamos los datos restantes de la lista a
    if(i < a.size()){
        while(i<a.size()){
            c.push_back(a[i]);
            i++;
        }
    }
    //Aquí agregamos los datos restantes de la lista b
    if(j < b.size()){
        while(j<b.size()){
            c.push_back(b[j]);
            j++;
        }
    }

    for(int dato_c : c){
        cout << dato_c << endl;
    }
}
int main(){
    //Iniciamos con 2 listas diferentes ordenadas
    vector <int> a = {4,8,9,12,45,123};
    vector <int> b = {1,23,45,34};
    merge(a,b);
    return 0;
}