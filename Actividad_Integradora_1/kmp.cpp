#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> lps(const string &subcadena){
    vector<int> LPS(subcadena.size(),0);
    LPS[0] = 0;
    int longitud = 0;
    int i = 1;
    int m = subcadena.size();
    while(i < m){
        if (subcadena[i] == subcadena[longitud]){
            longitud++;
            LPS[i] = longitud;
            i++;
        }
        else if (longitud != 0){
            longitud = LPS[longitud -1];
        }
        else if (longitud == 0){
            LPS[i]= 0;
            i = i + 1;
        }
    }
    return LPS;
}
void kmp(const string &subcadena, const string &cadena){
    int i = 0;
    int j = 0;
    int n = cadena.length();
    int m = subcadena.length();
    while (i < n){
        if (subcadena[j] == cadena[i]){
            i++;
            j++;
        }
        if (j == m){
            cout <<"True, starts at position "<<i - j << endl;
            j = lps(subcadena)[j - 1];
            return;
        }
        else if ( i<n && subcadena[j] != cadena[i]){
            if (j > 0) {
                j = lps(subcadena)[j - 1];
            }
            else{
                i++;
            }
        }
    }
    cout << "False";
}
int main(){
    string subcadena = "ababd";
    string cadena = "ababcabcabababd";
    vector <int> vec;
    vec = lps(subcadena);
    kmp(subcadena,cadena);
    return 0;
}