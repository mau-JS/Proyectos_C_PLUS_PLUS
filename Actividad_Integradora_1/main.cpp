// =========================================================
// File:
// Author: Mauricio Juárez Sánchez - A01660336
// Date: 20/01/2023
// =========================================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    ifstream mcode1("mcode1.txt");
    ifstream mcode2("mcode2.txt");
    ifstream mcode3("mcode3.txt");
    ifstream transmission1("transmission1.txt");
    ifstream transmission2("transmission2.txt");
    string cadena;
    //cadena mcode1
    string mcode1T= "";
    string mcode2T= "";
    string mcode3T= "";
    string transm1= "";
    string transm2= "";

    if ( mcode1.is_open() ) {     
        while ( mcode1 ) {
            std::getline (mcode1, cadena);
            mcode1T= mcode1T + cadena;            

            }          
        }
        cout << mcode1T;
        cout << endl;

    if ( mcode2.is_open() ) {     
        while ( mcode1 ) {
            std::getline (mcode2, cadena);
            mcode2T= mcode2T + cadena;            
            }          
        }
    
    if ( mcode3.is_open() ) {     
        while ( mcode1 ) {
            std::getline (mcode3, cadena);
            mcode3T= mcode3T + cadena;            
            }          
        }
    


    if ( transmission1.is_open() ) {     
        while ( transmission1 ) {
            std::getline (transmission1, cadena);
            transm1= transm1 + cadena;            
            }          
        }
    


    if ( transmission2.is_open() ) {     
        while ( transmission2 ) {
            std::getline (transmission1, cadena);
            transm2= transm2 + cadena;            
            }          
        }


    return 0;
}