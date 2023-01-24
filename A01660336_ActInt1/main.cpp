// =========================================================
// File:
// Author: Mauricio Juárez Sánchez - A01660336
// Date: 22/01/2023
// =========================================================
#include <iostream>
#include <fstream>
#include <string>
#include "palindromo.hpp"
#include "lcs.hpp"
#include "kmp.hpp"

using namespace std;
int main(){

    ifstream mcode1("mcode1.txt");
    ifstream mcode2("mcode2.txt");
    ifstream mcode3("mcode3.txt");
    ifstream transmission1("transmission1.txt");
    ifstream transmission2("transmission2.txt");
    string cadena;

    //Aquí almacenamos nuestras lectura de archivos
    string mcode1T= "";
    string mcode2T= "";
    string mcode3T= "";
    string transm1= "";
    string transm2= "";

    //Lectura de archivos
    if ( mcode1.is_open() ) {     
        while ( mcode1 ) {
            getline (mcode1, cadena);
            mcode1T= mcode1T + cadena;            
            }          
        }


    if ( mcode2.is_open() ) {     
        while ( mcode2 ) {
            getline (mcode2, cadena);
            mcode2T= mcode2T + cadena;            
            }          
        }

    
    if ( mcode3.is_open() ) {     
        while ( mcode3 ) {
            getline (mcode3, cadena);
            mcode3T= mcode3T + cadena;            
            }          
        }


    if ( transmission1.is_open() ) {     
        while ( transmission1 ) {
            getline (transmission1, cadena);
            transm1= transm1 + cadena;            
            }          
        }


    if ( transmission2.is_open() ) {     
        while ( transmission2 ) {
            getline (transmission2, cadena);
            transm2= transm2 + cadena;            
            }          
        }

    
    //Impresión al archivo mysolution.txt
    ofstream MyFile("mysolution.txt");
    MyFile <<"transmission1.txt:"<<endl;
    MyFile<<"mcode1.txt - ";
    kmp(mcode1T,transm1,MyFile);
    MyFile<<"mcode2.txt - ";
    kmp(mcode2T,transm1,MyFile);
    MyFile<<"mcode3.txt - ";
    kmp(mcode3T,transm1,MyFile);
    MyFile << endl;

    MyFile <<"transmission2.txt:"<<endl;
    MyFile<<"mcode1.txt - ";
    kmp(mcode1T,transm2,MyFile);
    MyFile<<"mcode2.txt - ";
    kmp(mcode2T,transm2,MyFile);
    MyFile<<"mcode3.txt - ";
    kmp(mcode3T,transm2,MyFile);
    MyFile << endl;


    MyFile << "Transmission1.txt:" <<endl;

    MyFile <<"Mirrored code found, starts at " <<palindromo(transm1).first<<" and ends at "<< palindromo(transm1).second<<"."<<endl<<endl;

    
    MyFile <<"Transmission2.txt:"<<endl<<"Mirrored code found, starts at " <<palindromo(transm2).first<<" and ends at "<< palindromo(transm2).second<<"."<<endl;

    /* MyFile << "the longest common subsecuence between transmission1.txt and transmission2.txt is "<< LCS(transm1,transm2)<< "characters long"<<endl; */
 


    
    return 0;
}