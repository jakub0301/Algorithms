#include <iostream>
#include <vector>

using namespace std;

string ciag;

int main(){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<long long> stos;
    
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ciag;
        int koniec = stos.size() - 1;//ost element
        long long wynik = 0;
        if(ciag == "+"){
            wynik = stos[koniec - 1] + stos[koniec];
            stos.pop_back();
            stos.pop_back();
            stos.push_back(wynik);
        }
        else if(ciag == "-"){
            wynik = stos[koniec - 1] - stos[koniec];
            stos.pop_back();
            stos.pop_back();
            stos.push_back(wynik);
        }
        else if(ciag == "*"){
            wynik = stos[koniec - 1] * stos[koniec];
            stos.pop_back();
            stos.pop_back();
            stos.push_back(wynik);
        }
        else if(ciag == "/"){
            wynik = stos[koniec - 1] / stos[koniec];
            stos.pop_back();
            stos.pop_back();
            stos.push_back(wynik);
        }
        else{
            long long wartosc = 0;
            for(int i = 0; i < ciag.size(); i++){
                wartosc = wartosc * 10 + ciag[i] - '0';
            }
            stos.push_back(wartosc);
            
        }
    }
    cout << stos[stos.size() - 1];
    return 0;
}

