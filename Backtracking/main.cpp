#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int numero_palabras;
    while (cin >> numero_palabras){
    int numero_reglas;
    vector <string> resultados;
    vector <string> palabras;
    vector <string> digitos{"0","1","2","3","4","5","6","7","8","9"};
    for(int n = 0; n < numero_palabras; n++){
    string palabra;
    cin >> palabra;
    palabras.push_back(palabra);
    }
    cin >> numero_reglas;
    for(int m = 0; m < numero_reglas; m++){
    string regla;
    cin >> regla;
    string regla_temp = regla;
        for(int j = 0; j < palabras.size(); j++){
    for(int i = 0; i < digitos.size(); i++){
        for(int k = 0; k < regla_temp.size(); k++){
            if (regla_temp[k] == '#'){
                regla_temp.replace(k,1,palabras[j]);
            }
            if (regla_temp[k] == '0'){
                regla_temp.replace(k,1,digitos[i]);
                
            }
        }
        resultados.push_back(regla_temp);
        regla_temp = regla;
        
    }
    }
    }




    

 
        
    cout <<"--"<<endl;
    for(auto m: resultados){
        cout << m <<endl;
    }
    }




    return 0;
}